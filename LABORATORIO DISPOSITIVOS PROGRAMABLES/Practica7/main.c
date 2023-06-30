//#include "project.h"
////#define Duty5 600// datos obtenidos experimentalmente para 0º
////#define Duty10 4000u// datos obtenidos experimentalmente para 180º
//
//uint16 DutyCounts;
//uint16 Period;
//
//int main(void)
//{
//    CyGlobalIntEnable; /* Enable global interrupts. */
//    
//    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
//    PWM1_Start();
//    PWM1_WriteCompare(600);
//    Period=PWM1_ReadPeriod();
//    for(;;)
//    {
//        /* Place your application code here. */
//        for(DutyCounts=600;DutyCounts<=7200;DutyCounts+=100){
//            PWM1_WriteCompare(DutyCounts);
//            CyDelay(100);
//        }       
//    }
//}























#include "project.h"
#include <stdlib.h>
#include <stdio.h>
//uint8 band=0;
uint8 tecla;
uint8 SegundoNumero;
uint8 PrimerNumero;
uint8 Menu;
uint8 contadigitacion;
uint8 ClaveIngresada[4];
uint8 ClaveOriginal[4]={9,3,1,7};
uint8 CompararClave(const uint8 *Ingresada,const uint8 *Original);
uint8 bandClave=0;
//uint8 contador[4]={0,0,0,0};
uint8 bandera=0;
uint16 dato=0;
uint32 Angulo;
uint16 comp;
uint16 contador=0;
uint8 Banderita=0;
uint8 Bandera2=0;
//char matrixaster="****";
//char arrayastr[4];
//int a,b,c,d;
char Binario[32], hexadecimal[32];// Variables que van a almacenar la conversión a Binario y Hexadecimal respectivamente 


CY_ISR_PROTO(teclado_interrupt);// Interrupciones que genera cada presión del teclado matricial
CY_ISR_PROTO(Timer_ISR);
CY_ISR_PROTO(bosali);
//-------------------------TECLADO-----------------------------
void MenuLCD(unsigned char Menu);
const uint8 miTeclado[4][4]={ // Definición del teclado
        {1,2,3,'A'},//Row 0
        {4,5,6,'B'},// Row 1
        {7,8,9,'C'},// Row 2
        {'*',0,'#','D'}// Row 3
};
struct Variable{//  variable compuesta que permite agrupar diferentes tipos de datos en una única unidad lógica
    uint8 BandKBI;// Esta estructura podría utilizarse para agrupar varias variables relacionadas y organizarlas de manera más estructurada y lógica.
}Banderas;


