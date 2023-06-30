/*******************************************************************************
* File Name: Boton2.h  
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

#if !defined(CY_PINS_Boton2_H) /* Pins Boton2_H */
#define CY_PINS_Boton2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Boton2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Boton2__PORT == 15 && ((Boton2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Boton2_Write(uint8 value);
void    Boton2_SetDriveMode(uint8 mode);
uint8   Boton2_ReadDataReg(void);
uint8   Boton2_Read(void);
void    Boton2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Boton2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Boton2_SetDriveMode() function.
     *  @{
     */
        #define Boton2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Boton2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Boton2_DM_RES_UP          PIN_DM_RES_UP
        #define Boton2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Boton2_DM_OD_LO           PIN_DM_OD_LO
        #define Boton2_DM_OD_HI           PIN_DM_OD_HI
        #define Boton2_DM_STRONG          PIN_DM_STRONG
        #define Boton2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Boton2_MASK               Boton2__MASK
#define Boton2_SHIFT              Boton2__SHIFT
#define Boton2_WIDTH              1u

/* Interrupt constants */
#if defined(Boton2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Boton2_SetInterruptMode() function.
     *  @{
     */
        #define Boton2_INTR_NONE      (uint16)(0x0000u)
        #define Boton2_INTR_RISING    (uint16)(0x0001u)
        #define Boton2_INTR_FALLING   (uint16)(0x0002u)
        #define Boton2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Boton2_INTR_MASK      (0x01u) 
#endif /* (Boton2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Boton2_PS                     (* (reg8 *) Boton2__PS)
/* Data Register */
#define Boton2_DR                     (* (reg8 *) Boton2__DR)
/* Port Number */
#define Boton2_PRT_NUM                (* (reg8 *) Boton2__PRT) 
/* Connect to Analog Globals */                                                  
#define Boton2_AG                     (* (reg8 *) Boton2__AG)                       
/* Analog MUX bux enable */
#define Boton2_AMUX                   (* (reg8 *) Boton2__AMUX) 
/* Bidirectional Enable */                                                        
#define Boton2_BIE                    (* (reg8 *) Boton2__BIE)
/* Bit-mask for Aliased Register Access */
#define Boton2_BIT_MASK               (* (reg8 *) Boton2__BIT_MASK)
/* Bypass Enable */
#define Boton2_BYP                    (* (reg8 *) Boton2__BYP)
/* Port wide control signals */                                                   
#define Boton2_CTL                    (* (reg8 *) Boton2__CTL)
/* Drive Modes */
#define Boton2_DM0                    (* (reg8 *) Boton2__DM0) 
#define Boton2_DM1                    (* (reg8 *) Boton2__DM1)
#define Boton2_DM2                    (* (reg8 *) Boton2__DM2) 
/* Input Buffer Disable Override */
#define Boton2_INP_DIS                (* (reg8 *) Boton2__INP_DIS)
/* LCD Common or Segment Drive */
#define Boton2_LCD_COM_SEG            (* (reg8 *) Boton2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Boton2_LCD_EN                 (* (reg8 *) Boton2__LCD_EN)
/* Slew Rate Control */
#define Boton2_SLW                    (* (reg8 *) Boton2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Boton2_PRTDSI__CAPS_SEL       (* (reg8 *) Boton2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Boton2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Boton2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Boton2_PRTDSI__OE_SEL0        (* (reg8 *) Boton2__PRTDSI__OE_SEL0) 
#define Boton2_PRTDSI__OE_SEL1        (* (reg8 *) Boton2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Boton2_PRTDSI__OUT_SEL0       (* (reg8 *) Boton2__PRTDSI__OUT_SEL0) 
#define Boton2_PRTDSI__OUT_SEL1       (* (reg8 *) Boton2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Boton2_PRTDSI__SYNC_OUT       (* (reg8 *) Boton2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Boton2__SIO_CFG)
    #define Boton2_SIO_HYST_EN        (* (reg8 *) Boton2__SIO_HYST_EN)
    #define Boton2_SIO_REG_HIFREQ     (* (reg8 *) Boton2__SIO_REG_HIFREQ)
    #define Boton2_SIO_CFG            (* (reg8 *) Boton2__SIO_CFG)
    #define Boton2_SIO_DIFF           (* (reg8 *) Boton2__SIO_DIFF)
#endif /* (Boton2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Boton2__INTSTAT)
    #define Boton2_INTSTAT            (* (reg8 *) Boton2__INTSTAT)
    #define Boton2_SNAP               (* (reg8 *) Boton2__SNAP)
    
	#define Boton2_0_INTTYPE_REG 		(* (reg8 *) Boton2__0__INTTYPE)
#endif /* (Boton2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Boton2_H */


/* [] END OF FILE */
