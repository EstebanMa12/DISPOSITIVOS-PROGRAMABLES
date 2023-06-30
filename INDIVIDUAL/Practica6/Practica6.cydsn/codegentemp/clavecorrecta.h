/*******************************************************************************
* File Name: clavecorrecta.h  
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

#if !defined(CY_PINS_clavecorrecta_H) /* Pins clavecorrecta_H */
#define CY_PINS_clavecorrecta_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "clavecorrecta_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 clavecorrecta__PORT == 15 && ((clavecorrecta__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    clavecorrecta_Write(uint8 value);
void    clavecorrecta_SetDriveMode(uint8 mode);
uint8   clavecorrecta_ReadDataReg(void);
uint8   clavecorrecta_Read(void);
void    clavecorrecta_SetInterruptMode(uint16 position, uint16 mode);
uint8   clavecorrecta_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the clavecorrecta_SetDriveMode() function.
     *  @{
     */
        #define clavecorrecta_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define clavecorrecta_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define clavecorrecta_DM_RES_UP          PIN_DM_RES_UP
        #define clavecorrecta_DM_RES_DWN         PIN_DM_RES_DWN
        #define clavecorrecta_DM_OD_LO           PIN_DM_OD_LO
        #define clavecorrecta_DM_OD_HI           PIN_DM_OD_HI
        #define clavecorrecta_DM_STRONG          PIN_DM_STRONG
        #define clavecorrecta_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define clavecorrecta_MASK               clavecorrecta__MASK
#define clavecorrecta_SHIFT              clavecorrecta__SHIFT
#define clavecorrecta_WIDTH              1u

/* Interrupt constants */
#if defined(clavecorrecta__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in clavecorrecta_SetInterruptMode() function.
     *  @{
     */
        #define clavecorrecta_INTR_NONE      (uint16)(0x0000u)
        #define clavecorrecta_INTR_RISING    (uint16)(0x0001u)
        #define clavecorrecta_INTR_FALLING   (uint16)(0x0002u)
        #define clavecorrecta_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define clavecorrecta_INTR_MASK      (0x01u) 
#endif /* (clavecorrecta__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define clavecorrecta_PS                     (* (reg8 *) clavecorrecta__PS)
/* Data Register */
#define clavecorrecta_DR                     (* (reg8 *) clavecorrecta__DR)
/* Port Number */
#define clavecorrecta_PRT_NUM                (* (reg8 *) clavecorrecta__PRT) 
/* Connect to Analog Globals */                                                  
#define clavecorrecta_AG                     (* (reg8 *) clavecorrecta__AG)                       
/* Analog MUX bux enable */
#define clavecorrecta_AMUX                   (* (reg8 *) clavecorrecta__AMUX) 
/* Bidirectional Enable */                                                        
#define clavecorrecta_BIE                    (* (reg8 *) clavecorrecta__BIE)
/* Bit-mask for Aliased Register Access */
#define clavecorrecta_BIT_MASK               (* (reg8 *) clavecorrecta__BIT_MASK)
/* Bypass Enable */
#define clavecorrecta_BYP                    (* (reg8 *) clavecorrecta__BYP)
/* Port wide control signals */                                                   
#define clavecorrecta_CTL                    (* (reg8 *) clavecorrecta__CTL)
/* Drive Modes */
#define clavecorrecta_DM0                    (* (reg8 *) clavecorrecta__DM0) 
#define clavecorrecta_DM1                    (* (reg8 *) clavecorrecta__DM1)
#define clavecorrecta_DM2                    (* (reg8 *) clavecorrecta__DM2) 
/* Input Buffer Disable Override */
#define clavecorrecta_INP_DIS                (* (reg8 *) clavecorrecta__INP_DIS)
/* LCD Common or Segment Drive */
#define clavecorrecta_LCD_COM_SEG            (* (reg8 *) clavecorrecta__LCD_COM_SEG)
/* Enable Segment LCD */
#define clavecorrecta_LCD_EN                 (* (reg8 *) clavecorrecta__LCD_EN)
/* Slew Rate Control */
#define clavecorrecta_SLW                    (* (reg8 *) clavecorrecta__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define clavecorrecta_PRTDSI__CAPS_SEL       (* (reg8 *) clavecorrecta__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define clavecorrecta_PRTDSI__DBL_SYNC_IN    (* (reg8 *) clavecorrecta__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define clavecorrecta_PRTDSI__OE_SEL0        (* (reg8 *) clavecorrecta__PRTDSI__OE_SEL0) 
#define clavecorrecta_PRTDSI__OE_SEL1        (* (reg8 *) clavecorrecta__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define clavecorrecta_PRTDSI__OUT_SEL0       (* (reg8 *) clavecorrecta__PRTDSI__OUT_SEL0) 
#define clavecorrecta_PRTDSI__OUT_SEL1       (* (reg8 *) clavecorrecta__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define clavecorrecta_PRTDSI__SYNC_OUT       (* (reg8 *) clavecorrecta__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(clavecorrecta__SIO_CFG)
    #define clavecorrecta_SIO_HYST_EN        (* (reg8 *) clavecorrecta__SIO_HYST_EN)
    #define clavecorrecta_SIO_REG_HIFREQ     (* (reg8 *) clavecorrecta__SIO_REG_HIFREQ)
    #define clavecorrecta_SIO_CFG            (* (reg8 *) clavecorrecta__SIO_CFG)
    #define clavecorrecta_SIO_DIFF           (* (reg8 *) clavecorrecta__SIO_DIFF)
#endif /* (clavecorrecta__SIO_CFG) */

/* Interrupt Registers */
#if defined(clavecorrecta__INTSTAT)
    #define clavecorrecta_INTSTAT            (* (reg8 *) clavecorrecta__INTSTAT)
    #define clavecorrecta_SNAP               (* (reg8 *) clavecorrecta__SNAP)
    
	#define clavecorrecta_0_INTTYPE_REG 		(* (reg8 *) clavecorrecta__0__INTTYPE)
#endif /* (clavecorrecta__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_clavecorrecta_H */


/* [] END OF FILE */
