/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdlib.h>

uint8 band=0;
uint8 tecla;
uint8 SegundoNumero;
uint8 PrimerNumero;
uint8 Menu;
char Binario[32], hexadecimal[32];// Variables que van a almacenar la conversión a Binario y Hexadecimal respectivamente 


CY_ISR_PROTO(teclado_interrupt);// Interrupciones que genera cada presión del teclado matricial
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
    /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        if(Banderas.BandKBI){
            Banderas.BandKBI=0;
            tecla=Teclado_AsignarTeclaExtern(miTeclado);
                
            if(tecla=='*' && Menu==0){
                Menu=1;
                MenuLCD(Menu);// Se muestra el primer menú de elecciones
            }
            else if (tecla=='A' && Menu ==1){
     	        Menu=2;
                MenuLCD(Menu); //Se muestra el menú para convertir números decimales en binario 
                }
            else if (tecla=='B' && Menu ==1){
                   Menu=5;
                   MenuLCD(Menu); //Se muestra el menú para convertir numeros decimales a hexadecimales
            }
            else if (tecla<10 && tecla>=0){  //Si se presiona un numero entra aquí
                if(Menu == 2 || Menu==5){
             		PrimerNumero=tecla;
             		Menu++;
             		MenuLCD(Menu); }//Muestra el menú para ingresar el segundo número 
                else if(Menu==3 || Menu==6){
                   SegundoNumero=tecla;
                    Menu++;
                    MenuLCD(Menu);
                    CyDelay(5000);// Muestra la conversión por 5 seg
             		Menu=0;
             		MenuLCD(Menu);   //Muestra nuevamente el menú inicial
         	     }

            }        
        }
    }
}

CY_ISR(teclado_interrupt){ // Bandera de interrupción
    Banderas.BandKBI=1;
}
void MenuLCD (unsigned char Menu){
    switch (Menu){
    case 0:
        LCD_ClearDisplay();
        LCD_Position(0,0) ;
        LCD_PrintString("     Bienvenido");
        LCD_Position(2,0);                      // Menú inicial
        LCD_PrintString("  Presione * para  ");
        LCD_Position(3,0) ;
        LCD_PrintString("      comenzar");
        break ;
    case 1:
        LCD_ClearDisplay();
        LCD_Position(0,3) ;
        LCD_PrintString("A->DEC to BIN");
        LCD_Position(2,3);
        LCD_PrintString("B->DEC to HEX");
        break;
    case 2:
        LCD_ClearDisplay();
        LCD_Position(0,0) ;
        LCD_PrintString("    DEC to BIN");
        LCD_Position(1,0);
        LCD_PrintString("Ingrese numero DEC:");
        LCD_Position(2,8);
        LCD_WriteControl(LCD_CURSOR_BLINK);
        break;
    case 3:
        LCD_PrintNumber(tecla); // Muestra las decenas 
        LCD_WriteControl(LCD_DISPLAY_ON_CURSOR_OFF);
        LCD_Position(0,0) ;
        LCD_PrintString("    DEC to BIN");
        LCD_Position(1,0);
        LCD_PrintString("Ingrese numero DEC:"); // Ingresa las unidades del numero
        LCD_Position(2,9); // La posición es una posición a la derecha de las decenas del numero 
        LCD_WriteControl(LCD_CURSOR_BLINK);
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
