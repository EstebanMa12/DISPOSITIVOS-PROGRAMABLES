/*******************************************************************************
* File Name: Enter.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Enter_H)
#define CY_ISR_Enter_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Enter_Start(void);
void Enter_StartEx(cyisraddress address);
void Enter_Stop(void);

CY_ISR_PROTO(Enter_Interrupt);

void Enter_SetVector(cyisraddress address);
cyisraddress Enter_GetVector(void);

void Enter_SetPriority(uint8 priority);
uint8 Enter_GetPriority(void);

void Enter_Enable(void);
uint8 Enter_GetState(void);
void Enter_Disable(void);

void Enter_SetPending(void);
void Enter_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Enter ISR. */
#define Enter_INTC_VECTOR            ((reg32 *) Enter__INTC_VECT)

/* Address of the Enter ISR priority. */
#define Enter_INTC_PRIOR             ((reg8 *) Enter__INTC_PRIOR_REG)

/* Priority of the Enter interrupt. */
#define Enter_INTC_PRIOR_NUMBER      Enter__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Enter interrupt. */
#define Enter_INTC_SET_EN            ((reg32 *) Enter__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Enter interrupt. */
#define Enter_INTC_CLR_EN            ((reg32 *) Enter__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Enter interrupt state to pending. */
#define Enter_INTC_SET_PD            ((reg32 *) Enter__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Enter interrupt. */
#define Enter_INTC_CLR_PD            ((reg32 *) Enter__INTC_CLR_PD_REG)


#endif /* CY_ISR_Enter_H */


/* [] END OF FILE */
