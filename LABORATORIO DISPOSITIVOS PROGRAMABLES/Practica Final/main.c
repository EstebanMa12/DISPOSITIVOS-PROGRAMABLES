/* ========================================
 *
 * Copyright Jonathan Gallego, 2022
 * All Rights Reserved
 *
 * ========================================
*/
#include "project.h"
#include <string.h> // Para el manejo de strings
#include <stdio.h>  //Para el manejo de sprintf
#include <stdlib.h> // Para la conversión de string a entero

/**************************************
******         Funciones           ****
***************************************/
/****Función para iniciar módulos******/
void InitAllModules(void);

/****Funciones del manejo de la hora***/
void AsignarHoraNueva(const char *Hora); //Recibe la hora en formato string y la asigna al RTC
void AsignarFechaNueva(const char *Fecha); //Recibe la fecha en formato string y la asigna al RTC
void mostrarTiempo (void); //Función para mostrar tiempo en LCD
void mostrarFecha (void); //Funcion para mostrar fecha en LCD

/***Funciones para la captura y visualización de ADC***/
void getADCvalue(void); //Función para obtener los valores crudos de ADC usando el Mux
void calculateADCprom(void); //Función para calcular el promedio de ADC

/***Función para mostrar datos en el LCD*****/
void LCD_Update_P(void); //Función para mostrar en el LCD todo lo que se desea mostrar
void LCD_Update_T(void);

/****Funciones para manejo del serial*****/
uint8 isDataReady(void);  //Función que verifica si ya llegó un mensaje completo, incluído el '\n'
void analyseData(void);  //Función que analiza que tipo de dato se recibió y realiza alguna acción dependiendo del dato
void sendADCData(void);  //Función para enviar los dos valores de ADC separados por ,


/**************************************
******  Variables Globales   **********
***************************************/

/*****Variables del RTC*****/
uint8 Segundos=0; //Variable para identificar cambio de segundos
RTC_TIME_DATE Start; //Variable que contiene hora inicial.
char Hora[]={"13:29:17"};
char Fecha[]={"23/04/1986"};
char Angulo[]={"000"};

/****Variables para comunicación Serial****/
char buffer[40]; // buffer que contiene todo lo enviado desde el serial hasta que se recibe un '\n'
char str[6]; //buffer que se utiliza para convertir ADC en string
char DatatoSend[40]; //Dato enviado por serial que tiene los 2 valores de ADC en string concatenados y separados por el caracter ',' El primer caracter es el tamaño del vector 
uint8 i=0; //variable que se utiliza para llenar el buffer de datos recibidos
uint8 fifofull=0; //bandera que indica cuanto el buffer está lleno. No se usa en este código
char  *ret; //apuntador a Strings que se usa para identificar el valor recibido después del caracter ':'
uint8 DataRecived=0; //bandera que se usa para identificar cada que llegue un byte por serial
uint8 value=0; //Si el valor que se recibe por serial es numérico, esta variable contendrá dicho valor

/****Variables para medición de ADC en el tiempo****///
uint8 BandTimer=0; //Bandera que indica interrupción cada 1ms
uint16 Countms;  // Contador de milisegundos. Cada 20ms se reinicia
uint16 ADCvalue[2]={0,0}; //Vector que contiene los valores crudos y acumulados de ADC
uint16 ADCprom0=0; //Promedio de 10 muestras del primer ADC
uint16 ADCprom1=0; //Promedio de 10 muestras del segundo ADC
uint8 graficar=0; //Bandera que indica si se desea enviar el ADC por serial o no.

/**Variables del muestreo**/
uint32 suma_presion=0;
uint32 suma_temperatura=0;
uint32 promedio_presion=0;
uint32 promedio_temperatura=0;
uint8 Count_Muestreo = 0;
uint8 BandMediciones=0;

//Interrupciones
CY_ISR_PROTO(RXint_isr); //Interrupción por serial
CY_ISR_PROTO(Timer_isr); //Interrupción cada 1m
CY_ISR_PROTO(TeclaKBI); //Interrupcion por teclado