int main(void)
{
    Teclado_Start();//
    LCD_Start();    // Se inicializan los componentes que se van a utilizar
    MenuLCD(Menu);  //
    isr_KBI_StartEx(teclado_interrupt);
    CyGlobalIntEnable; 
    ADC_Start();
    MUX_Start();
    LCD_LoadCustomFonts(LCD_customFonts);
    PWM1_Start();
    Timer_StartEx(Timer_ISR);
    bosali_StartEx(bosali);
//            period=PWM1_ReadPeriod();
//        comp=(uint32) period*(30/100);
//        PWM1_WriteCompare(comp);

    for(;;)
    {
//                if(band){
//            band=0;
//            LCD_PutChar(Teclado_AsignarTecla());
//        }
//        /* Place your application code here. */
        if(Banderas.BandKBI){
            Banderas.BandKBI=0;
            tecla=Teclado_AsignarTeclaExtern(miTeclado);
            if(Menu==0){
                if (tecla<10 && tecla>=0){
                    contadigitacion++;
                    if(contadigitacion==5){
                        bandera=1;
                        contadigitacion=1;
                    }
                    ClaveIngresada[contadigitacion-1]=tecla;
                }
                if(tecla=='#'){
                    contadigitacion=0;
                    bandera=0;
                }
    //            if(Menu==0){
    //                MenuLCD(Menu);
    //            }
                if(tecla=='*'){
                    bandClave= CompararClave(ClaveIngresada,ClaveOriginal);
                    if(bandClave==0){
                        LCD_ClearDisplay();
                        LCD_Position(1,3) ;
                        LCD_PrintString("Clave incorrecta");
                        CyDelay(1500);
                        LCD_ClearDisplay();
                        LCD_Position(1,3) ;
                        LCD_PrintString("Ingrese clave");
                        LCD_Position(2,5) ;
                        LCD_PrintString("de nuevo");
                        CyDelay(1500);
                        contadigitacion=0;
                        bandera=0;
                    }
                    if(bandClave==1){
                        Menu=1;
//                        MenuLCD(Menu);
                    }
                }
                MenuLCD(Menu);
            }
            
           
            if(Menu==1){
                MenuLCD(Menu);
            }
            if (tecla=='A' && Menu ==1){
     	        Menu=2;
//                MenuLCD(Menu); //Se muestra el menú para convertir números decimales en binario 
                }
        }
        if(Menu==2 && Bandera2==1){
          if(Banderita==1){
            Banderita=0;
            contador++;
        }
        if(contador>=3000){
            LCD_ClearDisplay();
            Menu=3;
        }
        }
        
        
            if(Menu==2){
                CyDelay(500);
                MenuLCD(Menu);
            }
            
            if(Menu==3){
//                CyDelay(500);
                MenuLCD(Menu);
            }
//            else if (tecla=='B' && Menu ==1){
//                   Menu=5;
//                   MenuLCD(Menu); //Se muestra el menú para convertir numeros decimales a hexadecimales
//            }
//            else if (tecla<10 && tecla>=0){  //Si se presiona un numero entra aquí
//                if(Menu == 2 || Menu==5){
//             		PrimerNumero=tecla;
//             		Menu++;
//             		MenuLCD(Menu); }//Muestra el menú para ingresar el segundo número 
//                else if(Menu==3 || Menu==6){
//                   SegundoNumero=tecla;
//                    Menu++;
//                    MenuLCD(Menu);
//                    CyDelay(5000);// Muestra la conversión por 5 seg
//             		Menu=0;
//             		MenuLCD(Menu);   //Muestra nuevamente el menú inicial
//         	     }
//
//            }        
        }
    }


CY_ISR(teclado_interrupt){ // Bandera de interrupción
    Banderas.BandKBI=1;
//    band=1;
}
CY_ISR(Timer_ISR){
    Banderita=1; 
}
CY_ISR(bosali){
    Bandera2=1;; 
}


