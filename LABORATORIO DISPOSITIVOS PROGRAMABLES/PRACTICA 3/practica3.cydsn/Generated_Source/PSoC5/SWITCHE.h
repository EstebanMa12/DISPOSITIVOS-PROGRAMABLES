/*******************************************************************************
* File Name: SWITCHE.h  
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

#if !defined(CY_PINS_SWITCHE_H) /* Pins SWITCHE_H */
#define CY_PINS_SWITCHE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SWITCHE_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SWITCHE__PORT == 15 && ((SWITCHE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SWITCHE_Write(uint8 value);
void    SWITCHE_SetDriveMode(uint8 mode);
uint8   SWITCHE_ReadDataReg(void);
uint8   SWITCHE_Read(void);
void    SWITCHE_SetInterruptMode(uint16 position, uint16 mode);
uint8   SWITCHE_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SWITCHE_SetDriveMode() function.
     *  @{
     */
        #define SWITCHE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SWITCHE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SWITCHE_DM_RES_UP          PIN_DM_RES_UP
        #define SWITCHE_DM_RES_DWN         PIN_DM_RES_DWN
        #define SWITCHE_DM_OD_LO           PIN_DM_OD_LO
        #define SWITCHE_DM_OD_HI           PIN_DM_OD_HI
        #define SWITCHE_DM_STRONG          PIN_DM_STRONG
        #define SWITCHE_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SWITCHE_MASK               SWITCHE__MASK
#define SWITCHE_SHIFT              SWITCHE__SHIFT
#define SWITCHE_WIDTH              1u

/* Interrupt constants */
#if defined(SWITCHE__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SWITCHE_SetInterruptMode() function.
     *  @{
     */
        #define SWITCHE_INTR_NONE      (uint16)(0x0000u)
        #define SWITCHE_INTR_RISING    (uint16)(0x0001u)
        #define SWITCHE_INTR_FALLING   (uint16)(0x0002u)
        #define SWITCHE_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SWITCHE_INTR_MASK      (0x01u) 
#endif /* (SWITCHE__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SWITCHE_PS                     (* (reg8 *) SWITCHE__PS)
/* Data Register */
#define SWITCHE_DR                     (* (reg8 *) SWITCHE__DR)
/* Port Number */
#define SWITCHE_PRT_NUM                (* (reg8 *) SWITCHE__PRT) 
/* Connect to Analog Globals */                                                  
#define SWITCHE_AG                     (* (reg8 *) SWITCHE__AG)                       
/* Analog MUX bux enable */
#define SWITCHE_AMUX                   (* (reg8 *) SWITCHE__AMUX) 
/* Bidirectional Enable */                                                        
#define SWITCHE_BIE                    (* (reg8 *) SWITCHE__BIE)
/* Bit-mask for Aliased Register Access */
#define SWITCHE_BIT_MASK               (* (reg8 *) SWITCHE__BIT_MASK)
/* Bypass Enable */
#define SWITCHE_BYP                    (* (reg8 *) SWITCHE__BYP)
/* Port wide control signals */                                                   
#define SWITCHE_CTL                    (* (reg8 *) SWITCHE__CTL)
/* Drive Modes */
#define SWITCHE_DM0                    (* (reg8 *) SWITCHE__DM0) 
#define SWITCHE_DM1                    (* (reg8 *) SWITCHE__DM1)
#define SWITCHE_DM2                    (* (reg8 *) SWITCHE__DM2) 
/* Input Buffer Disable Override */
#define SWITCHE_INP_DIS                (* (reg8 *) SWITCHE__INP_DIS)
/* LCD Common or Segment Drive */
#define SWITCHE_LCD_COM_SEG            (* (reg8 *) SWITCHE__LCD_COM_SEG)
/* Enable Segment LCD */
#define SWITCHE_LCD_EN                 (* (reg8 *) SWITCHE__LCD_EN)
/* Slew Rate Control */
#define SWITCHE_SLW                    (* (reg8 *) SWITCHE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SWITCHE_PRTDSI__CAPS_SEL       (* (reg8 *) SWITCHE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SWITCHE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SWITCHE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SWITCHE_PRTDSI__OE_SEL0        (* (reg8 *) SWITCHE__PRTDSI__OE_SEL0) 
#define SWITCHE_PRTDSI__OE_SEL1        (* (reg8 *) SWITCHE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SWITCHE_PRTDSI__OUT_SEL0       (* (reg8 *) SWITCHE__PRTDSI__OUT_SEL0) 
#define SWITCHE_PRTDSI__OUT_SEL1       (* (reg8 *) SWITCHE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SWITCHE_PRTDSI__SYNC_OUT       (* (reg8 *) SWITCHE__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SWITCHE__SIO_CFG)
    #define SWITCHE_SIO_HYST_EN        (* (reg8 *) SWITCHE__SIO_HYST_EN)
    #define SWITCHE_SIO_REG_HIFREQ     (* (reg8 *) SWITCHE__SIO_REG_HIFREQ)
    #define SWITCHE_SIO_CFG            (* (reg8 *) SWITCHE__SIO_CFG)
    #define SWITCHE_SIO_DIFF           (* (reg8 *) SWITCHE__SIO_DIFF)
#endif /* (SWITCHE__SIO_CFG) */

/* Interrupt Registers */
#if defined(SWITCHE__INTSTAT)
    #define SWITCHE_INTSTAT            (* (reg8 *) SWITCHE__INTSTAT)
    #define SWITCHE_SNAP               (* (reg8 *) SWITCHE__SNAP)
    
	#define SWITCHE_0_INTTYPE_REG 		(* (reg8 *) SWITCHE__0__INTTYPE)
#endif /* (SWITCHE__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SWITCHE_H */


/* [] END OF FILE */
