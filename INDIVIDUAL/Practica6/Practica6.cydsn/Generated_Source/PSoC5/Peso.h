/*******************************************************************************
* File Name: Peso.h  
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

#if !defined(CY_PINS_Peso_H) /* Pins Peso_H */
#define CY_PINS_Peso_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Peso_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Peso__PORT == 15 && ((Peso__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Peso_Write(uint8 value);
void    Peso_SetDriveMode(uint8 mode);
uint8   Peso_ReadDataReg(void);
uint8   Peso_Read(void);
void    Peso_SetInterruptMode(uint16 position, uint16 mode);
uint8   Peso_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Peso_SetDriveMode() function.
     *  @{
     */
        #define Peso_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Peso_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Peso_DM_RES_UP          PIN_DM_RES_UP
        #define Peso_DM_RES_DWN         PIN_DM_RES_DWN
        #define Peso_DM_OD_LO           PIN_DM_OD_LO
        #define Peso_DM_OD_HI           PIN_DM_OD_HI
        #define Peso_DM_STRONG          PIN_DM_STRONG
        #define Peso_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Peso_MASK               Peso__MASK
#define Peso_SHIFT              Peso__SHIFT
#define Peso_WIDTH              1u

/* Interrupt constants */
#if defined(Peso__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Peso_SetInterruptMode() function.
     *  @{
     */
        #define Peso_INTR_NONE      (uint16)(0x0000u)
        #define Peso_INTR_RISING    (uint16)(0x0001u)
        #define Peso_INTR_FALLING   (uint16)(0x0002u)
        #define Peso_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Peso_INTR_MASK      (0x01u) 
#endif /* (Peso__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Peso_PS                     (* (reg8 *) Peso__PS)
/* Data Register */
#define Peso_DR                     (* (reg8 *) Peso__DR)
/* Port Number */
#define Peso_PRT_NUM                (* (reg8 *) Peso__PRT) 
/* Connect to Analog Globals */                                                  
#define Peso_AG                     (* (reg8 *) Peso__AG)                       
/* Analog MUX bux enable */
#define Peso_AMUX                   (* (reg8 *) Peso__AMUX) 
/* Bidirectional Enable */                                                        
#define Peso_BIE                    (* (reg8 *) Peso__BIE)
/* Bit-mask for Aliased Register Access */
#define Peso_BIT_MASK               (* (reg8 *) Peso__BIT_MASK)
/* Bypass Enable */
#define Peso_BYP                    (* (reg8 *) Peso__BYP)
/* Port wide control signals */                                                   
#define Peso_CTL                    (* (reg8 *) Peso__CTL)
/* Drive Modes */
#define Peso_DM0                    (* (reg8 *) Peso__DM0) 
#define Peso_DM1                    (* (reg8 *) Peso__DM1)
#define Peso_DM2                    (* (reg8 *) Peso__DM2) 
/* Input Buffer Disable Override */
#define Peso_INP_DIS                (* (reg8 *) Peso__INP_DIS)
/* LCD Common or Segment Drive */
#define Peso_LCD_COM_SEG            (* (reg8 *) Peso__LCD_COM_SEG)
/* Enable Segment LCD */
#define Peso_LCD_EN                 (* (reg8 *) Peso__LCD_EN)
/* Slew Rate Control */
#define Peso_SLW                    (* (reg8 *) Peso__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Peso_PRTDSI__CAPS_SEL       (* (reg8 *) Peso__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Peso_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Peso__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Peso_PRTDSI__OE_SEL0        (* (reg8 *) Peso__PRTDSI__OE_SEL0) 
#define Peso_PRTDSI__OE_SEL1        (* (reg8 *) Peso__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Peso_PRTDSI__OUT_SEL0       (* (reg8 *) Peso__PRTDSI__OUT_SEL0) 
#define Peso_PRTDSI__OUT_SEL1       (* (reg8 *) Peso__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Peso_PRTDSI__SYNC_OUT       (* (reg8 *) Peso__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Peso__SIO_CFG)
    #define Peso_SIO_HYST_EN        (* (reg8 *) Peso__SIO_HYST_EN)
    #define Peso_SIO_REG_HIFREQ     (* (reg8 *) Peso__SIO_REG_HIFREQ)
    #define Peso_SIO_CFG            (* (reg8 *) Peso__SIO_CFG)
    #define Peso_SIO_DIFF           (* (reg8 *) Peso__SIO_DIFF)
#endif /* (Peso__SIO_CFG) */

/* Interrupt Registers */
#if defined(Peso__INTSTAT)
    #define Peso_INTSTAT            (* (reg8 *) Peso__INTSTAT)
    #define Peso_SNAP               (* (reg8 *) Peso__SNAP)
    
	#define Peso_0_INTTYPE_REG 		(* (reg8 *) Peso__0__INTTYPE)
#endif /* (Peso__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Peso_H */


/* [] END OF FILE */