void MenuLCD (unsigned char Menu){
    switch (Menu){
    case 0:
        PWM1_Start();
        PWM1_WriteCompare(600);
        LCD_ClearDisplay();
        LCD_Position(0,0) ;
        LCD_PrintString("     BIENVENIDO");
        LCD_Position(2,8);
        if(bandera==0){
        LCD_PrintString("****");
        }
        if(bandera==1){
          for(uint8 i=0;i<4;i++){
            LCD_Position(2,8+i);
            LCD_PrintNumber(ClaveIngresada[i]);
        }}
        if(contadigitacion!=0){
            for(uint8 i=0;i<contadigitacion;i++){
                LCD_Position(2,8+i);
                LCD_PrintNumber(ClaveIngresada[i]);
            }
        }
        break ;
    case 1:
        LCD_ClearDisplay();
        LCD_Position(0,1) ;
        LCD_PrintString("CONTROL SERVOMOTOR");
        LCD_Position(1,0) ;
        LCD_PrintString("A-Potenciometro");
        LCD_Position(2,0) ;
        LCD_PrintString("B-Teclado");
        LCD_Position(3,0) ;
        LCD_PrintString("C-Camilla");

        break;
    case 2:
        LCD_ClearDisplay();
        
        MUX_Select(0);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
//        CyDelay(500);
        dato=ADC_GetResult16();
        Angulo=(int32) (dato*180/4095) ;
//        Angulo/=6;
        comp=(uint32) ((dato*440)/273)+600;
//        period=PWM1_ReadPeriod();
//        comp=(uint32) period*5/100;
        
        
        if(comp>=7200){
            comp=7200;
        }
        if(comp<=600){
        comp=600;
        }
        PWM1_WriteCompare(comp);   
        
        LCD_Position(0,1) ;
        LCD_PrintString("A-potenciometro");
        LCD_Position(1,0);
        LCD_PrintString("Angulo = ");
        LCD_PrintNumber(Angulo);
        LCD_PutChar(LCD_CUSTOM_0);
        LCD_Position(3,0);
        LCD_PrintString("ADC = ");
        LCD_PrintNumber(dato);
        LCD_Position(2,0);
        LCD_PrintString("Dureza = ");
        LCD_PrintNumber((comp-600)/66);
        LCD_PutChar(LCD_CUSTOM_1);
        
//        if(Bandera2==1 && Banderita==1){
//            Banderita=0;
//            contador++;
//        }
//        if(contador>=3000){
//            Menu=3;
//        }

        break;
    case 3:
        LCD_ClearDisplay();
        LCD_Position(1,0);
        LCD_PrintString("Saliendo del sistema");
        CyDelay(2000);
        Menu=0;

        break;
    case 4:
        LCD_PrintNumber(tecla); // Muestra los números
        LCD_WriteControl(LCD_DISPLAY_ON_CURSOR_OFF); // Apaga el cursos
        CyDelay(500);
        LCD_ClearDisplay();// Limpia el display
        LCD_Position(1,0);
        LCD_PrintString("El numero en BIN es:");
        LCD_Position(2,8);
        SegundoNumero=(PrimerNumero*10)+SegundoNumero; // Se crea el número que se va a convertir a binario
        itoa(SegundoNumero,Binario,2);// Itoa es una libreria que permite convertir un numero entero en una cadena de caracteres: esta función toma 3 argumentos:  el número entero que se desea convertir, un puntero a un array de caracteres donde se almacenará la cadena resultante y un número entero que indica la base en la que se desea representar el número que en este caso es 2
        LCD_PrintString(Binario);
        break;
    case 5:
        LCD_ClearDisplay(); // Esta parte del codigo es la misma que para el binarios
        LCD_Position(0,0) ;
        LCD_PrintString("    DEC to HEX");
        LCD_Position(1,0);
        LCD_PrintString("Ingrese numero DEC:");
        LCD_Position(2,8);
        LCD_WriteControl(LCD_CURSOR_BLINK);
        break;
    case 6:
        LCD_PrintNumber(tecla);
        LCD_WriteControl(LCD_DISPLAY_ON_CURSOR_OFF);
        LCD_Position(0,0) ;
        LCD_PrintString("    DEC to HEX");
        LCD_Position(1,0);
        LCD_PrintString("Ingrese numero DEC:");
        LCD_Position(2,9);
        LCD_WriteControl(LCD_CURSOR_BLINK);
        break;
    case 7:
        LCD_PrintNumber(tecla);
        LCD_WriteControl(LCD_DISPLAY_ON_CURSOR_OFF);
        CyDelay(500);
        LCD_ClearDisplay();
        LCD_Position(1,0);
        LCD_PrintString("El numero en HEX es:");
        LCD_Position(2,8);
        SegundoNumero=(PrimerNumero*10)+SegundoNumero;
        itoa(SegundoNumero,hexadecimal,16); // Cambia en esta parte en donde se indica la base 16 que corresponde a Hexadecimal
        LCD_PrintString(hexadecimal);
        break;
    }
}
uint8 CompararClave (const uint8 *Ingresada, const uint8 *Original){
    uint8 Aciertos=0;
    uint8 m=0;
    for(m=0;m<4;m++){
        if(*Ingresada==*Original){
            Aciertos++;
        }
        Ingresada++;
        Original++;
    }
        if(Aciertos==4){
            return 1;
        }
        else{
            return 0;
        }
    }


































//----------------------------------------------------------------------------------------------------------

