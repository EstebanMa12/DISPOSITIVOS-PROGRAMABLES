/*******************************************************************************
* File Name: Segments_Seg_Driver_L_PM.c
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

#include "Segments_Seg_Driver_L.h"

/* Check for removal by optimization */
#if !defined(Segments_Seg_Driver_L_Sync_ctrl_reg__REMOVED)

static Segments_Seg_Driver_L_BACKUP_STRUCT  Segments_Seg_Driver_L_backup = {0u};

    
/*******************************************************************************
* Function Name: Segments_Seg_Driver_L_SaveConfig
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
void Segments_Seg_Driver_L_SaveConfig(void) 
{
    Segments_Seg_Driver_L_backup.controlState = Segments_Seg_Driver_L_Control;
}


/*******************************************************************************
* Function Name: Segments_Seg_Driver_L_RestoreConfig
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
void Segments_Seg_Driver_L_RestoreConfig(void) 
{
     Segments_Seg_Driver_L_Control = Segments_Seg_Driver_L_backup.controlState;
}


/*******************************************************************************
* Function Name: Segments_Seg_Driver_L_Sleep
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
void Segments_Seg_Driver_L_Sleep(void) 
{
    Segments_Seg_Driver_L_SaveConfig();
}


/*******************************************************************************
* Function Name: Segments_Seg_Driver_L_Wakeup
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
void Segments_Seg_Driver_L_Wakeup(void)  
{
    Segments_Seg_Driver_L_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