//variables Creadas en el codigo propias
uint8 BandKBI=0; //Bandera que me indica una interrupcion por teclado 
uint8 Menu = 0;  //Me indica en que menu se esta
uint8 Tecla;     //Me indica la tecla presionada
uint8 BandNegativo=0; //Me inidica el signo de la temperatura
uint16 presion;      //Variable que me guarda el valor de la presion
uint16 temp;         //Variable que me guarda el valor de la temperatura
uint16 IntAngulo=0; //Variable donde se guarda el valor entero del angulo que se trae de labview
uint32 Compare=0;   //Varibale que me guarda el valor de compare que se pasara al PWM para mover el servomotor
uint8 p = 0;    //Me recupera el valor guardado de presion en la memoria EEPROM

#define presion1  0x00000001u //Defino la direccion en donde deseo que me guarde la presion y la pongo con la clave presion1

//Funciones propias//

void Guardar(void); //Funcion que me guarda el valor de presion en la memoria EEPROM
void MenuLCD(uint8); //Funcion donde se encuenta los menus establecidos
void MoverServo (const char *Angulo); //Funcion creada para calcular el compare y pasarlo al PWM con la finalidad de mover el servo al angulo deseado (mandado por labview)
void calculartempyp(void); //Funcion que me calcula la temperatura y la presion respecto al valor ADC de los potenciometrso
void Read(void); //Funcion que me lee la presion guardada en la EEMPROM
void blindLCD(void);
uint8 bandBlind;
 
//Se define la matriz correspondiente a cada posición del teclado, se define como constante ya que no se alterará en el programa.
const uint8 miTeclado[4][4] = {
    {1,2,3,'A'},//Row 0
    {4,5,6,'B'},//Row 1
    {7,8,9,'C'},//Row 2
    {'*',0,'#','D'}//Row 3
};

//----------------------------------------------------------------main-------------------------------------------------------------------
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    InitAllModules(); //Inicializa interrupciones y todos los módulos   
    //----------------------------------------------for infinito---------------------------------------
    for(;;)
    {
        if(isDataReady()){ //Cuando recibe un mensaje completo por serial, incluido el '\n' entra aquí
            analyseData(); //Analiza que tipo de dato se recibió
        }//is Dara Ready
        
        if (BandTimer==1){ //entra cada 1ms a aca (se define el tiempo por el contador)
            BandTimer=0; //bajo la bandera
            if (Menu==0){ //si esto en el menu incial, pongo el menu en la LCD por 1s y luego muestro el menu 1
                MenuLCD(Menu);
                CyDelay(2000);
                Menu=1;
                MenuLCD(Menu);
            }//menu 0
            Countms++; //aumento el contrador 
            if(Countms%2==0){  //Toma una mestra cada 2ms
                getADCvalue();   //Obtengo los valores crudos de ADC usando el Mux           
                if(Countms==20){ //cada 20ms calcula promedio
                    Countms=0;
                    calculateADCprom(); //calculo el valor promedio del adc cada 20 ms
                    calculartempyp();  //calculo la temperatura y la presion 
                    if(graficar)sendADCData(); //Mando los valores al labview separados por ,
                    if (Menu==2){ //Si esta en el menu 2 muestro los valores de presion
                        Tecla = Teclado_AsignarTeclaExtern(miTeclado); //le que tecla se presion
                        if (Tecla== 'A'){//Si le doy esta opcion (tecla A) me guarda en la memoria EEPROM La fecha
                            Guardar(); //Aca me guarda el valor de temperatura en la memoria EEPROM
                            //Muestro el mensaje de guardado exitoso en la memoria por 2 segundos
                            LCD_ClearDisplay(); 
                            LCD_Position(0,0);
                            LCD_PrintString("Presion guardada");
                            LCD_Position(1,6);
                            LCD_PrintString("exitosamente");
                            CyDelay(2000);
                        }
                    }
                }//cuando coja las 20muestras
            }//counts
//            if (Menu==5) MoverServo(Angulo); //Si esta en el menu 5 muevo el servo 
            if (Menu==5){ //Si estoy en el menu 4 muestro cual es la presion que guarde 
                    LCD_Position(0,0);
                    LCD_PrintString("La presion");
                    LCD_Position(1,0);
                    LCD_PrintString("guardada es: ");
                    //aca retorno la fecha que guarde en la memoria eemprom
                    Read(); //leo la presion guardada
            }//menu 4
        }//BandTimer

        if (BandKBI==1){ //Entra aca cuando se produce una interrupcion por teclado
            BandKBI=0;
            Tecla = Teclado_AsignarTeclaExtern(miTeclado); //guardo la tecla presionada en la variable
            if(Tecla ==1 && Menu==1){ //Entra al monitoreo de presion si la tecla es 1 y esta en menu 1
                BandKBI=0;
                Menu = 2;
                MenuLCD(Menu);//me muestra en la LCD el menu 3
            }//opcion 1

            else if(Tecla == 2 && Menu==1){//Opcion 2 mostrar fecha, hora y temperatura
                Menu=3;
                MenuLCD(Menu); //me muestra en la LCD el menu 2
            }//opcion 2
            
            else if(Tecla == 4 && Menu==1){//Opcion 4 mostrar variable guardada
                Menu=5;
                MenuLCD(Menu); //me muestra en la LCD el menu 4
            }//opcion 4
            
            else if (Tecla ==3 && Menu==1){ //Opción 3 mover servomotor 
                Menu=4; 
                MenuLCD(Menu); //me muestra en la LCD el menu 5
            }//opcion 3
            
            if(Tecla == '#'){ //Si oprimo esta tecla me devuelve al menu 1 y me inicializa las variables y banderas
                Menu=1;
                MenuLCD(Menu);//Me devuelva al menu principal 
                BandKBI=0;
                Count_Muestreo=0;
                suma_presion = 0;
                suma_temperatura = 0;
                promedio_presion = 0;
                promedio_temperatura = 0;
                presion = 0;
                temp = 0;
                BandNegativo=0; 
            }//opcion #
            BandMediciones=0;
        }//banKBI  
        if(Segundos!=RTC_ReadSecond() && Menu==2){ //Cada segundo entra aquí y actualiza reloj, fecha y valor ADC en el LCD
            LCD_Update_P();  
        }//SEGUNDOS==RTC
        if(Segundos!=RTC_ReadSecond() && Menu==3){ //Cada segundo entra aquí y actualiza reloj, fecha y valor ADC en el LCD
            LCD_Update_T();  
        }//SEGUNDOS==RTC
    }//for 
}//main