//#include "project.h"
//uint8 bandKBI = 0;
//CY_ISR_PROTO(teclado_interrupt);
//CY_ISR_PROTO(counter_isr);
//const uint8 miTeclado[4][4]={
//    {1,2,3,'A'},     //Row 1
//    {4,5,6,'B'},     //Row 2
//    {7,8,9,'C'},     //Row 3
//    {'*',0,'#','D'}  //Row 4   
//};
//uint8 CompararClave(const uint8 *Ingresada,const uint8 *original); //Función para comparar la clave ingresada con la esperada
//uint8 Tecla=0; // Valor de la tecla cada vez que se presiona.
//uint8 posPass=8; //Posición del cursor de la pnatalla LCD para la clave y los valores solicitados.
//uint8 passcorr[4]={9,3,1,7}; //Vector que contiene la clave correcta.
//uint8 pass[4]; //Vector que almacenara la clave ingresada por teclado.
//uint8 VectAng[4]={0,0,0,0}; //Almacena cada uno de los dígitos del valor del ángulo copiado por teclado.
//uint8 contAng=0; //Cuenta los dígitos que se almacenaron para el valor del ángulo en control por teclado.
//uint16 valAng=0; //Valor del ángulo ingresado por teclado.
//uint8 paso=0; //indica si se copiaron más de cuatro caracteres en la contraseña a ingresar.
//uint8 bandClave=0; //Indica si la clave ingresada es igual a la clave correcta.
//uint8 Menu=0; //Cada uno de los menús. Cambia de valor según el menú en que se ingrese.
//uint8 bandAng=0; //Evalúa si se quiere comprobar valor de ángulo en opción control por teclado.
//uint32 compare=0; //Valor del compare otorgado al PWM. (Depende el valor del ángulo deseado).
//uint16 dureza=0; //Valosr del Duty correspondiente al valor del compare.
//uint16 valADC=0; //Valor del ADC correspondiente al valor del voltaje del potenciómetro.
//uint16 contador=0; //Aumenta cuando se deja presionado el botón de reinicio del sistema (hasta que se suelta).
//uint8 BandReset=0; //Bandera que indica cuando se presiona el botón más de 4 seg. Para reiniciar el sistema.
//int main(void)
//{
//    TecMatric_Start(); //Inicio del Teclado Matricial.
//    LCD_Start();       //Inicio de la pantalla LCD
//    PWM_Start();       //Inicio del PWM
//    Counter_Start();   //Inicio del Contador
//    ADC_Start();       //Inicio del Conversor Análogo/Digital
//    isr_KBI_StartEx(teclado_interrupt);
//    LCD_Position(2,8);
//    LCD_PrintString("**");
//    isr_counter_StartEx(counter_isr);
//    CyGlobalIntEnable; /* Enable global interrupts. */
//    for(;;)
//    {
//        if (Menu==0){ //Menú de inicio.
//            LCD_Position(0,5);
//            LCD_PrintString("BIENVENIDO");
//            
//            if(bandKBI==1){ //Cada que se ingresa un valor de la contraseña de ingreso al sistema.
//                bandKBI=0;
//                if(Tecla!='*' && Tecla!='A' && Tecla!='B' && Tecla!='C' && Tecla!='D' &&Tecla!='#' ){
//                    LCD_Position(2,posPass);
//                    pass[posPass-8]=Tecla;
//                    LCD_PrintNumber(Tecla);         
//                    posPass+=1;
//                }
//                if(posPass==12)posPass=8;paso=1; //Cuando se escribe un 5° dígito, vuelve al primero.
//                if(Tecla=='#'){ //Para borrar toda la contraseña
//                    paso=0;
//                    posPass=8;
//                    pass[0]=0;pass[1]=0;pass[2]=0;pass[3]=0;
//                    LCD_Position(2,posPass);LCD_PrintString("**");
//                }
//                if(Tecla=='' && paso==1){ //Si se ingresan 4 dígitos y se presiona ''
//                    paso=0;
//                    bandClave=CompararClave(pass,passcorr);
//                    if(bandClave){ //Si la clave ingresada es correcta (1223)...
//                        Menu=1;    //Se ingresa al menú principal.
//                        LCD_ClearDisplay();
//                        posPass=8;
//                    }                                     
//                    if(bandClave==0){ //Si la clave ingresada es incorrecta...
//                        LCD_ClearDisplay();
//                        LCD_Position(1,2);
//                        LCD_PrintString("Clave Incorrecta");
//                        CyDelay(1500); //Muestra "Clave Incorrecta" durante 2 segundos.
//                        LCD_ClearDisplay();
//                        LCD_Position(1,2);
//                        LCD_PrintString("Ingrese clave ");
//                        LCD_Position(2,4);
//                        LCD_PrintString("de nuevo");
//                        CyDelay(1500);
//                        LCD_ClearDisplay();
//                        LCD_Position(2,8); //Vuelve a ubicar el cursor en la posición inicial.
//                        LCD_PrintString("**");
//                        posPass=8;
//                        Menu=0;
//                    }
//                }
//            }
//        }
//        if(Menu==1){ //Nos encontramos en el Menú principal.
//            LCD_Position(0,1);
//            LCD_PrintString("CONTROL SERVOMOTOR");
//            LCD_Position(1,0);
//            LCD_PrintString("A-Potenciometro");
//            LCD_Position(2,0);
//            LCD_PrintString("B-Teclado");
//            LCD_Position(3,0);
//            LCD_PrintString("C-Camilla");
//            if(Tecla=='A'){ //Si se elige la opción Control por Ptenciómetro.
//                bandKBI=0;
//                Menu=2; //Ingresa al Menú de Control por Potenciómetro
//                LCD_ClearDisplay();
//            }
//            if(Tecla=='B'){ //Si se elige la opción Ángulo por Teclado.
//                bandKBI=0;
//                Menu=3;     //Ingresa al Menú Control por Teclado.
//                LCD_ClearDisplay();
//            }
//            if(Tecla=='#'){ //Si se quiere regresar al Menú de inicio.
//                LCD_ClearDisplay();
//                Tecla=0;
//                bandKBI=0;
//                LCD_Position(2,8);
//                LCD_PrintString("**"); //Reiniciar valores y volver a pedir contraseña.
//            }
//            if(BandReset){ //Si se presionó el botón de reseteo por más de 4 segundos.
//                BandReset=0;
//                LCD_ClearDisplay();
//                LCD_Position(2,8);
//                LCD_PrintString("**");
//            }
//        }
//        if(Menu==2){
//            LCD_Position(0,2);
//            LCD_PrintString("A-POTENCIOMETRO");
//            LCD_Position(1,0);
//            ADC_StartConvert(); //Comenzar la conversión del voltaje del potenciómtro a ADC.
//            ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
//            valADC=ADC_GetResult16();
//            compare=((180*valADC)/4095)+1000; //Valor del compare para PWM según el valor de ADC.
//            dureza=(compare/6); //Valor del Duty del PWM.
//            LCD_PrintString("Angulo: ");
//            LCD_PrintNumber((180*valADC)/4095);LCD_PutChar(0xDF);LCD_PrintString("  "); //Imprime en pantalla el valor del ángulo de giro del servo.
//            LCD_Position(2,0);
//            LCD_PrintString("Dureza: ");
//            LCD_PrintNumber(dureza/100); //Imprime en la pantalla LCD el valor entero del Duty del PWM.
//            LCD_PrintString(".");
//            LCD_PrintNumber(dureza%100); ////Imprime en la pantalla LCD el valor decimal del Duty del PWM.
//            LCD_PrintString("%  ");
//            LCD_Position(3,0);
//            LCD_PrintString("ADC: ");
//            LCD_PrintNumber(valADC); //Imprime en pantalla el valor ADCsegún voltaje del potenciómetro.
//            PWM_WriteCompare(compare);  //Genera el nuevo compare en el PWM para el control del servo.
//            if(Tecla=='#') LCD_ClearDisplay();
//            if(BandReset){
//                BandReset=0;
//                LCD_ClearDisplay();
//                LCD_Position(2,8);
//                LCD_PrintString("**");
//            }
//        }
//        if(Menu==3){ //Si se ingresa la opción de control de ángulo por teclado.
//            LCD_Position(0,5);
//            LCD_PrintString("B-TECLADO");
//            LCD_Position(1,0);
//            LCD_PrintString("Angulo: ");
//            if(bandKBI==1){ //Cada que se presiona una tecla para ingresar valor de ángulo.
//                bandKBI=0;
//                bandAng=0;
//                if(Tecla=='C'){
//                    bandAng=1;
//                    posPass=8;
//                    valAng=(1000*VectAng[0])+(100*VectAng[1])+(10*VectAng[2])+(VectAng[3]); //Valor del ángulo ingresado
//                    if(valAng>180 || contAng==0){ //Si se ingresó un valor de ángulo incorrecto, o si no se ingresó nada por teclado.
//                        contAng=0;
//                        posPass=8;
//                        VectAng[0]=0; VectAng[1]=0; VectAng[2]=0; VectAng[3]=0; //Reinicia el valor del ángulo en 0.
//                        LCD_Position(1,8); //Reinicia la posición del cursor.
//                        LCD_PrintString("Error");
//                        CyDelay(2000);
//                        LCD_ClearDisplay(); //Muestra "Error" por dos segundo y borra pantalla.
//                    }
//                    if(valAng<=180 && contAng!=0){ //Si se ingresa un valor de ángulo correcto (entre 0° y 180°).
//                        LCD_Position(1,8);                        
//                        LCD_PrintNumber(valAng); //Muestra el valor del ángulo
//                        LCD_PutChar(0xDF); //Escribe el símbolo '°'.
//                        LCD_Position(2,0);
//                        compare=((310*valAng)/9)+1000; //Valor del compare para el PWM según el valor de ángulo ingresado.
//                        dureza=(compare/6); //Duty de la señal PWM.
//                        LCD_PrintString("Dureza: ");
//                        LCD_PrintNumber(dureza/10); //Escribe el valor entero del duty en pantalla.
//                        LCD_PrintString(".");
//                        LCD_PrintNumber(dureza%100); //Escribe el valor decimal del duty en pantalla.
//                        LCD_PrintString("%");
//                        PWM_WriteCompare(compare); //Genera el nuevo compare en el PWM para el control del servo.
//                    }
//                }
//                if(bandAng==0 && Tecla!='*' && Tecla!='#'){ //Si no se ha presionado la tecla 'c' para comprobar valor del ángulo.
//                    LCD_Position(1,posPass);
//                    LCD_PrintNumber(Tecla); //Escribir el valor del dígito en pantalla.
//                    VectAng[0]=VectAng[1]; //...
//                    VectAng[1]=VectAng[2]; //...
//                    VectAng[2]=VectAng[3]; //...
//                    VectAng[3]=Tecla;      //...Se almacenan cada uno de los dígitos del ángulo en un vector.
//                    posPass+=1;
//                    contAng+=1;
//                }
//                
//            }
//            if(Tecla=='#') LCD_ClearDisplay(); //Si se quiere volver al menú principal.
//            if(BandReset){ //Si se presionó el botón de reseteo por mas de 4 segundos.
//                BandReset=0;
//                LCD_ClearDisplay();
//                LCD_Position(2,8);
//                LCD_PrintString("**");
//            }
//        }
//        if(Menu==4){
//            LCD_Position(0,2);
//            LCD_PrintString("C-CAMILLA");
//            LCD_Position(1,0);
//            ADC_StartConvert(); //Comenzar la conversión del voltaje del potenciómtro a ADC.
//            ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
//            valADC=ADC_GetResult16();
//            compare=((6200*valADC)/4095)+1000; //Valor del compare para PWM según el valor de ADC.
//            dureza=(compare/6); //Valor del Duty del PWM.
//            LCD_PrintString("Angulo: ");
//            LCD_PrintNumber((180*valADC)/4095);LCD_PutChar(0xDF);LCD_PrintString("  "); //Imprime en pantalla el valor del ángulo de giro del servo.
//            LCD_Position(2,0);
//            LCD_PrintString("Dureza: ");
//            LCD_PrintNumber(dureza/100); //Imprime en la pantalla LCD el valor entero del Duty del PWM.
//            LCD_PrintString(".");
//            LCD_PrintNumber(dureza%100); ////Imprime en la pantalla LCD el valor decimal del Duty del PWM.
//            LCD_PrintString("%  ");
//            LCD_Position(3,0);
//            LCD_PrintString("ADC: ");
//            LCD_PrintNumber(valADC); //Imprime en pantalla el valor ADCsegún voltaje del potenciómetro.
//            PWM_WriteCompare(compare);  //Genera el nuevo compare en el PWM para el control del servo.
//            if(Tecla=='#') LCD_ClearDisplay();
//            if(BandReset){
//                BandReset=0;
//                LCD_ClearDisplay();
//                LCD_Position(2,8);
//                LCD_PrintString("**");
//            }
//        }
//    }
//}
//CY_ISR(teclado_interrupt){ //Definición de la función que se cumple cada que se presiona en el teclado matricial.
//    bandKBI=1;
//    Tecla=TecMatric_AsignarTeclaExtern(miTeclado);
//    if(Tecla=='#' && Menu!=0){ //Si se presiona la tecla '#' para regresar al menú anterior.
//        if(Menu==1){
//            Menu=0;
//            LCD_ClearDisplay();
//            bandClave=0;
//            pass[0]=0; pass[1]=0; pass[2]=0; pass[3]=0;
//            paso=0;
//            posPass=8;
//            LCD_Position(2,posPass);LCD_PrintString("**");
//        }
//        if(Menu==3 || Menu==2){
//            Menu=1;
//            VectAng[0]=0; VectAng[1]=0; VectAng[2]=0; VectAng[3]=0;
//            LCD_ClearDisplay();
//            LCD_Position(2,8);
//            LCD_PrintString("**");
//        }
//        
//        posPass=8;
//        contAng=0;
//        bandAng=0;
//        valAng=0;
//        LCD_ClearDisplay();
//    }
//    
//}
//CY_ISR(counter_isr){
//    if(reset_Read()==1){
//        contador++; //Variable que comienza a aumentar cuando se tiene presionado el botón de reseteo.
//
//        if(contador>=4000){ //Si se presionó el botón de reseteo por 4 segundos o más.
//            LCD_ClearDisplay();
//            LCD_Position(1,0);
//            LCD_PrintString("Saliendo del sistema");
//            CyDelay(2000); //Muestra mensaje "Saliendo del sistema" por dos segundos.
//            BandReset=1;
//            Menu=0; //Se regresa al menú de incio.
//            contador=0;
//            paso=0;
//            pass[0]=0;pass[1]=0;pass[2]=0;pass[3]=0;
//            posPass=8;
//            LCD_Position(2,posPass);LCD_PrintString("**");
//            bandClave=0;
//            bandKBI=0;
//            //Se reinician todas las variables de conteo y posición.
//        }
//    }
//    if(reset_Read()==0 && contador<4000){ //Si no se ha presionado el botón o se presionó menos de 4 segundos
//        contador=0;
//        //No se hace nada en el sistema.
//    }
//}
//uint8 CompararClave (const uint8 *Ingresada, const uint8 *Original){//Compara dos claves mediante apuntadores
//uint8 Aciertos=0;
//uint8 m=0;
//for(m=0;m<4;m++){
//if(*Ingresada==*Original){ //Si lo apuntado por Ingresada es igual a lo apuntado por Original
//    Aciertos++; //Cuente el número de aciertos
//}
//Ingresada++; //Apunte a la siguiente posición
//Original++;// Apunte a la siguiente posición
//}
//if (Aciertos==4){ //4 aciertos significa que la clave es correcta
//    return 1;
//}
//else{
//return 0;}}
//
///* [] END OF FILE */
//
//
//













