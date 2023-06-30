/*******************************************************************************
* File Name: Contador_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Contador.h"

static Contador_backupStruct Contador_backup;


/*******************************************************************************
* Function Name: Contador_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Contador_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Contador_SaveConfig(void) 
{
    #if (!Contador_UsingFixedFunction)

        Contador_backup.CounterUdb = Contador_ReadCounter();

        #if(!Contador_ControlRegRemoved)
            Contador_backup.CounterControlRegister = Contador_ReadControlRegister();
        #endif /* (!Contador_ControlRegRemoved) */

    #endif /* (!Contador_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Contador_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Contador_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Contador_RestoreConfig(void) 
{      
    #if (!Contador_UsingFixedFunction)

       Contador_WriteCounter(Contador_backup.CounterUdb);

        #if(!Contador_ControlRegRemoved)
            Contador_WriteControlRegister(Contador_backup.CounterControlRegister);
        #endif /* (!Contador_ControlRegRemoved) */

    #endif /* (!Contador_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Contador_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Contador_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Contador_Sleep(void) 
{
    #if(!Contador_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Contador_CTRL_ENABLE == (Contador_CONTROL & Contador_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Contador_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Contador_backup.CounterEnableState = 0u;
        }
    #else
        Contador_backup.CounterEnableState = 1u;
        if(Contador_backup.CounterEnableState != 0u)
        {
            Contador_backup.CounterEnableState = 0u;
        }
    #endif /* (!Contador_ControlRegRemoved) */
    
    Contador_Stop();
    Contador_SaveConfig();
}


/*******************************************************************************
* Function Name: Contador_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Contador_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Contador_Wakeup(void) 
{
    Contador_RestoreConfig();
    #if(!Contador_ControlRegRemoved)
        if(Contador_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Contador_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Contador_ControlRegRemoved) */
    
}


/* [] END OF FILE */
