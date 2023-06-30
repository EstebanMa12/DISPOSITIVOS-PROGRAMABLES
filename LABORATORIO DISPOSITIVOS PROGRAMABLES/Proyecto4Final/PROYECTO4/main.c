
// LUIS MIGUEL RAMIREZ RUEDA
// KORAIMA TORRES DIAZ
// ESTEBAN MAYA
#include "project.h"


CY_ISR_PROTO(IRQ_ISR);
CY_ISR_PROTO(ENTER_ISR);
CY_ISR_PROTO(Timer_ISR);
CY_ISR_PROTO(Salida_ISR);
uint8 CompararClave(const uint8 *Ingresada,const uint8 *Original);
uint8 titileoletras(uint8 ubicaletra);
uint8 Estado=0;
uint8 ordenLED;
uint8 Binarios[10]={0b00000000,0b10000001,0b01000010,0b10000001,0b00100100,0b11000011,0b00011000,0b11100111,0b00000000,0b11111111};// Vector que contiene la secuencia de LEDS
char Matrix[6][10]={"   A","  A "," A  ","A   "," A  ","  A ",}; // Matriz de configuraciones del 7 segmentos

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
uint8 ClaveIngresada[4];// Inicializa un vector en donde se almacena la clave 
uint8 ClaveOriginal[4]={4,1,2,5};// Clave Original 
uint8 Contador[4]={0,0,0,0};
//------------------------------------
uint8 Bright[2]={0,255};// Minimo de brillo y máximo
uint8 BandeBrillo=0;
uint8 Banderita=0;
uint16 conta=0;
uint8 TitileoSingular=0;
uint8 TitileoSingularDespla=0;
uint8 u=0;
uint8 uu=0;
//--------------------------------------
uint8 Posicion=0;
uint8 bandClave=0;


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Interrupt_StartEx(IRQ_ISR);
    Enter_StartEx(ENTER_ISR);
    Timer_StartEx(Timer_ISR);
    Salida_StartEx(Salida_ISR);// Inicialización de todas las interrupciones
    Segments_Start();
    Contador_Start();
    Segments_Write7SegNumberDec(0,0,4,Segments_ZERO_PAD);// El 7 segmentos inicializa todo en 0

    for(;;)
    {
        if(Posicion==4){

            Posicion=0;
            TitileoSingular=0;
            TitileoSingularDespla=0;
            u=0;
            
            bandClave= CompararClave(ClaveIngresada,ClaveOriginal);
            if(bandClave==1){// Si la clave es correcta procede a realizar el titileo
                // El titileo es de 250Hz
                   // El siguiente bucle es el encargado de sobreescribir el 7segmentos en C y realizar el titileo por 3 segundos 
                for(u10=0;u10<6;u10++){
                    Segments_WriteString7Seg("    ",0);// Inicializa el 7 segmentos vacion
                    Segments_SetBrightness(0,3);// Brillo en 0
                    Segments_Write7SegDigitHex(12,3);// Escribe la C en el 7segmentos
                    CyDelay(250);
                    Segments_SetBrightness(255,3);
                    Segments_Write7SegDigitHex(12,3);
                    CyDelay(250);
                }
                
               
            }
                  
            else{// Si la clave es falsa entonces ingresa al siguiente bucle, el cual sobreescribe el 7 segmentos con una F y realiza el por 7 segundos 
                for(u10=0;u10<14;u10++){
                 Segments_WriteString7Seg("    ",0);
                Segments_SetBrightness(0,3);
                Segments_WriteString7Seg("   F",0);
                 CyDelay(250);
                Segments_SetBrightness(255,3);
                Segments_WriteString7Seg("   F",0);
                CyDelay(250);
                }
            }
//            
            for(uint8 i=0;i<4;i++){
                Contador[i]=0;
            }
            Segments_Write7SegNumberDec(0,0,4,Segments_ZERO_PAD);
        }
        // Titileo(todos los seg) inicial del 7seg
        if(Banderita){
            Banderita=0;
            conta++;
            if(conta==125){
                conta=0;
                if(TitileoSingular==0 && TitileoSingularDespla==0){    // El 7 segmentos titila mientras no se seleccione un segmento                 
                    for( u=0;u<4;u++){
                    Segments_SetBrightness(Bright[BandeBrillo],u);
                    }
                }
                //----------------------------------------------------
                if( TitileoSingular!=0 || TitileoSingularDespla!=0){ // Apenas se ingrese la clave solo va a titilar el segmento seleccionado

                 for( uu=0;uu<4;uu++){
                    Segments_SetBrightness(Bright[1],uu);
                    Segments_SetBrightness(Bright[BandeBrillo],Posicion);
                }
                }
                BandeBrillo++;
                if(BandeBrillo>1){
                    BandeBrillo=0;
                }
                
            }
           }
        
        
        
        
        // TAREA 0
        if(bandClave==1 && SW_Read()==0){
            for( u7=0;u7<4;u7++){
                    Segments_SetBrightness(255,u7);
                    }
            banderaa=0;
            u6=0;

                    Segments_WriteString7Seg(Matrix[u3++],0);// Recorre la matriz de A
                    if (u3==6){
                        u3=0;
                    }
                    LEDS_Write(Binarios[u5++]);// Recorre la matriz del LED 
                        if (u5==10){
                            u5=0;
                        }
                        CyDelay(666);
        }
        
        // TAREA 1
            if(bandClave==1 && SW_Read()==1){//
                u3=0;
                u5=0;
                LEDS_Write(Binarios[0b00000000]);// Los LED se apagan 
                
                if(banderaa==0){
                    Segments_WriteString7Seg("12",0);// Escribe 12 los dos primeros segmentos
                    Segments_SetBrightness(255-u6,0);// Resta a 255 un 51 cada vez hasta llegar a 0 
                    Segments_SetBrightness(255-u6,1);

                    // El 51 sale de la relacion de 255/5 
                    
                    Segments_WriteString7Seg("12",2);// Escribe 12 los dos ultimos segmentso 
                     Segments_SetBrightness(0+u6,2);// Suma 51 a 0 cada vez 
                    Segments_SetBrightness(0+u6,3);
                         u6+=51;

                        if(u6==255){
                        u6=0;
                        banderaa=1;
                        }
                }
                if(banderaa==1){// Este ciclo hace lo contrario que el anterior, a los que se les sumo se les resta y a los que se les restó se les suma
                        
                     Segments_WriteString7Seg("12",0);
                     Segments_SetBrightness(255-u6,2);
                    Segments_SetBrightness(255-u6,3);

                    
                    Segments_WriteString7Seg("12",2);
                     Segments_SetBrightness(0+u6,0);
                    Segments_SetBrightness(0+u6,1);
                    
                         u6+=51;
                    if(u6==255){
                        u6=0;
                        banderaa=0;
                    }
                }
                CyDelay(400);
            }
            //SALIDA
        if(bandesali==1){ // Si se presiona el boton de salida se vuelve al estado inicial
            bandClave=0;
            LEDS_Write(Binarios[0b00000000]);
            Segments_Write7SegNumberDec(0,0,4,Segments_ZERO_PAD);
            bandesali=0;
            TitileoSingular=0;
            TitileoSingularDespla=0;
            for(Posicion=0;Posicion<4;Posicion++){
            Contador[Posicion]=0;
            }
            Posicion=0;
        }
            
    }          
                     
    }


