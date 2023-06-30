/*******************************************************************************
* File Name: Segments_Com_Driver_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Segments_Com_Driver.h"

/* Check for removal by optimization */
#if !defined(Segments_Com_Driver_Sync_ctrl_reg__REMOVED)

static Segments_Com_Driver_BACKUP_STRUCT  Segments_Com_Driver_backup = {0u};

    
/*******************************************************************************
* Function Name: Segments_Com_Driver_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Segments_Com_Driver_SaveConfig(void) 
{
    Segments_Com_Driver_backup.controlState = Segments_Com_Driver_Control;
}


/*******************************************************************************
* Function Name: Segments_Com_Driver_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Segments_Com_Driver_RestoreConfig(void) 
{
     Segments_Com_Driver_Control = Segments_Com_Driver_backup.controlState;
}


/*******************************************************************************
* Function Name: Segments_Com_Driver_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Segments_Com_Driver_Sleep(void) 
{
    Segments_Com_Driver_SaveConfig();
}


/*******************************************************************************
* Function Name: Segments_Com_Driver_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Segments_Com_Driver_Wakeup(void)  
{
    Segments_Com_Driver_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
