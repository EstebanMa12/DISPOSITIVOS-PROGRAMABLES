/*******************************************************************************
* File Name: BUZZER_ON.h  
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

#if !defined(CY_PINS_BUZZER_ON_H) /* Pins BUZZER_ON_H */
#define CY_PINS_BUZZER_ON_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BUZZER_ON_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BUZZER_ON__PORT == 15 && ((BUZZER_ON__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BUZZER_ON_Write(uint8 value);
void    BUZZER_ON_SetDriveMode(uint8 mode);
uint8   BUZZER_ON_ReadDataReg(void);
uint8   BUZZER_ON_Read(void);
void    BUZZER_ON_SetInterruptMode(uint16 position, uint16 mode);
uint8   BUZZER_ON_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BUZZER_ON_SetDriveMode() function.
     *  @{
     */
        #define BUZZER_ON_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BUZZER_ON_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BUZZER_ON_DM_RES_UP          PIN_DM_RES_UP
        #define BUZZER_ON_DM_RES_DWN         PIN_DM_RES_DWN
        #define BUZZER_ON_DM_OD_LO           PIN_DM_OD_LO
        #define BUZZER_ON_DM_OD_HI           PIN_DM_OD_HI
        #define BUZZER_ON_DM_STRONG          PIN_DM_STRONG
        #define BUZZER_ON_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BUZZER_ON_MASK               BUZZER_ON__MASK
#define BUZZER_ON_SHIFT              BUZZER_ON__SHIFT
#define BUZZER_ON_WIDTH              1u

/* Interrupt constants */
#if defined(BUZZER_ON__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BUZZER_ON_SetInterruptMode() function.
     *  @{
     */
        #define BUZZER_ON_INTR_NONE      (uint16)(0x0000u)
        #define BUZZER_ON_INTR_RISING    (uint16)(0x0001u)
        #define BUZZER_ON_INTR_FALLING   (uint16)(0x0002u)
        #define BUZZER_ON_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BUZZER_ON_INTR_MASK      (0x01u) 
#endif /* (BUZZER_ON__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BUZZER_ON_PS                     (* (reg8 *) BUZZER_ON__PS)
/* Data Register */
#define BUZZER_ON_DR                     (* (reg8 *) BUZZER_ON__DR)
/* Port Number */
#define BUZZER_ON_PRT_NUM                (* (reg8 *) BUZZER_ON__PRT) 
/* Connect to Analog Globals */                                                  
#define BUZZER_ON_AG                     (* (reg8 *) BUZZER_ON__AG)                       
/* Analog MUX bux enable */
#define BUZZER_ON_AMUX                   (* (reg8 *) BUZZER_ON__AMUX) 
/* Bidirectional Enable */                                                        
#define BUZZER_ON_BIE                    (* (reg8 *) BUZZER_ON__BIE)
/* Bit-mask for Aliased Register Access */
#define BUZZER_ON_BIT_MASK               (* (reg8 *) BUZZER_ON__BIT_MASK)
/* Bypass Enable */
#define BUZZER_ON_BYP                    (* (reg8 *) BUZZER_ON__BYP)
/* Port wide control signals */                                                   
#define BUZZER_ON_CTL                    (* (reg8 *) BUZZER_ON__CTL)
/* Drive Modes */
#define BUZZER_ON_DM0                    (* (reg8 *) BUZZER_ON__DM0) 
#define BUZZER_ON_DM1                    (* (reg8 *) BUZZER_ON__DM1)
#define BUZZER_ON_DM2                    (* (reg8 *) BUZZER_ON__DM2) 
/* Input Buffer Disable Override */
#define BUZZER_ON_INP_DIS                (* (reg8 *) BUZZER_ON__INP_DIS)
/* LCD Common or Segment Drive */
#define BUZZER_ON_LCD_COM_SEG            (* (reg8 *) BUZZER_ON__LCD_COM_SEG)
/* Enable Segment LCD */
#define BUZZER_ON_LCD_EN                 (* (reg8 *) BUZZER_ON__LCD_EN)
/* Slew Rate Control */
#define BUZZER_ON_SLW                    (* (reg8 *) BUZZER_ON__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BUZZER_ON_PRTDSI__CAPS_SEL       (* (reg8 *) BUZZER_ON__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BUZZER_ON_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BUZZER_ON__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BUZZER_ON_PRTDSI__OE_SEL0        (* (reg8 *) BUZZER_ON__PRTDSI__OE_SEL0) 
#define BUZZER_ON_PRTDSI__OE_SEL1        (* (reg8 *) BUZZER_ON__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BUZZER_ON_PRTDSI__OUT_SEL0       (* (reg8 *) BUZZER_ON__PRTDSI__OUT_SEL0) 
#define BUZZER_ON_PRTDSI__OUT_SEL1       (* (reg8 *) BUZZER_ON__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BUZZER_ON_PRTDSI__SYNC_OUT       (* (reg8 *) BUZZER_ON__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BUZZER_ON__SIO_CFG)
    #define BUZZER_ON_SIO_HYST_EN        (* (reg8 *) BUZZER_ON__SIO_HYST_EN)
    #define BUZZER_ON_SIO_REG_HIFREQ     (* (reg8 *) BUZZER_ON__SIO_REG_HIFREQ)
    #define BUZZER_ON_SIO_CFG            (* (reg8 *) BUZZER_ON__SIO_CFG)
    #define BUZZER_ON_SIO_DIFF           (* (reg8 *) BUZZER_ON__SIO_DIFF)
#endif /* (BUZZER_ON__SIO_CFG) */

/* Interrupt Registers */
#if defined(BUZZER_ON__INTSTAT)
    #define BUZZER_ON_INTSTAT            (* (reg8 *) BUZZER_ON__INTSTAT)
    #define BUZZER_ON_SNAP               (* (reg8 *) BUZZER_ON__SNAP)
    
	#define BUZZER_ON_0_INTTYPE_REG 		(* (reg8 *) BUZZER_ON__0__INTTYPE)
#endif /* (BUZZER_ON__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BUZZER_ON_H */


/* [] END OF FILE */
