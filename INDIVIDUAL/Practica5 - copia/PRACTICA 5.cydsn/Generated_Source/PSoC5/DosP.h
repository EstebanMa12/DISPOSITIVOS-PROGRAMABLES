/*******************************************************************************
* File Name: DosP.h  
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

#if !defined(CY_PINS_DosP_H) /* Pins DosP_H */
#define CY_PINS_DosP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DosP_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DosP__PORT == 15 && ((DosP__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DosP_Write(uint8 value);
void    DosP_SetDriveMode(uint8 mode);
uint8   DosP_ReadDataReg(void);
uint8   DosP_Read(void);
void    DosP_SetInterruptMode(uint16 position, uint16 mode);
uint8   DosP_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DosP_SetDriveMode() function.
     *  @{
     */
        #define DosP_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DosP_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DosP_DM_RES_UP          PIN_DM_RES_UP
        #define DosP_DM_RES_DWN         PIN_DM_RES_DWN
        #define DosP_DM_OD_LO           PIN_DM_OD_LO
        #define DosP_DM_OD_HI           PIN_DM_OD_HI
        #define DosP_DM_STRONG          PIN_DM_STRONG
        #define DosP_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DosP_MASK               DosP__MASK
#define DosP_SHIFT              DosP__SHIFT
#define DosP_WIDTH              1u

/* Interrupt constants */
#if defined(DosP__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DosP_SetInterruptMode() function.
     *  @{
     */
        #define DosP_INTR_NONE      (uint16)(0x0000u)
        #define DosP_INTR_RISING    (uint16)(0x0001u)
        #define DosP_INTR_FALLING   (uint16)(0x0002u)
        #define DosP_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DosP_INTR_MASK      (0x01u) 
#endif /* (DosP__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DosP_PS                     (* (reg8 *) DosP__PS)
/* Data Register */
#define DosP_DR                     (* (reg8 *) DosP__DR)
/* Port Number */
#define DosP_PRT_NUM                (* (reg8 *) DosP__PRT) 
/* Connect to Analog Globals */                                                  
#define DosP_AG                     (* (reg8 *) DosP__AG)                       
/* Analog MUX bux enable */
#define DosP_AMUX                   (* (reg8 *) DosP__AMUX) 
/* Bidirectional Enable */                                                        
#define DosP_BIE                    (* (reg8 *) DosP__BIE)
/* Bit-mask for Aliased Register Access */
#define DosP_BIT_MASK               (* (reg8 *) DosP__BIT_MASK)
/* Bypass Enable */
#define DosP_BYP                    (* (reg8 *) DosP__BYP)
/* Port wide control signals */                                                   
#define DosP_CTL                    (* (reg8 *) DosP__CTL)
/* Drive Modes */
#define DosP_DM0                    (* (reg8 *) DosP__DM0) 
#define DosP_DM1                    (* (reg8 *) DosP__DM1)
#define DosP_DM2                    (* (reg8 *) DosP__DM2) 
/* Input Buffer Disable Override */
#define DosP_INP_DIS                (* (reg8 *) DosP__INP_DIS)
/* LCD Common or Segment Drive */
#define DosP_LCD_COM_SEG            (* (reg8 *) DosP__LCD_COM_SEG)
/* Enable Segment LCD */
#define DosP_LCD_EN                 (* (reg8 *) DosP__LCD_EN)
/* Slew Rate Control */
#define DosP_SLW                    (* (reg8 *) DosP__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DosP_PRTDSI__CAPS_SEL       (* (reg8 *) DosP__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DosP_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DosP__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DosP_PRTDSI__OE_SEL0        (* (reg8 *) DosP__PRTDSI__OE_SEL0) 
#define DosP_PRTDSI__OE_SEL1        (* (reg8 *) DosP__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DosP_PRTDSI__OUT_SEL0       (* (reg8 *) DosP__PRTDSI__OUT_SEL0) 
#define DosP_PRTDSI__OUT_SEL1       (* (reg8 *) DosP__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DosP_PRTDSI__SYNC_OUT       (* (reg8 *) DosP__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DosP__SIO_CFG)
    #define DosP_SIO_HYST_EN        (* (reg8 *) DosP__SIO_HYST_EN)
    #define DosP_SIO_REG_HIFREQ     (* (reg8 *) DosP__SIO_REG_HIFREQ)
    #define DosP_SIO_CFG            (* (reg8 *) DosP__SIO_CFG)
    #define DosP_SIO_DIFF           (* (reg8 *) DosP__SIO_DIFF)
#endif /* (DosP__SIO_CFG) */

/* Interrupt Registers */
#if defined(DosP__INTSTAT)
    #define DosP_INTSTAT            (* (reg8 *) DosP__INTSTAT)
    #define DosP_SNAP               (* (reg8 *) DosP__SNAP)
    
	#define DosP_0_INTTYPE_REG 		(* (reg8 *) DosP__0__INTTYPE)
#endif /* (DosP__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DosP_H */


/* [] END OF FILE */