CY_ISR(IRQ_ISR){// Determina que en cada segmento se vaya de 0 a 9 
    TitileoSingular=1;// 
    Contador[Posicion]++;
    if(Contador[Posicion]==10)Contador[Posicion]=0;
    Segments_Write7SegDigitDec(Contador[Posicion],Posicion);
}
CY_ISR(ENTER_ISR){// Interrupción para desplazar la posición en el 7 segmentos
    TitileoSingularDespla=1;
    ClaveIngresada[Posicion]=Contador[Posicion];
    Posicion++;
}
CY_ISR(Timer_ISR){
    Banderita=1; 
}
CY_ISR(Salida_ISR){// Salida del sistema
    bandesali=1; 
}

//Función para comparar clave original con la ingresada 
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
    
    // SOLUCION INICIAL PARA MOVIMIENTO DE A EN SEGMENTOS (FUNCIONA PERO MAS COMPLEJO)
    
//    while(PosiA>=0 && PosiA<4){
//    if(bandetar==0){
//    for( u4=0;u4<4;u4++){
//    if(u4!=PosiA){
//    Segments_SetBrightness(Bright[0],u4);
//    Segments_Write7SegDigitHex(10,PosiA);
//        }
//    Segments_SetBrightness(Bright[1],PosiA);
//    }
//    CyDelay(666);
//    PosiA--;
//    }
//    if(PosiA==0){
//        bandetar=1;}
//    if(bandetar==1){
//        for( u4=0;u4<4;u4++){
//        if(u4!=PosiA){
//        Segments_SetBrightness(Bright[0],u4);
//        Segments_Write7SegDigitHex(10,PosiA);
//            }
//        Segments_SetBrightness(Bright[1],PosiA);
//        }
//        CyDelay(666);
//        PosiA++;
//    }
//        if(PosiA==3){
//        bandetar=0;}
//    }
//}

