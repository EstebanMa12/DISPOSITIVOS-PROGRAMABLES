/*******************************************************************************
* File Name: Segments.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values and API definition for the
*  LED Driver Component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_LED_Driver_Segments_H)
#define CY_LED_Driver_Segments_H


/***************************************
*   Conditional Compilation Parameters
***************************************/
#define Segments_BRIGHTNESS_EN                (1u)
#define Segments_COM_DRIVE                    (1u)
#define Segments_SEG_DRIVE                    (1u)
#define Segments_NUM_COM                      (4u)
#define Segments_NUM_SEG                      (7u)
#define Segments_TWO_NUM_COM                  ((uint8)((uint8)Segments_NUM_COM << 1u))

/* Error message for removed commons control register through optimization */
#ifdef Segments_Com_Driver_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the commons terminal to be connected to pins.
#endif /* Segments_Com_Driver_Sync_ctrl_reg__REMOVED */

/* Error message for removed segments control registers through optimization */
#if defined Segments_Seg_Driver_L_Sync_ctrl_reg__REMOVED || \
defined Segments_Seg_Driver_M_Sync_ctrl_reg__REMOVED || \
defined Segments_Seg_Driver_H_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the segments terminal to be connected to pins.
#endif /* Segments_Seg_Driver_L_Sync_ctrl_reg__REMOVED */


/***************************************
*   Header files
***************************************/
#include <Segments_Com_Driver.h>
#include <Segments_Seg_Driver_L.h>
#if (Segments_NUM_SEG > 8u)
    #include <Segments_Seg_Driver_M.h>
#endif /* Segment_M control register */
#if (Segments_NUM_SEG > 16u)
    #include <Segments_Seg_Driver_H.h>
#endif /* Segment_H control register */

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#ifndef CY_PSOC5A
    #error Component LED_Driver_v1_10 requires cy_boot v3.0 or later
#endif /* CY_PSOC5A */


/***************************************
*        Structure Definitions
***************************************/
typedef struct
{
    uint8 ledEnableState;
    /* Backup the segment values when going to sleep. (Stop() clears the buffers) */
    uint8 segLBackup[Segments_NUM_COM];
    #if (Segments_NUM_SEG > 8u) 
        uint8 segMBackup[Segments_NUM_COM];
    #endif /* (Segments_NUM_SEG > 8u) */
    #if (Segments_NUM_SEG > 16u) 
        uint8 segHBackup[Segments_NUM_COM];
    #endif /* (Segments_NUM_SEG > 16u) */
}Segments_backupStruct;


/***************************************
*        Function Prototypes
***************************************/
void Segments_Init(void)                       ;
void Segments_Enable(void)                     ;
void Segments_Start(void)                      ;
void Segments_Stop(void)                       ;
void Segments_SetDisplayRAM(uint8 value, uint8 position) 
                                                        ;
void Segments_SetRC(uint8 row, uint8 column)    ;
void Segments_ClearRC(uint8 row, uint8 column)  ;
void Segments_ToggleRC(uint8 row, uint8 column) ;
uint8 Segments_GetRC(uint8 row, uint8 column)   ;
void Segments_ClearDisplay(uint8 position)      ;
void Segments_ClearDisplayAll(void)             ;
void Segments_Write7SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Segments_Write7SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Segments_WriteString7Seg(char8 const character[], uint8 position)
                                                        ;
void Segments_PutChar7Seg(char8 character , uint8 position)
                                                        ;
void Segments_Write7SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void Segments_Write7SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void Segments_Write14SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Segments_Write14SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Segments_WriteString14Seg(char8 const character[], uint8 position)
                                                        ;
void Segments_PutChar14Seg(char8 character , uint8 position)
                                                        ;
void Segments_Write14SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void Segments_Write14SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void Segments_Write16SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Segments_Write16SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void Segments_WriteString16Seg(char8 const character[], uint8 position)
                                                        ;
void Segments_PutChar16Seg(char8 character , uint8 position)
                                                        ;
void Segments_Write16SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void Segments_Write16SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void Segments_PutDecimalPoint(uint8 dp, uint8 position)
                                                        ;
uint8 Segments_GetDecimalPoint(uint8 position)  ;
uint8 Segments_EncodeNumber7Seg(uint8 number)   ;
uint8 Segments_EncodeChar7Seg(char8 input)      ;
uint16 Segments_EncodeNumber14Seg(uint8 number) ;
uint16 Segments_EncodeChar14Seg(char8 input)    ;
uint16 Segments_EncodeNumber16Seg(uint8 number) ;
uint16 Segments_EncodeChar16Seg(char8 input)    ;
void Segments_SetBrightness(uint8 bright, uint8 position)
                                                        ;
uint8 Segments_GetBrightness(uint8 position)    ;
void Segments_Sleep(void)                       ;
void Segments_Wakeup(void)                      ;


/***************************************
*           Global Variables
***************************************/
extern uint8 Segments_initVar;
extern uint8 Segments_enableVar;

/* Buffers used to hold the display(segment) values to be transferred to the control registers */
extern uint8 Segments_segLBuffer[Segments_NUM_COM];
#if (Segments_NUM_SEG > 8u) 
    extern uint8 Segments_segMBuffer[Segments_NUM_COM];
#endif /* (Segments_NUM_SEG > 8u) */
#if (Segments_NUM_SEG > 16u) 
    extern uint8 Segments_segHBuffer[Segments_NUM_COM];