//-------------------------------------------FUNCIONES------------------------------------------------------------------------------------------------------

CY_ISR(RXint_isr){  //Interrupción por serial
    DataRecived=1; //indico que se ha recibido un dato
    buffer[i++]= UART_ReadRxData();  //Cada dato que llega se guarda en el buffer
    if(i==30)fifofull=1;  //En caso de que se llene el buffer
}

CY_ISR(Timer_isr){  //Interrupción por tiempo que genera una interrupcion cada 1ms
    BandTimer=1;
}

CY_ISR(TeclaKBI){ //Interrupcion por teclado
    BandKBI=1;
}

void calculartempyp(void){   //Funcion que me calcula el valor de presion y temp por medio del ADC 
    //para calcular presion con el ADC 
    if(ADCprom0<=3685) presion =  ((ADCprom0+11055)*30)/737; 
    else presion = 600; 
    
    //para calcular temperatura
    if(ADCprom1<=3685){ //Se define para los valores de ADC validos 
        if(ADCprom1<921){
            temp=(921 - ADCprom1)*400/3685; //Se define la función que permite calcular la variable
            BandNegativo = 1;
            }                         
        else{ 
            temp=(ADCprom1 - 921)*400/3685; //Se define la ecuación de esta región
            BandNegativo = 0;
                }//else temp
            }
    else{ 
        temp = 300;  //para valores mayores a 3685 se estabiliza la temperatura en 30 y ese cero de mas es por que se mostrara con un decimal
        }
}

void InitAllModules(void){
    //Inicialización de interrupciones
    Timer_StartEx(Timer_isr);  
    RXint_StartEx(RXint_isr);
    KBI_StartEx(TeclaKBI);
    //Inicialización de modulos 
    AMux_Start();
    ADC_Start();
    Counter_Start();
    LCD_Start(); 
    UART_Start(); 
    RTC_Start(); 
    Teclado_Start();
    Segment_Start();
//    PWM_Start(); 
    EEPROM_Start();
    AsignarHoraNueva(Hora);  //Carga la hora inicial
    AsignarFechaNueva(Fecha); //Carga la fecha inicial
}

