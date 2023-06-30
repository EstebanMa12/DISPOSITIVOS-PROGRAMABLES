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
uint8 uu=0;
uint8 Bright[2]={0,255};
uint8 BandeBrillo=0;
uint16 band4seg=0;
uint8 band_pulse=0;
uint16 cnt=0;
uint8 configuration=0, Segundos=0;
uint16 T_tiempo=0, bandseg=0, vel =0,cnt_noconf;
uint8 band_tarea1=0,Band_Final=0;

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
        if(SW_Read()==0){
            configuration=0;
            Band_Final=0;
            Segments_SetBrightness(Bright[0],0);
            if(band_2mili){
                band_2mili=0;
                mili2segundos++;
                band4seg++;
                bandseg++;
                
    //-----------------------TITILEOS----------------------------------------------------------------
                if(mili2segundos<=125)Segments_SetBrightness(Bright[1],Posicion);
                if(mili2segundos>125)Segments_SetBrightness(Bright[0],Posicion);
                if(mili2segundos>250)mili2segundos=0;             
    //-----------------------4SEGUNDOS---------------------------------------------------------------
                if(band4seg==2000){
                    band4seg=0;
                    Segments_SetBrightness(Bright[1],Posicion);
                    mili2segundos=0;
                    Posicion++;
                    if(Posicion>=3)Posicion=1;  
                    configuration=1;   
                    }
    //-----------------------PULSACIÓN---------------------------------------------------------------
                if(band_pulse){
                    band_pulse=0;
                    pulsecounter++;
                    if(pulsecounter==1)band380ms=1;
                }
                if(band380ms){
                    cnt++;
                    band4seg=0;
                    if(pulsecounter==1 && cnt>=190){
                        cnt=0; pulsecounter=0;
                        if(contador[1]>=2)contador[1]=-1;
                        if(contador[2]>=5)contador[2]=-1;
                        if(contador[3]>=9)contador[3]=-1;
                        
                        contador[Posicion]++;
                        Segments_Write7SegDigitDec(contador[Posicion],Posicion);
                        
                        band4seg=0;
                        band380ms=0;
                        mili2segundos=0;
                        band_pulse=0;
                    }
                    if(pulsecounter==2 && cnt<190){
                        cnt=0;
                        Segments_SetBrightness(Bright[1],Posicion);
                        Posicion++;
                        pulsecounter=0;band380ms=0;band4seg=0;mili2segundos=0;band_pulse=0;
                        if(Posicion==4){
                            Posicion=1;
                            configuration=1; }                 
                    }
                }

            }
        }
//-----------------TAREA 2------------------------------------------------
        if(SW_Read()==1){
            if(configuration==1){
            if(band_2mili){
                band_2mili=0;
                mili2segundos++;
                bandseg++;
                band_tarea1=1;
                if(band_tarea1==1){
                    band_tarea1=0;
                    mili2segundos=0;
                    Segments_SetBrightness(0,0);
                    Segments_Write7SegDigitDec(contador[1],1);Segments_SetBrightness(Bright[1], 1);
                    Segments_Write7SegDigitDec(contador[2],2);Segments_SetBrightness(Bright[1], 2);
                    Segments_Write7SegDigitDec(contador[3],3);Segments_SetBrightness(Bright[1], 3);
                    band4seg=0;
                    Posicion=1;
                    configuration=0;
                }
                if(bandseg>=vel)Segundos++;
                    Segments_SetBrightness(Bright[0],0);
                    T_tiempo= contador[1]*60 + contador[2]*10 +contador[3];
                    T_tiempo-= Segundos;
                    Segments_Write7SegDigitDec(T_tiempo/60,1);Segments_SetBrightness(Bright[1], 1);
                    Segments_Write7SegDigitDec((T_tiempo%60)/10,2);Segments_SetBrightness(Bright[1], 2);
                    Segments_Write7SegDigitDec(T_tiempo%10,3);Segments_SetBrightness(Bright[1], 3);     
                    
                    if(SW_buzz_Read()==1){
                        if(contador[3]%5==0)Buzzer_Write(1);
                        else Buzzer_Write(0);
                    }else Buzzer_Write(0);
                    
                    if(contador[1]==0 && contador[2]==0 && contador[3]==0){
                        configuration=0;
                        Band_Final=1;}
                    
                    if(Band_Final==1){
                        LEDS_Write(1);
                        Buzzer_Write(0);
                        Segments_SetBrightness(Bright[1],0);
                        Segments_Write7SegNumberDec(0,0,4,Segments_ZERO_PAD);
                    }

                    if(configuration==0 && Band_Final==0){
                        band4seg=0;
                        cnt_noconf=0;
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
                            mili2segundos=0;
                            }
                        if(cnt_noconf>200)cnt_noconf=0;
                    }                
                }
        }
        if(SW_Read()==1 && configuration==0){
            Segments_Write7SegDigitDec(0,0);Segments_Write7SegDigitDec(0,1);Segments_Write7SegDigitDec(0,2);Segments_Write7SegDigitDec(0,3);
            if(band_2mili){
            band_2mili=0;
            mili2segundos++;
                if(mili2segundos==100){
                    Segments_SetBrightness(Bright[1], 1);
                    Segments_SetBrightness(Bright[1], 2);
                    Segments_SetBrightness(Bright[1], 3);
                    Segments_SetBrightness(Bright[1], 0);
            }
                if(mili2segundos==200){
                    Segments_SetBrightness(Bright[0], 1);
                    Segments_SetBrightness(Bright[0], 2);
                    Segments_SetBrightness(Bright[0], 3);
                    Segments_SetBrightness(Bright[0], 0);
                    mili2segundos=0; 
            }
        }
        }
    if(SW_vel_Read()==1)vel=100;
    else vel=500;
            }          
//-----------------------------------------------------------------------------------------------                
            
}
CY_ISR(IRQ_ISR){
    band_pulse=1;
}
CY_ISR(Timer_ISR){
    band_2mili=1; 
}
    

/* [] END OF FILE */
