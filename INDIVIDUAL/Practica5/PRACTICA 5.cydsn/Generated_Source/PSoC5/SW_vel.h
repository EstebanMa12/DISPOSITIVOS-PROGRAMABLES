/*******************************************************************************
* File Name: SW_vel.h  
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

#if !defined(CY_PINS_SW_vel_H) /* Pins SW_vel_H */
#define CY_PINS_SW_vel_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SW_vel_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SW_vel__PORT == 15 && ((SW_vel__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SW_vel_Write(uint8 value);
void    SW_vel_SetDriveMode(uint8 mode);
uint8   SW_vel_ReadDataReg(void);
uint8   SW_vel_Read(void);
void    SW_vel_SetInterruptMode(uint16 position, uint16 mode);
uint8   SW_vel_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SW_vel_SetDriveMode() function.
     *  @{
     */
        #define SW_vel_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SW_vel_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SW_vel_DM_RES_UP          PIN_DM_RES_UP
        #define SW_vel_DM_RES_DWN         PIN_DM_RES_DWN
        #define SW_vel_DM_OD_LO           PIN_DM_OD_LO
        #define SW_vel_DM_OD_HI           PIN_DM_OD_HI
        #define SW_vel_DM_STRONG          PIN_DM_STRONG
        #define SW_vel_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SW_vel_MASK               SW_vel__MASK
#define SW_vel_SHIFT              SW_vel__SHIFT
#define SW_vel_WIDTH              1u

/* Interrupt constants */
#if defined(SW_vel__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SW_vel_SetInterruptMode() function.
     *  @{
     */
        #define SW_vel_INTR_NONE      (uint16)(0x0000u)
        #define SW_vel_INTR_RISING    (uint16)(0x0001u)
        #define SW_vel_INTR_FALLING   (uint16)(0x0002u)
        #define SW_vel_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SW_vel_INTR_MASK      (0x01u) 
#endif /* (SW_vel__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SW_vel_PS                     (* (reg8 *) SW_vel__PS)
/* Data Register */
#define SW_vel_DR                     (* (reg8 *) SW_vel__DR)
/* Port Number */
#define SW_vel_PRT_NUM                (* (reg8 *) SW_vel__PRT) 
/* Connect to Analog Globals */                                                  
#define SW_vel_AG                     (* (reg8 *) SW_vel__AG)                       
/* Analog MUX bux enable */
#define SW_vel_AMUX                   (* (reg8 *) SW_vel__AMUX) 
/* Bidirectional Enable */                                                        
#define SW_vel_BIE                    (* (reg8 *) SW_vel__BIE)
/* Bit-mask for Aliased Register Access */
#define SW_vel_BIT_MASK               (* (reg8 *) SW_vel__BIT_MASK)
/* Bypass Enable */
#define SW_vel_BYP                    (* (reg8 *) SW_vel__BYP)
/* Port wide control signals */                                                   
#define SW_vel_CTL                    (* (reg8 *) SW_vel__CTL)
/* Drive Modes */
#define SW_vel_DM0                    (* (reg8 *) SW_vel__DM0) 
#define SW_vel_DM1                    (* (reg8 *) SW_vel__DM1)
#define SW_vel_DM2                    (* (reg8 *) SW_vel__DM2) 
/* Input Buffer Disable Override */
#define SW_vel_INP_DIS                (* (reg8 *) SW_vel__INP_DIS)
/* LCD Common or Segment Drive */
#define SW_vel_LCD_COM_SEG            (* (reg8 *) SW_vel__LCD_COM_SEG)
/* Enable Segment LCD */
#define SW_vel_LCD_EN                 (* (reg8 *) SW_vel__LCD_EN)
/* Slew Rate Control */
#define SW_vel_SLW                    (* (reg8 *) SW_vel__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SW_vel_PRTDSI__CAPS_SEL       (* (reg8 *) SW_vel__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SW_vel_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SW_vel__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SW_vel_PRTDSI__OE_SEL0        (* (reg8 *) SW_vel__PRTDSI__OE_SEL0) 
#define SW_vel_PRTDSI__OE_SEL1        (* (reg8 *) SW_vel__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SW_vel_PRTDSI__OUT_SEL0       (* (reg8 *) SW_vel__PRTDSI__OUT_SEL0) 
#define SW_vel_PRTDSI__OUT_SEL1       (* (reg8 *) SW_vel__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SW_vel_PRTDSI__SYNC_OUT       (* (reg8 *) SW_vel__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SW_vel__SIO_CFG)
    #define SW_vel_SIO_HYST_EN        (* (reg8 *) SW_vel__SIO_HYST_EN)
    #define SW_vel_SIO_REG_HIFREQ     (* (reg8 *) SW_vel__SIO_REG_HIFREQ)
    #define SW_vel_SIO_CFG            (* (reg8 *) SW_vel__SIO_CFG)
    #define SW_vel_SIO_DIFF           (* (reg8 *) SW_vel__SIO_DIFF)
#endif /* (SW_vel__SIO_CFG) */

/* Interrupt Registers */
#if defined(SW_vel__INTSTAT)
    #define SW_vel_INTSTAT            (* (reg8 *) SW_vel__INTSTAT)
    #define SW_vel_SNAP               (* (reg8 *) SW_vel__SNAP)
    
	#define SW_vel_0_INTTYPE_REG 		(* (reg8 *) SW_vel__0__INTTYPE)
#endif /* (SW_vel__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SW_vel_H */


/* [] END OF FILE */