void AsignarHoraNueva(const char *Hora){ //Asigna la Hora en el RTC
    RTC_WriteHour((Hora[0]-48)*10+(Hora[1]-48)); //Se recoge del vector hora la posicon 0 y 1 que son la hora y se escribe en el modulo de hora del RTC
    RTC_WriteMinute((Hora[3]-48)*10+(Hora[4]-48));//los min son con la posicon 3 y 4
    RTC_WriteSecond((Hora[6]-48)*10+(Hora[7]-48));//los segundos con la 6 y 7 
}
void AsignarFechaNueva(const char *Fecha){ //Asigna la fecha en el RTC
    RTC_WriteDayOfMonth((Fecha[0]-48)*10+(Fecha[1]-48));
    RTC_WriteMonth((Fecha[3]-48)*10+(Fecha[4]-48));
    RTC_WriteYear((uint16)((uint16)(Fecha[6]-48)*1000+(Fecha[7]-48)*100+(Fecha[8]-48)*10+(Fecha[9]-48)));
}

uint8 isDataReady(void){  // Siempre retorna un cero, a menos que se reciba el caracter '\n' (un enter)
    if(DataRecived==0)return 0; //Si no ha recibido nada, retorna cero
    DataRecived=0;  //Si recibió algo, apaga la bandera, pero necesita chequear si es '\n'
    if(buffer[i-1]!='\n')return 0; //Si no es '\n' retorna un cero
    buffer[i-1]=0;  //En caso de que si sea un '\n' lo reemplaza por un 0 en el buffer y retorna un 1
    return 1; 
}
void analyseData(void){
    if(strncmp(buffer, "Hora", 4)==0){ //Compara si los primeros 4 bytes de buffer es Hora
        ret = strchr(buffer, ':'); //Retorna los caracteres que están después de ':' incluyendo los ':'
        ret++; //apunta a los caracteres después de ':'
        strcpy(Hora, ret); //Asigna los caracteres después de ':' al vector Hora
        UART_PutString("Hora recibida:");
        UART_PutString(Hora); //Devuelve el valor de hora recibido para comprobar
        AsignarHoraNueva(Hora); //Asigna hora nueva.
        //mostrarTiempo(); //Va a la funcion para mostrar el tiempo
    }
    else if(strncmp(buffer, "Fecha", 5)==0){ //Compara si los primeros 5 bytes de buffer es Fecha y de resto es similar al código de hora
        ret = strchr(buffer, ':');
        ret++;
        strcpy(Fecha, ret);
        UART_PutString("Fecha recibida:");       
        UART_PutString(Fecha);
        AsignarFechaNueva(Fecha);
        //mostrarFecha();//Va a la funcion para mostrar el Fecha
    }
    else if(strncmp(buffer, "Graficar", 8)==0){//Compara si los primeros 8 bytes de buffer es Graficar
        ret = strchr(buffer, ':');
        ret++;
        graficar=atoi(ret);  //Después de graficar, se recibe un ASCII que representa un entero. Aquí se convierte a entero.
    }
    else if (strncmp(buffer, "Angulo", 6)==0){ //Compara si los primeros 6 bytes de buffer es Angulo 
        ret = strchr(buffer, ':');//Retorna los caracteres que están después de ':' incluyendo los ':'
        ret++;//apunta a los caracteres después de ':'
        strcpy(Angulo, ret);//Asigna los caracteres después de ':' al vector Angulo
        UART_PutString("Angulo recibido:");//manda al labview el mensaje por serial  
        UART_PutString(Angulo);//Devuelve el valor de Angulo recibido para comprobar
//        MoverServo(Angulo); //va la funcion para mover el servo
        
    }
    i=0;  //Reinicia la posición del buffer
    memset(buffer,0,sizeof(buffer));  // Pone todo el buffer en 0
}

void mostrarTiempo (void){ //Muestra la hora en el LCD en formato 24H
    LCD_Position(0,0);
    LCD_PrintString("HORA: ");
    LCD_Position(0,6);
    LCD_PrintNumber(RTC_ReadHour()/10);
    LCD_PrintNumber(RTC_ReadHour()%10);
    LCD_PutChar(':');
    LCD_PrintNumber(RTC_ReadMinute()/10);
    LCD_PrintNumber(RTC_ReadMinute()%10);
    LCD_PutChar(':');
    LCD_PrintNumber(RTC_ReadSecond()/10);
    LCD_PrintNumber(RTC_ReadSecond()%10);
}
void mostrarFecha (void){ //Muestra la fecha en el LCD
    LCD_Position(1,0);
    LCD_PrintString("FECHA: ");
    LCD_Position(1,7);
    LCD_PrintNumber(RTC_ReadDayOfMonth()/10);
    LCD_PrintNumber(RTC_ReadDayOfMonth()%10);
    LCD_PutChar('/');
    LCD_PrintNumber(RTC_ReadMonth()/10);
    LCD_PrintNumber(RTC_ReadMonth()%10);
    LCD_PutChar('/');
    LCD_PrintNumber(RTC_ReadYear());

}

