/*******************************************************************************
* File Name: counter_PM.c  
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

#include "counter.h"

static counter_backupStruct counter_backup;


/*******************************************************************************
* Function Name: counter_SaveConfig
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
*  counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void counter_SaveConfig(void) 
{
    #if (!counter_UsingFixedFunction)

        counter_backup.CounterUdb = counter_ReadCounter();

        #if(!counter_ControlRegRemoved)
            counter_backup.CounterControlRegister = counter_ReadControlRegister();
        #endif /* (!counter_ControlRegRemoved) */

    #endif /* (!counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: counter_RestoreConfig
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
*  counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void counter_RestoreConfig(void) 
{      
    #if (!counter_UsingFixedFunction)

       counter_WriteCounter(counter_backup.CounterUdb);

        #if(!counter_ControlRegRemoved)
            counter_WriteControlRegister(counter_backup.CounterControlRegister);
        #endif /* (!counter_ControlRegRemoved) */

    #endif /* (!counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: counter_Sleep
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
*  counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void counter_Sleep(void) 
{
    #if(!counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(counter_CTRL_ENABLE == (counter_CONTROL & counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            counter_backup.CounterEnableState = 0u;
        }
    #else
        counter_backup.CounterEnableState = 1u;
        if(counter_backup.CounterEnableState != 0u)
        {
            counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!counter_ControlRegRemoved) */
    
    counter_Stop();
    counter_SaveConfig();
}


/*******************************************************************************
* Function Name: counter_Wakeup
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
*  counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void counter_Wakeup(void) 
{
    counter_RestoreConfig();
    #if(!counter_ControlRegRemoved)
        if(counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
