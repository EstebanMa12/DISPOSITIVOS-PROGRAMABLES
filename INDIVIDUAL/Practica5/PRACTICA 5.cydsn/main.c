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
CY_ISR_PROTO(IRQ_ISR);
CY_ISR_PROTO(Timer_ISR);
uint8 band_2mili=0;
uint8 TitileoSingularDespla=0;
uint16 band380ms=0;
uint8 mili2segundos=0;
uint8 pulsecounter=0;
uint8 Posicion=1;
uint8 contador[4]={0,0,0,0};
uint8 cnt4seg=0;
uint8 Bright[2]={0,255};
uint8 BandeBrillo=0;
uint16 band4seg=0;
uint16 cnt=0;
uint8 configuration=0, Segundos=0;
uint16 T_tiempo=0, bandseg=0, vel =500,cnt_noconf;
uint8 band_tarea1=0,Band_Final=0;
uint16 cnt_time;
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Interrupt_StartEx(IRQ_ISR);
    Timer_StartEx(Timer_ISR);
    Segments_Start();
    Contador_Start();
    DosP_Write(0b1);
    Segments_Write7SegNumberDec(0,1,3,Segments_ZERO_PAD);//Se escriben 3 ceros a la derecha en los 7 segmentos
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(band_2mili){
            band_2mili=0;
            band4seg++;
    //-----------------------TAREA 1------------------------------------------------------------------
            if(SW_Read()==0){ 
                mili2segundos++;
                Band_Final=0;
//                contador[1]=0;contador[2]=0;contador[3]=0;
    //-----------------------TITILEOS----------------------------------------------------------------
                if(mili2segundos<=125)Segments_SetBrightness(Bright[1],Posicion);
                if(mili2segundos>125)Segments_SetBrightness(Bright[0],Posicion);
                if(mili2segundos>250)mili2segundos=0;             
    //-----------------------4SEGUNDOS---------------------------------------------------------------
                if(band4seg==2000){// La condición es que si no se realiza ninguna acción el titileo pase de un lado a otro
                    band4seg=0;
                    Segments_SetBrightness(Bright[1],Posicion);

                    if(Posicion==3){
                        Posicion=0;  
                        configuration=1;   
                    }
                    mili2segundos=0;
                    Posicion++;
                }
    //----------------------------------------

                if(band380ms){
                    cnt++;
                    band4seg=0;
                    if(pulsecounter==1 && cnt>=190){
                        if(contador[1]>=2)contador[1]=-1;// Definición de limites de los minutos y segundos
                        if(contador[2]>=5)contador[2]=-1;
                        if(contador[3]>=9)contador[3]=-1;                      
                        contador[Posicion]++;// Si se cumple la condición se cambia de posición
                        Segments_Write7SegDigitDec(contador[Posicion],Posicion); // Se escribe el valos del contador en la posición respectiva
                        
                        cnt=0;
                        pulsecounter=0;
                        band4seg=0;
                        band380ms=0;
                        mili2segundos=0;
                    }
                    else if(pulsecounter==2 && cnt<190){
                        cnt=0; // Si hay dos pulsaciones se reinicia el contador
                        Segments_SetBrightness(Bright[1],Posicion);                        
                        if(Posicion==3){
                            Posicion=0;
                            configuration=1; }
                        Posicion++;
                        pulsecounter=0;
                        band380ms=0;
                        band4seg=0;
                        mili2segundos=0;//               
                    }
                }

            }
//-----------------TAREA 2------------------------------------------------
            if(SW_Read()){
                if(configuration==1){
                    cnt_time++;
                    Segments_SetBrightness(Bright[0],0);
                    Segments_SetBrightness(Bright[1],1);
                    Segments_SetBrightness(Bright[1],2);
                    Segments_SetBrightness(Bright[1],3);
                    //--------BUZZER----------------------------
                    if(SW_buzz_Read()==1){
                        if(contador[3]%5==0)Buzzer_Write(1);
                        else Buzzer_Write(0);
                    }else Buzzer_Write(0);
                    
                    //---------------------

                    Segments_SetBrightness(Bright[1],1);
                    if(cnt_time>=vel){
                        cnt_time=0; // Se reinicia el contador
                        
                        T_tiempo= contador[1]*60 + contador[2]*10 +contador[3];// Se guarda en una variable todo el tiempo en segundos 
                        T_tiempo--;// Se va restando cada vez
                        contador[1]= T_tiempo/60;// Minutos
                        contador[2]=(T_tiempo%60)/10;// Corresponde a decenas de segundos
                        contador[3]=T_tiempo%10;// Segundos
                        Segments_Write7SegDigitDec(contador[1],1);
                        Segments_Write7SegDigitDec(contador[2],2);
                        Segments_Write7SegDigitDec(contador[3],3);
                        if(contador[1]==0 && contador[2]==0 && contador[3]==0){// Si todo se cumple entonces se genera una bandera final
                            configuration=0;
                            Band_Final=1;}
                    }

                    
                    if(Band_Final==1){//
                        LEDS_Write(1);
                        Buzzer_Write(0);
                        Segments_SetBrightness(Bright[1],0);
                        Segments_Write7SegNumberDec(0,0,4,Segments_ZERO_PAD);
                    }if(SW_Read()==0)configuration=0;
                }
                else if(configuration==0 && Band_Final==0){
                    band4seg=0;
                    cnt_noconf++;// Contador para cuando no esta configurado
                    Segments_Write7SegNumberDec(0,0,4,Segments_ZERO_PAD);
                    
                    if(cnt_noconf<=100){
                        Segments_SetBrightness(Bright[0], 1);
                        Segments_SetBrightness(Bright[0], 2);
                        Segments_SetBrightness(Bright[0], 3);
                        Segments_SetBrightness(Bright[0], 0);}
                    if(cnt_noconf>100){
                        Segments_SetBrightness(Bright[1], 1);
                        Segments_SetBrightness(Bright[1], 2);
                        Segments_SetBrightness(Bright[1], 3);
                        Segments_SetBrightness(Bright[1], 0);
                        }
                    if(cnt_noconf>200)cnt_noconf=0;
                    }               
                
            }

        }
        //-----------------------CAMBIO DE VELOCIDAD---------------------------------------------------------------
        if(SW_vel_Read()==1)vel=100;
        if(SW_vel_Read()==0)vel=500;

            
//-----------------------------------------------------------------------------------------------                

    }
}
CY_ISR(IRQ_ISR){
    pulsecounter++;
    if(pulsecounter==1)band380ms=1;// Cada que sucede una pulsación, inicia el conteo de los 380 ms
    
}
CY_ISR(Timer_ISR){
    band_2mili=1; 
}

    

/* [] END OF FILE */