void getADCvalue(void){ //Multiplexación de ADC, me recoge los valores ADC de cada uno de los canales del multiflexor
    AMux_Select(0);
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    ADCvalue[0]+=ADC_GetResult16();
    AMux_Select(1);
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    ADCvalue[1]+=ADC_GetResult16();
}

void calculateADCprom(void){ //Calcula promedio de 10 muestras obtenido en ambos canales de la funcion getADC value 
    ADCprom0=ADCvalue[0]/10;
    ADCprom1=ADCvalue[1]/10;
    ADCvalue[0]=0;
    ADCvalue[1]=0;

}
void LCD_Update_P(void){ //Mostrar todo en el LCD la fecha y el tiempo
    Segundos=RTC_ReadSecond();
    LCD_ClearDisplay();
    mostrarTiempo();
    mostrarFecha();
    LCD_Position(2,3);
    LCD_PrintString("P: ");
    LCD_PrintU32Number(presion/10); //Parte entera
    LCD_PrintString(".");
    LCD_PrintU32Number(presion%10); //Primer decimal
    LCD_PrintString(" kPa"); //Unidad en KPa
    if(presion>600 || presion<=450){
        bandBlind=1;
    }
//        LCD_ClearDisplay();
//        LCD_Position(1,3);
//        LCD_PrintString("ALERTA");
//        blindLCD();
//        LCD_Position(2,3);
//        LCD_PrintString("P: ");
//        LCD_PrintU32Number(presion/10); //Parte entera
//        LCD_PrintString(".");
//        LCD_PrintU32Number(presion%10); //Primer decimal
//        LCD_PrintString(" kPa"); //Unidad en KPa
//    }
}
void LCD_Update_T(void){ //Mostrar todo en el LCD la fecha y el tiempo
    Segundos=RTC_ReadSecond();
    LCD_ClearDisplay();
    mostrarTiempo();
    mostrarFecha();
    LCD_Position(2,3);
    
    if(BandNegativo) LCD_PrintString("T= -"); 
    else  LCD_PrintString("T= "); 
    LCD_PrintU32Number(temp/10); //Parte entera
    LCD_PrintString(".");
    LCD_PrintU32Number(temp%10); //Segundo decimal
    LCD_PrintString(" ");
    LCD_PutChar(0xDF);
    LCD_PrintString("C");
//    if(temp>250 || temp<=230){
//        LCD_ClearDisplay();
//        LCD_Position(1,3);
//        LCD_PrintString("ALERTA");
//        blindLCD();
//    }
    
    
}
void sendADCData(void){  //Envía los dos valores de ADC uno seguido del otro separado por coma.
    if(BandNegativo) sprintf(str,"%s", "-"); //me manda el signo negativo o positivo segun sea el caso
    else  sprintf(str,"%s", "+"); 
    strcat(DatatoSend,str);  //Concatena str a DatoSend(el cual ya tiene el primer valor ADCprom0 + ','.
    sprintf(str,"%u",temp);  //COPIA el valor de ADCprom1 al String str
    strcat(DatatoSend,str);  //Concatena str a DatoSend(el cual ya tiene el primer valor ADCprom0 + ','.
    strcat(DatatoSend,",");      //Concatena la ',' a Datosend
    sprintf(str,"%u", presion);  //COPIA el valor de ADCprom0 al String str
    strcat(DatatoSend,str);      //Concatena  str a DatoSend (el cual está vacío inicialmente)

    sprintf(str,"%u",strlen(DatatoSend)); // Determina el tamaño del String DatoSend, se copia dicho valor al String str
    UART_PutString(str);  // Primer dato que se envía por serial. Corresponde al tamaño del vector DataSend.
    
    UART_PutString(DatatoSend); //Segundo dato que se envía por serial. Corresponde al vector DataSend.
    memset(DatatoSend,0,sizeof(DatatoSend));  //Borra el vector DatoSend para que quede disponible para un próximo envío.
}

void Guardar(){
    EEPROM_WriteByte(presion , presion1); //Me guarda el valor de la presion en la direccion establecida en la EEPROM
}

