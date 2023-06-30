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
#define Dutyi 600
#define Dutyf 7200

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
uint32 dureza;
uint16 contador=0;
uint8 Banderita=0;
uint8 Bandera2=0;
uint16 DutyCounts=Dutyi;
uint16 contadorLED=0;
//char matrixaster="****";
//char arrayastr[4];
//int a,b,c,d;
char Binario[32], hexadecimal[32];// Variables que van a almacenar la conversión a Binario y Hexadecimal respectivamente 
uint8 BandBotUp;
uint8 Bandms;
uint16 contador_ms;


CY_ISR_PROTO(teclado_interrupt);// Interrupciones que genera cada presión del teclado matricial
CY_ISR_PROTO(Timer_ISR);
CY_ISR_PROTO(Boton_ISR);
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

//Declaracion de funciones
void FuncionSalir();
void FuncionBoton4seg();


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
    bosali_StartEx(Boton_ISR);
    PWM1_WriteCompare(DutyCounts);

    for(;;)
    {
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
                    }
                }
            }
            
           
            if(Menu==1){
                MenuLCD(Menu);
            }
            if (tecla=='A' && Menu ==1){
     	        Menu=2;
                }
            
            else if(Menu==2){
                CyDelay(500);
                MenuLCD(Menu);
            }
            
            if (tecla=='C' && Menu ==1){
                Menu=8;
            }
            if(Menu==8){
                MenuLCD(Menu);
                MUX_Select(0);
                ADC_StartConvert();
                ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
                dato=ADC_GetResult16();
                dureza= (uint32) ((440*dato)/273)+600;
                Angulo= ((dureza-600)*3)/110;
                LCD_Position(1,16);
                LCD_PrintDecUint16(Angulo);
                if(Angulo>=85){
                    Angulo=85;
                }
                if(Angulo<=70){
                    Banderita=0;
                    contadorLED++;
                    if(contadorLED<166)LED_Write(1);
                    else if(contadorLED>=333)LED_Write(0);
                }if(Angulo>70){
                   LCD_Position(3,0);
                   LCD_PrintString("Posicion incomoda");
                   LCD_PutChar(LCD_CUSTOM_0);
                }
                
                
                
            }
        }
    }
}



CY_ISR(teclado_interrupt){ // Bandera de interrupción
    Banderas.BandKBI=1;
//    band=1;
}
CY_ISR(Timer_ISR){
    Banderita=1; 
}
CY_ISR(Boton_ISR){
    BandBotUp=1;
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
        Bandera2=0;
        MUX_Select(0);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
//        CyDelay(500);
        dato=ADC_GetResult16();
        Angulo=(int32) (dato*180/4095) ;
//        Angulo/=6;
        comp=(uint32) ((dato*440)/273)+600;
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
       
        break;
    case 3:
        LCD_ClearDisplay();
        LCD_Position(1,0);
        LCD_PrintString("Saliendo del sistema");
        CyDelay(2000);
        Menu=0;

    case 8:
        LCD_ClearDisplay();
        LCD_Position(0,5) ;
        LCD_PrintString("C-CAMILLA");
        LCD_Position(1,0);
        LCD_PrintString("Angulo camilla:"); // Ingresa las unidades del numero
        break;
    }
}

void FuncionSalir(){ //Se activa cuando se mantiene presionado un boton por 4 segundos o mas
    LCD_ClearDisplay();
    LCD_Position(1,0);
    LCD_PrintString("SALIENDO DEL SISTEMA");
    CyDelay(2000); //Se espera 2 segundos con el mensaje en pantalla
    LCD_ClearDisplay();
    MenuLCD(0); //Se va a la pantalla de bienvenidos para ingresar contraseña
}

void FuncionBoton3seg(){ //Funcion para oprimir el boton en cualquier menú (1,3 o 4) para salir a la pantala de bienvenida
    if (BandBotUp){//Se activa cuando el boton se presiona y se mantiene presionado
        Banderita=0;
        BandBotUp=0;
        contador_ms++; //Comienza el conteo
        if (contador_ms<3000){ //Si el boton se suelta antes de los 3 segundos
            BandBotUp=0; //Se reinician banderas de boton oprimido y suelto
            contador_ms=0;//Se reinicia el contador de milisegundos para que no se acumule con las pulsaciones
        }
        else if (contador_ms>=3000){ //En caso contrario, cuando se deje de optimir el boton y hayan pasado 3 segundos ...
            BandBotUp=0; //Se reinician banderas de botones
            FuncionSalir(); //Se va a la funcion salir para salir del sistema a la pantalla de bienvenidos
        }
    }
}

//Interrupcion por terminal count del contador
CY_ISR(contador_interrupt){
    Bandms = 1; //Bandera del conteo de milisegundos
    if (Menu==1||Menu==3||Menu==4) FuncionBoton4seg();//Continuamente verifica si menú esta en 1 (eleccion de control del servo), 3(control por potenciometro) o 4(control por teclado) y se asigna la Funcion del Boton 4 segundos para que pueda ir a la pant de inicio
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























