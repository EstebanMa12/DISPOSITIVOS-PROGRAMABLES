#include "project.h"


CY_ISR_PROTO(IRQ_ISR);
CY_ISR_PROTO(ENTER_ISR);
CY_ISR_PROTO(Timer_ISR);
CY_ISR_PROTO(Salida_ISR);
uint8 CompararClave(const uint8 *Ingresada,const uint8 *Original);
uint8 titileoletras(uint8 ubicaletra);
uint8 Estado=0;
uint8 ordenLED;
uint8 Binarios[10]={0b00000000,0b10000001,0b01000010,0b10000001,0b00100100,0b11000011,0b00011000,0b11100111,0b00000000,0b11111111};
char Matrix[6][10]={"   A","  A "," A  ","A   "," A  ","  A ",};
uint8 u3=0;
uint8 u5=0;
uint8 PosiA=3;
uint8 u4=0;
uint16 u6=0;
uint8 u7=0;
uint8 u8=0;
uint8 bandetar=0;
uint8 banderaa=0;
uint8 bandesali=0;
uint8 u10=0;

uint8 BandeTare=0;
uint8 ClaveIngresada[4];
uint8 ClaveOriginal[4]={4,1,2,5};
uint8 Contador[4]={0,0,0,0};
//------------------------------------
uint8 Bright[2]={0,255};
uint8 BandeBrillo=0;
uint8 Banderita=0;
uint8 Banderota=0;
uint16 conta=0;
uint16 contad=0;
uint16 contador=0;
uint8 doblepres=0;
uint8 TitileoSingular=0;
uint8 TitileoSingularDespla=0;
uint8 u=0;
uint8 uu=0;
//--------------------------------------
uint8 Posicion=1;
uint8 bandClave=0;


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Interrupt_StartEx(IRQ_ISR);
    Enter_StartEx(ENTER_ISR);
    Timer_StartEx(Timer_ISR);
    Salida_StartEx(Salida_ISR);
    Segments_Start();
    Contador_Start();
    Segments_Write7SegNumberDec(0,0,4,Segments_ZERO_PAD);

    for(;;)
    {
        if(Posicion==4){
            Posicion=1;
            TitileoSingular=0;
            TitileoSingularDespla=0;
            u=0;
//            
//            bandClave= CompararClave(ClaveIngresada,ClaveOriginal);
//            if(bandClave==1){
//                for(u10=0;u10<6;u10++){
//                 Segments_WriteString7Seg("    ",0);
//                Segments_SetBrightness(0,3);
//                Segments_Write7SegDigitHex(12,3);
//                 CyDelay(250);
//                Segments_SetBrightness(255,3);
//                Segments_Write7SegDigitHex(12,3);
//                CyDelay(250);
//                }
//            }
//                  
//            else{
//                for(u10=0;u10<14;u10++){
//                 Segments_WriteString7Seg("    ",0);
//                Segments_SetBrightness(0,3);
//                Segments_WriteString7Seg("   F",0);
//                 CyDelay(250);
//                Segments_SetBrightness(255,3);
//                Segments_WriteString7Seg("   F",0);
//                CyDelay(250);
//                }
//            }
//            
            for(uint8 i=0;i<4;i++){
                Contador[i]=0;
            }
            Segments_Write7SegNumberDec(0,0,4,Segments_ZERO_PAD);
        }
        // Titileo(todos los seg) inicial del 7seg
        if(SW_Read()==0){
        if(Banderita){
            Banderita=0;
            conta++;
            contad++;
            contador++;
            if(conta==125){
                conta=0;
//                if(TitileoSingular==0 && TitileoSingularDespla==0){                    
//                    for( u=0;u<4;u++){
//                    Segments_SetBrightness(Bright[BandeBrillo],u);
//                    }
//                }
                //----------------------------------------------------
//                if( TitileoSingular!=0 || TitileoSingularDespla!=0){

                 for( uu=1;uu<4;uu++){
                   Segments_SetBrightness(Bright[0],0);
                    Segments_SetBrightness(Bright[1],uu);
                    Segments_SetBrightness(Bright[BandeBrillo],Posicion);
                }
//                }
                BandeBrillo++;
                if(BandeBrillo>1){
                    BandeBrillo=0;
                }
                
            }
           }
        
        

//            if(doblepres==2 && contador<190){
//                Banderota=1;
//                contador=0;
//                doblepres=0;
//                Posicion++;
//            }
//            else{
//                Banderota=0;
//            }
        
//            if(contador==190){
//            contador=0;
//            doblepres=0;
//            }
            
//            if(Contador[Posicion]==0){
//                TitileoSingular=0;
//            }
            if(contad==2000){
//                doblepres=0;
            contad=0;
            Posicion++;
            contador=0;
        }
            
        if(TitileoSingular==1 && doblepres==1){
              contador=0;
            TitileoSingular=0;
    }
        }

            
            
        
//            //SALIDA
//        if(bandesali==1){
//            bandClave=0;
//            Segments_Write7SegNumberDec(0,0,4,Segments_ZERO_PAD);
//            bandesali=0;
//            TitileoSingular=0;
//            TitileoSingularDespla=0;
//            for(Posicion=0;Posicion<4;Posicion++){
//            Contador[Posicion]=0;
//            }
//            Posicion=0;
//        }
            
    }          
                     
    }


CY_ISR(IRQ_ISR){
    contad=0;
    TitileoSingular=1;
    doblepres++;
//    if(doblepres==1){
//    contador=0;
//    }
    if(doblepres==3){
            doblepres=0;
//        contador=0;
        }
    if(doblepres==2 && contador<190){
//    Banderota=1;
//    contador=0;
//    doblepres=0;
    Posicion++;
//    TitileoSingular=0;
}
    else if(doblepres==1 && contador>190){
//    else{
//    doblepres=0;
//    contador=0;
    Contador[Posicion]++;
    if(Contador[Posicion]==10 && Posicion==3)Contador[Posicion]=0;
    if(Contador[Posicion]==6 && Posicion==2)Contador[Posicion]=0;
    if(Contador[Posicion]==3 && Posicion==1)Contador[Posicion]=0;
    Segments_Write7SegDigitDec(Contador[Posicion],Posicion);
    }
//         if(contador>190){
//            contador=0;
//        }
 
//    contador=0;
}
CY_ISR(ENTER_ISR){
    TitileoSingularDespla=1;
    ClaveIngresada[Posicion]=Contador[Posicion];
    Posicion++;
}
CY_ISR(Timer_ISR){
    Banderita=1; 
}
CY_ISR(Salida_ISR){
    bandesali=1; 
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
