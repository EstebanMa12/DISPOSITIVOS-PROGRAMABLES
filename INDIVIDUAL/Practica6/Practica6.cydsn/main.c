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
uint8 bandtime=0;
uint32 suma_peso=0;
uint32 suma_temperatura=0;
uint32 promedio_peso=0;
uint32 promedio_temperatura=0;
uint32 Peso=0, Temperatura=0;
uint8 bandAdvertencia1=0;

void Visual();

CY_ISR_PROTO(Timer_ISR); // Función de interrupción del contador

int main(void)
{
    uint16 Contador=0;
    int32 VALADC=0;
    uint16 mVolts=0;
    uint8 Segundos=0;
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Start();
    timer_StartEx(Timer_ISR);
    counter_Start();
    ADC_SetScaledGain(8190);// 8190 equivale a 10V
    Mux_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(bandtime){
            bandtime=0;
        /* Place your application code here. */
        //EN EL CASO DE QUE LA CONTRASEÑA SEA INCORRECTA. *Para este caso simule que fuera con un switch
            if(clavecorrecta_Read()==1){
                Contador++;
                if(Contador%25==0){
                    Mux_Select(0); //Se toma el valor ADC para la primera variable (temperatura)
                    ADC_StartConvert(); //Se hace la conversión ADC
                    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT); //Se espera a que la conversión termine
                    uint32 VALADC1 = ADC_GetResult16(); //se obtiene el valor ADC, se hace casting a VALADC1 por el tamaño del número que se obtendrá
                    suma_temperatura+=VALADC1; //Se suma el valor ADC capturado y se guarda en la posición de memoria correspondiente de la variable temperatura por medio del apuntador
                    //Se realiza el mismo proceso descrito anteriormente pero para el caso de la segunda variable (peso), cuando el MUX = 1
                    Mux_Select(1);
                    ADC_StartConvert();
                    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
                    uint32 VALADC2 = ADC_GetResult16();
                    suma_peso+=VALADC2;
                    if(Contador==500){
                        Contador=0;
                        promedio_peso=suma_peso/20;
                        promedio_temperatura=suma_temperatura/20;
                        LCD_CLEAR_DISPLAY();
                        Visual(promedio_peso,promedio_temperatura);
                    }
                }
            }
                        
                
            }
        
    }
}
CY_ISR(Timer_ISR){ // Sucede una interrupción cada 1 ms
    counter_ReadStatusRegister();
    bandtime=1;
}
void Visual(uint32 VALADC0,uint32 VALADC1){
     //La funcion de transferencia del peso 
    Peso=(uint32)(VALADC0)*8200/4000;
    if (Peso>4847) bandAdvertencia1=1;// La condion del valor ADC que genera la advertencia 1
    if (Peso>= 8200) Peso=8200;  
    LCD_Position(0,0);
    if (VALADC1<= (256)){  
        if(VALADC1<=256){//Condicion para los valores positivos 
            LCD_Position(2,0);//Se configura la visualizacion en el lcd
            Temperatura=(uint32)(256-VALADC1)*100/256;
            LCD_PrintString("Temp=-");
            if (Temperatura>=0) bandAdvertencia=1;
            }
        else{//Para valores negativos
            LCD_Position(2,0);//Se configura la visualizacion en el lcd
            Temperatura=(uint32)(VALADC1-256)*100/256;
            LCD_PrintString("Temp=");
            }
    }
    else if (VALADC1>(256)){
        LCD_Position(2,0);
        Temperatura=(uint32)(VALADC1-153)*100/256;//se define solo una funcion de transferencia por que son
        LCD_PrintString("Temp= ");//solo para numeros positivos
        if (Temperatura >=1500) Temperatura=1500;//Se estabiliza el valor de la temperatura 
        if (Temperatura>= 705) bandAdvertencia=1;//Se condiciona la bandera de advertencia cuando supere ese valor
                   
        }
    // Visualizacion de los datos 
    LCD_Position(1,0);LCD_PrintString("Peso= ");//Se configura la visualizacion de los datos del peso 
    LCD_PrintNumber(Peso/100); //Se escrcibe la parte entera del valor 
    LCD_PutChar('.');
    if (Peso%100==0 || Peso%100<10)LCD_PrintNumber(0); //se escribe el primer y
    LCD_PrintNumber(Peso%100);//segundo decimal del resultado
    LCD_PrintString(" Kg");
    
    LCD_Position(2,6);//Se configura la visualizacion de los datos de la temperatura
    LCD_PrintNumber(Temperatura/10);//se escribe la parte entera del valor
    LCD_PutChar('.');
    LCD_PrintNumber(Temperatura%10);//se escribe el primer decimal 
    LCD_PutChar(LCD_CUSTOM_0);
    LCD_PutChar('F');
    VALADC0=0;//Se limpian los valores del adc para poder iniciar otra medicion en los 
    VALADC1=0;//siguiente 500 ms
    

}

/* [] END OF FILE */
