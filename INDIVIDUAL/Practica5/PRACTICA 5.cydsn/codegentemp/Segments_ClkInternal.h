/*******************************************************************************
* File Name: Segments_ClkInternal.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Segments_ClkInternal_H)
#define CY_CLOCK_Segments_ClkInternal_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Segments_ClkInternal_Start(void) ;
void Segments_ClkInternal_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Segments_ClkInternal_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Segments_ClkInternal_StandbyPower(uint8 state) ;
void Segments_ClkInternal_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Segments_ClkInternal_GetDividerRegister(void) ;
void Segments_ClkInternal_SetModeRegister(uint8 modeBitMask) ;
void Segments_ClkInternal_ClearModeRegister(uint8 modeBitMask) ;
uint8 Segments_ClkInternal_GetModeRegister(void) ;
void Segments_ClkInternal_SetSourceRegister(uint8 clkSource) ;
uint8 Segments_ClkInternal_GetSourceRegister(void) ;
#if defined(Segments_ClkInternal__CFG3)
void Segments_ClkInternal_SetPhaseRegister(uint8 clkPhase) ;
uint8 Segments_ClkInternal_GetPhaseRegister(void) ;
#endif /* defined(Segments_ClkInternal__CFG3) */

#define Segments_ClkInternal_Enable()                       Segments_ClkInternal_Start()
#define Segments_ClkInternal_Disable()                      Segments_ClkInternal_Stop()
#define Segments_ClkInternal_SetDivider(clkDivider)         Segments_ClkInternal_SetDividerRegister(clkDivider, 1u)
#define Segments_ClkInternal_SetDividerValue(clkDivider)    Segments_ClkInternal_SetDividerRegister((clkDivider) - 1u, 1u)
#define Segments_ClkInternal_SetMode(clkMode)               Segments_ClkInternal_SetModeRegister(clkMode)
#define Segments_ClkInternal_SetSource(clkSource)           Segments_ClkInternal_SetSourceRegister(clkSource)
#if defined(Segments_ClkInternal__CFG3)
#define Segments_ClkInternal_SetPhase(clkPhase)             Segments_ClkInternal_SetPhaseRegister(clkPhase)
#define Segments_ClkInternal_SetPhaseValue(clkPhase)        Segments_ClkInternal_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Segments_ClkInternal__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Segments_ClkInternal_CLKEN              (* (reg8 *) Segments_ClkInternal__PM_ACT_CFG)
#define Segments_ClkInternal_CLKEN_PTR          ((reg8 *) Segments_ClkInternal__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Segments_ClkInternal_CLKSTBY            (* (reg8 *) Segments_ClkInternal__PM_STBY_CFG)
#define Segments_ClkInternal_CLKSTBY_PTR        ((reg8 *) Segments_ClkInternal__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Segments_ClkInternal_DIV_LSB            (* (reg8 *) Segments_ClkInternal__CFG0)
#define Segments_ClkInternal_DIV_LSB_PTR        ((reg8 *) Segments_ClkInternal__CFG0)
#define Segments_ClkInternal_DIV_PTR            ((reg16 *) Segments_ClkInternal__CFG0)

/* Clock MSB divider configuration register. */
#define Segments_ClkInternal_DIV_MSB            (* (reg8 *) Segments_ClkInternal__CFG1)
#define Segments_ClkInternal_DIV_MSB_PTR        ((reg8 *) Segments_ClkInternal__CFG1)

/* Mode and source configuration register */
#define Segments_ClkInternal_MOD_SRC            (* (reg8 *) Segments_ClkInternal__CFG2)
#define Segments_ClkInternal_MOD_SRC_PTR        ((reg8 *) Segments_ClkInternal__CFG2)

#if defined(Segments_ClkInternal__CFG3)
/* Analog clock phase configuration register */
#define Segments_ClkInternal_PHASE              (* (reg8 *) Segments_ClkInternal__CFG3)
#define Segments_ClkInternal_PHASE_PTR          ((reg8 *) Segments_ClkInternal__CFG3)
#endif /* defined(Segments_ClkInternal__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Segments_ClkInternal_CLKEN_MASK         Segments_ClkInternal__PM_ACT_MSK
#define Segments_ClkInternal_CLKSTBY_MASK       Segments_ClkInternal__PM_STBY_MSK

/* CFG2 field masks */
#define Segments_ClkInternal_SRC_SEL_MSK        Segments_ClkInternal__CFG2_SRC_SEL_MASK
#define Segments_ClkInternal_MODE_MASK          (~(Segments_ClkInternal_SRC_SEL_MSK))

#if defined(Segments_ClkInternal__CFG3)
/* CFG3 phase mask */
#define Segments_ClkInternal_PHASE_MASK         Segments_ClkInternal__CFG3_PHASE_DLY_MASK
#endif /* defined(Segments_ClkInternal__CFG3) */

#endif /* CY_CLOCK_Segments_ClkInternal_H */


/* [] END OF FILE */
