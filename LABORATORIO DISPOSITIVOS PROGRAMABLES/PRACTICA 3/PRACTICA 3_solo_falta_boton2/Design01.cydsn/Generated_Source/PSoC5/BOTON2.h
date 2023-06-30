/*******************************************************************************
* File Name: BOTON2.h  
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

#if !defined(CY_PINS_BOTON2_H) /* Pins BOTON2_H */
#define CY_PINS_BOTON2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BOTON2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BOTON2__PORT == 15 && ((BOTON2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BOTON2_Write(uint8 value);
void    BOTON2_SetDriveMode(uint8 mode);
uint8   BOTON2_ReadDataReg(void);
uint8   BOTON2_Read(void);
void    BOTON2_SetInterruptMode(uint16 position, uint16 mode);
uint8   BOTON2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BOTON2_SetDriveMode() function.
     *  @{
     */
        #define BOTON2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BOTON2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BOTON2_DM_RES_UP          PIN_DM_RES_UP
        #define BOTON2_DM_RES_DWN         PIN_DM_RES_DWN
        #define BOTON2_DM_OD_LO           PIN_DM_OD_LO
        #define BOTON2_DM_OD_HI           PIN_DM_OD_HI
        #define BOTON2_DM_STRONG          PIN_DM_STRONG
        #define BOTON2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BOTON2_MASK               BOTON2__MASK
#define BOTON2_SHIFT              BOTON2__SHIFT
#define BOTON2_WIDTH              1u

/* Interrupt constants */
#if defined(BOTON2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BOTON2_SetInterruptMode() function.
     *  @{
     */
        #define BOTON2_INTR_NONE      (uint16)(0x0000u)
        #define BOTON2_INTR_RISING    (uint16)(0x0001u)
        #define BOTON2_INTR_FALLING   (uint16)(0x0002u)
        #define BOTON2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BOTON2_INTR_MASK      (0x01u) 
#endif /* (BOTON2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BOTON2_PS                     (* (reg8 *) BOTON2__PS)
/* Data Register */
#define BOTON2_DR                     (* (reg8 *) BOTON2__DR)
/* Port Number */
#define BOTON2_PRT_NUM                (* (reg8 *) BOTON2__PRT) 
/* Connect to Analog Globals */                                                  
#define BOTON2_AG                     (* (reg8 *) BOTON2__AG)                       
/* Analog MUX bux enable */
#define BOTON2_AMUX                   (* (reg8 *) BOTON2__AMUX) 
/* Bidirectional Enable */                                                        
#define BOTON2_BIE                    (* (reg8 *) BOTON2__BIE)
/* Bit-mask for Aliased Register Access */
#define BOTON2_BIT_MASK               (* (reg8 *) BOTON2__BIT_MASK)
/* Bypass Enable */
#define BOTON2_BYP                    (* (reg8 *) BOTON2__BYP)
/* Port wide control signals */                                                   
#define BOTON2_CTL                    (* (reg8 *) BOTON2__CTL)
/* Drive Modes */
#define BOTON2_DM0                    (* (reg8 *) BOTON2__DM0) 
#define BOTON2_DM1                    (* (reg8 *) BOTON2__DM1)
#define BOTON2_DM2                    (* (reg8 *) BOTON2__DM2) 
/* Input Buffer Disable Override */
#define BOTON2_INP_DIS                (* (reg8 *) BOTON2__INP_DIS)
/* LCD Common or Segment Drive */
#define BOTON2_LCD_COM_SEG            (* (reg8 *) BOTON2__LCD_COM_SEG)
/* Enable Segment LCD */
#define BOTON2_LCD_EN                 (* (reg8 *) BOTON2__LCD_EN)
/* Slew Rate Control */
#define BOTON2_SLW                    (* (reg8 *) BOTON2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BOTON2_PRTDSI__CAPS_SEL       (* (reg8 *) BOTON2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BOTON2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BOTON2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BOTON2_PRTDSI__OE_SEL0        (* (reg8 *) BOTON2__PRTDSI__OE_SEL0) 
#define BOTON2_PRTDSI__OE_SEL1        (* (reg8 *) BOTON2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BOTON2_PRTDSI__OUT_SEL0       (* (reg8 *) BOTON2__PRTDSI__OUT_SEL0) 
#define BOTON2_PRTDSI__OUT_SEL1       (* (reg8 *) BOTON2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BOTON2_PRTDSI__SYNC_OUT       (* (reg8 *) BOTON2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BOTON2__SIO_CFG)
    #define BOTON2_SIO_HYST_EN        (* (reg8 *) BOTON2__SIO_HYST_EN)
    #define BOTON2_SIO_REG_HIFREQ     (* (reg8 *) BOTON2__SIO_REG_HIFREQ)
    #define BOTON2_SIO_CFG            (* (reg8 *) BOTON2__SIO_CFG)
    #define BOTON2_SIO_DIFF           (* (reg8 *) BOTON2__SIO_DIFF)
#endif /* (BOTON2__SIO_CFG) */

/* Interrupt Registers */
#if defined(BOTON2__INTSTAT)
    #define BOTON2_INTSTAT            (* (reg8 *) BOTON2__INTSTAT)
    #define BOTON2_SNAP               (* (reg8 *) BOTON2__SNAP)
    
	#define BOTON2_0_INTTYPE_REG 		(* (reg8 *) BOTON2__0__INTTYPE)
#endif /* (BOTON2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BOTON2_H */


/* [] END OF FILE */