#endif /* (Segments_NUM_SEG > 16u) */


/***************************************
*           API Constants
***************************************/

/* Related to conditional compilation */
#define Segments_HIGH                   (0x01u)
#define Segments_ENABLED                (0x01u)

/* Number of DMA channels */
#if (Segments_BRIGHTNESS_EN == Segments_ENABLED)
    #define Segments_CHANNEL_LIMIT      (0x03u)
#else
    #define Segments_CHANNEL_LIMIT      (0x02u)
#endif /* (Segments_BRIGHTNESS_EN == Segments_ENABLED) */

/* Defines related to sign extraction for number displays */
#define Segments_SIGNED                 (0x01u)
#define Segments_UNSIGNED               (0x00u)
#define Segments_ZERO_NEG               ((int32)0x00000000)

/* Brightness control defines */
#define Segments_INIT_BRIGHT            (0xFFu)

/* Segment display defines */
#if(Segments_SEG_DRIVE == Segments_HIGH)
    #define Segments_CLEAR              (0x00u)
    #define Segments_CLEAR_16           ((uint16)0x0000u)
    #define Segments_ZERO_7CHAR         (0x3Fu)
    #define Segments_ZERO_14CHAR        ((uint16)0x243Fu)
    #define Segments_ZERO_16CHAR        ((uint16)0x90FFu)
#else
    #define Segments_CLEAR              (0xFFu)
    #define Segments_CLEAR_16           ((uint16)0xFFFFu)
    #define Segments_ZERO_7CHAR         (0xC0u)
    #define Segments_ZERO_14CHAR        ((uint16)0xDBC0u)
    #define Segments_ZERO_16CHAR        ((uint16)0x6F00u)
#endif /* (Segments_SEG_DRIVE == Segments_HIGH) */

/* Shifts and 4-bit operation mask */
#define Segments_SHIFT_NIBBLE           (0x04u)
#define Segments_NIBBLE_MASK            (0x0Fu)
#define Segments_SHIFT_BYTE             (0x08u)

/* ASCII table access defines */
#define Segments_SEG_ASCII_OFFSET       (0x02u)
#define Segments_SEG_ASCII_LIM_HI       (0x08u)
#define Segments_SEG_ASCII_LIM_LO       (0x01u)

/* Decimal point defines */
#define Segments_DEC_POINT              (0x07u)
#define Segments_DEC_POINT_MASK         (0x01u)
#if(Segments_SEG_DRIVE == Segments_HIGH)
    #define Segments_DEC_POINT_VALUE    (0x80u)
#else
    #define Segments_DEC_POINT_VALUE    (0x7Fu)
#endif /* (Segments_SEG_DRIVE == Segments_HIGH) */

/* 7-seg position to register mapping defines */
#define Segments_SEG_REG_LOW            (0x00u)
#define Segments_SEG_REG_MID            (0x01u)
#define Segments_SEG_REG_HIGH           (0x02u)

/* Segment display alignment defines */
#define Segments_RIGHT_ALIGN            (0x00u)
#define Segments_LEFT_ALIGN             (0x01u)
#define Segments_ZERO_PAD               (0x02u)


/***************************************
*           Registers
***************************************/
#define Segments_CONTROL_REG_BASE       (CYDEV_PERIPH_BASE)
#define Segments_SRAM_BASE              (CYDEV_SRAM_BASE)

#define Segments_COM_CONTROL_PTR        (Segments_Com_Driver_Control_PTR)
#define Segments_SEG_L_CONTROL_PTR      (Segments_Seg_Driver_L_Control_PTR)

#if (Segments_NUM_SEG > 8u)
    #define Segments_SEG_M_CONTROL_PTR  (Segments_Seg_Driver_M_Control_PTR)
#endif /* (Segments_NUM_SEG > 8u) */
#if (Segments_NUM_SEG > 16u)
    #define Segments_SEG_H_CONTROL_PTR  (Segments_Seg_Driver_H_Control_PTR)
#endif /* (Segments_NUM_SEG > 16u) */


/***************************************
*           UDB PWM Registers
***************************************/
/* Control register */
#define Segments_CONTROL_REG            (*(reg8 *) Segments_bLED_PWM_CtlReg__CONTROL_REG)
#define Segments_CONTROL_PTR            ( (reg8 *) Segments_bLED_PWM_CtlReg__CONTROL_REG)

/* Counter register */
#define Segments_COUNTER_REG            (*(reg8 *) Segments_bLED_PWM_PwmDP_u0__A1_REG)
#define Segments_COUNTER_PTR            ((reg8 *) Segments_bLED_PWM_PwmDP_u0__A1_REG)
/* Compare value buffer */
#define Segments_COMPARE_REG            (*(reg8 *) Segments_bLED_PWM_PwmDP_u0__D0_REG)
#define Segments_COMPARE_PTR            ((reg8 *) Segments_bLED_PWM_PwmDP_u0__D0_REG)


/***************************************
*          Register Constants
***************************************/
/* Control Register Enable/Disable. Also use for Segments_enableVar */
#define Segments_CTRL_ENABLE            (0x01u)
#define Segments_CTRL_DISABLE           (0x00u)

#endif /* CY_LED_Driver_Segments_H Header File */


/* [] END OF FILE */
