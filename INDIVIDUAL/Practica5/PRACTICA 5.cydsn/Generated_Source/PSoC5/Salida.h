/*******************************************************************************
* File Name: Salida.h
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
#if !defined(CY_ISR_Salida_H)
#define CY_ISR_Salida_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Salida_Start(void);
void Salida_StartEx(cyisraddress address);
void Salida_Stop(void);

CY_ISR_PROTO(Salida_Interrupt);

void Salida_SetVector(cyisraddress address);
cyisraddress Salida_GetVector(void);

void Salida_SetPriority(uint8 priority);
uint8 Salida_GetPriority(void);

void Salida_Enable(void);
uint8 Salida_GetState(void);
void Salida_Disable(void);

void Salida_SetPending(void);
void Salida_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Salida ISR. */
#define Salida_INTC_VECTOR            ((reg32 *) Salida__INTC_VECT)

/* Address of the Salida ISR priority. */
#define Salida_INTC_PRIOR             ((reg8 *) Salida__INTC_PRIOR_REG)

/* Priority of the Salida interrupt. */
#define Salida_INTC_PRIOR_NUMBER      Salida__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Salida interrupt. */
#define Salida_INTC_SET_EN            ((reg32 *) Salida__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Salida interrupt. */
#define Salida_INTC_CLR_EN            ((reg32 *) Salida__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Salida interrupt state to pending. */
#define Salida_INTC_SET_PD            ((reg32 *) Salida__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Salida interrupt. */
#define Salida_INTC_CLR_PD            ((reg32 *) Salida__INTC_CLR_PD_REG)


#endif /* CY_ISR_Salida_H */


/* [] END OF FILE */
