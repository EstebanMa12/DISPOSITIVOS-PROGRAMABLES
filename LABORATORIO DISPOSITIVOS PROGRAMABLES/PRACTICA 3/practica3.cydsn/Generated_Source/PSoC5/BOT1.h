/*******************************************************************************
* File Name: BOT1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BOT1_H) /* Pins BOT1_H */
#define CY_PINS_BOT1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BOT1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BOT1__PORT == 15 && ((BOT1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BOT1_Write(uint8 value);
void    BOT1_SetDriveMode(uint8 mode);
uint8   BOT1_ReadDataReg(void);
uint8   BOT1_Read(void);
void    BOT1_SetInterruptMode(uint16 position, uint16 mode);
uint8   BOT1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BOT1_SetDriveMode() function.
     *  @{
     */
        #define BOT1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BOT1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BOT1_DM_RES_UP          PIN_DM_RES_UP
        #define BOT1_DM_RES_DWN         PIN_DM_RES_DWN
        #define BOT1_DM_OD_LO           PIN_DM_OD_LO
        #define BOT1_DM_OD_HI           PIN_DM_OD_HI
        #define BOT1_DM_STRONG          PIN_DM_STRONG
        #define BOT1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BOT1_MASK               BOT1__MASK
#define BOT1_SHIFT              BOT1__SHIFT
#define BOT1_WIDTH              1u

/* Interrupt constants */
#if defined(BOT1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BOT1_SetInterruptMode() function.
     *  @{
     */
        #define BOT1_INTR_NONE      (uint16)(0x0000u)
        #define BOT1_INTR_RISING    (uint16)(0x0001u)
        #define BOT1_INTR_FALLING   (uint16)(0x0002u)
        #define BOT1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BOT1_INTR_MASK      (0x01u) 
#endif /* (BOT1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BOT1_PS                     (* (reg8 *) BOT1__PS)
/* Data Register */
#define BOT1_DR                     (* (reg8 *) BOT1__DR)
/* Port Number */
#define BOT1_PRT_NUM                (* (reg8 *) BOT1__PRT) 
/* Connect to Analog Globals */                                                  
#define BOT1_AG                     (* (reg8 *) BOT1__AG)                       
/* Analog MUX bux enable */
#define BOT1_AMUX                   (* (reg8 *) BOT1__AMUX) 
/* Bidirectional Enable */                                                        
#define BOT1_BIE                    (* (reg8 *) BOT1__BIE)
/* Bit-mask for Aliased Register Access */
#define BOT1_BIT_MASK               (* (reg8 *) BOT1__BIT_MASK)
/* Bypass Enable */
#define BOT1_BYP                    (* (reg8 *) BOT1__BYP)
/* Port wide control signals */                                                   
#define BOT1_CTL                    (* (reg8 *) BOT1__CTL)
/* Drive Modes */
#define BOT1_DM0                    (* (reg8 *) BOT1__DM0) 
#define BOT1_DM1                    (* (reg8 *) BOT1__DM1)
#define BOT1_DM2                    (* (reg8 *) BOT1__DM2) 
/* Input Buffer Disable Override */
#define BOT1_INP_DIS                (* (reg8 *) BOT1__INP_DIS)
/* LCD Common or Segment Drive */
#define BOT1_LCD_COM_SEG            (* (reg8 *) BOT1__LCD_COM_SEG)
/* Enable Segment LCD */
#define BOT1_LCD_EN                 (* (reg8 *) BOT1__LCD_EN)
/* Slew Rate Control */
#define BOT1_SLW                    (* (reg8 *) BOT1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BOT1_PRTDSI__CAPS_SEL       (* (reg8 *) BOT1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BOT1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BOT1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BOT1_PRTDSI__OE_SEL0        (* (reg8 *) BOT1__PRTDSI__OE_SEL0) 
#define BOT1_PRTDSI__OE_SEL1        (* (reg8 *) BOT1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BOT1_PRTDSI__OUT_SEL0       (* (reg8 *) BOT1__PRTDSI__OUT_SEL0) 
#define BOT1_PRTDSI__OUT_SEL1       (* (reg8 *) BOT1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BOT1_PRTDSI__SYNC_OUT       (* (reg8 *) BOT1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BOT1__SIO_CFG)
    #define BOT1_SIO_HYST_EN        (* (reg8 *) BOT1__SIO_HYST_EN)
    #define BOT1_SIO_REG_HIFREQ     (* (reg8 *) BOT1__SIO_REG_HIFREQ)
    #define BOT1_SIO_CFG            (* (reg8 *) BOT1__SIO_CFG)
    #define BOT1_SIO_DIFF           (* (reg8 *) BOT1__SIO_DIFF)
#endif /* (BOT1__SIO_CFG) */

/* Interrupt Registers */
#if defined(BOT1__INTSTAT)
    #define BOT1_INTSTAT            (* (reg8 *) BOT1__INTSTAT)
    #define BOT1_SNAP               (* (reg8 *) BOT1__SNAP)
    
	#define BOT1_0_INTTYPE_REG 		(* (reg8 *) BOT1__0__INTTYPE)
#endif /* (BOT1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BOT1_H */


/* [] END OF FILE */