void Read(void){
    p = EEPROM_ReadByte(presion1); //Leo el valor guardado en el EEPROM y la guardo en la variable p
    LCD_Position(3,0); //muestro el valor guardado
    LCD_PrintNumber(p/10);
    LCD_PrintString(".");
    LCD_PrintNumber(p%10);
    LCD_PrintString(" kPa");
}

//void MoverServo (const char *Angulo) {
//    IntAngulo=(int)atoi(Angulo); //Paso el angulo recibido a entero
//    //Calculo el compare dependiendo del angulo en que se encuentre
//    if (IntAngulo<=90){
//           Compare=(uint32)(IntAngulo*248)/9 + 745; 
//        }
//    else {
//        Compare=(uint32)(IntAngulo*110)/3 -100;
//    }
//    PWM_WriteCompare(Compare); //Mando el valor de compare al PWM para que me mueva el servo
//    //Muestro el angulo que deseo mover en la LCD
//    LCD_Position(0,0);
//    LCD_PrintString("Angulo: ");
//    LCD_Position(0,7);
//    LCD_PrintNumber(IntAngulo);
//    LCD_PutChar(0xDF);
//    LCD_PrintString("          ");
//}
void blindLCD(void){
    if(bandBlind){
    bandBlind=0;
    LCD_DisplayOn();
    CyDelay(500);
    LCD_DisplayOff();
    CyDelay(500);  
    }
    
}
void MenuLCD (unsigned char Menu){//Función donde se definen los menú implicados en el funcionamiento de sistema
    switch (Menu){
        case 0: //Menú que muestra por 1s BINVENIDO AL SISTEMA
        LCD_ClearDisplay();
        LCD_Position(0,4);
        LCD_PrintString("BIENVENIDO AL");
        LCD_Position(1,5);
        LCD_PrintString("SISTEMA DE");
        LCD_Position(2,5);
        LCD_PrintString("NAVEGACION");
    break;
        
        case 1: //Menú que me muestra el menú con las 4 opciones
        LCD_ClearDisplay();
        for(uint8 i=0;i<4;i++){
            Segment_SetBrightness(0,i);// me pone el brillo en cero en el display 7 segmentos
        }//for
        LCD_Position(0,0);
        LCD_PrintString("1.PRESION CABINA");
        LCD_Position(1,0);
        LCD_PrintString("2.TEMP CABINA");
        LCD_Position(2,0);
        LCD_PrintString("3.ANGULO INCLINA");
        LCD_Position(3,0);
        LCD_PrintString("4.MOSTRAR DATA");
    break;
        
        case 2: //Menú que muestra la fecha y la hora y la presión
        for(uint8 i=0;i<4;i++){
            Segment_SetBrightness(255,i);//Se encienden todos los display 7 segmentos.
        }//for
        Segment_Write7SegNumberDec(1,1,3,Segment_ZERO_PAD); //Muestra 2 desde la posicion uno usando 3 displays con ceros a la derecha
        break;
        
        case 3: //Menú que muestra la fecha, hora y la temperatura
        LCD_ClearDisplay();
        for(uint8 i=0;i<4;i++){
            Segment_SetBrightness(255,i);//Se encienden todos los display 7 segmentos.
        }//for
        Segment_Write7SegNumberDec(2,1,3,Segment_ZERO_PAD); //Muestra 1 desde la posicion uno usando 3 displays con ceros a la derecha  
        break;
            
        case 4: //Menú para mostrar el angulo
        LCD_ClearDisplay();
        for(uint8 i=0;i<4;i++){
            Segment_SetBrightness(255,i);//Se encienden todos los display 7 segmentos.
        }//for
        Segment_Write7SegNumberDec(3,1,3,Segment_ZERO_PAD); //Muestra 3 desde la posicion uno usando 3 displays con ceros a la derecha

        break;
        
        case 5: // Mostrar data
        LCD_ClearDisplay();
        for(uint8 i=0;i<4;i++){
            Segment_SetBrightness(255,i);//Se encienden todos los display 7 segmentos.
        }//for
        Segment_Write7SegNumberDec(4,1,3,Segment_ZERO_PAD); //Muestra 4 desde la posicion uno usando 3 displays con ceros a la derecha

//        MoverServo(Angulo);
//        PWM_WriteCompare(Compare); 

    break;

    }//swich
  }

/* [] END OF FILE */
