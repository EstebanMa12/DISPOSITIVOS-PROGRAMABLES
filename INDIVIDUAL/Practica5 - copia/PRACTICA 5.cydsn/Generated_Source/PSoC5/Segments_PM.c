/*******************************************************************************
* File Name: Segments_PM.c
* Version 1.10
*
* Description:
*  This file provides the power management source code to API for the
*  LED_Driver component.
*
* Note:
*  None
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Segments.h"
static Segments_backupStruct Segments_backup;


/*******************************************************************************
* Function Name: Segments_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Segments_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    Segments_backup.ledEnableState = Segments_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < Segments_NUM_COM; i++)
    {
        Segments_backup.segLBackup[i] = Segments_segLBuffer[i];
        #if (Segments_NUM_SEG > 8u) 
            Segments_backup.segMBackup[i] = Segments_segMBuffer[i];
        #endif /* (Segments_NUM_SEG > 8u) */
        #if (Segments_NUM_SEG > 16u) 
            Segments_backup.segHBackup[i] = Segments_segHBuffer[i];
        #endif /* (Segments_NUM_SEG > 16u) */
    }
    
    Segments_Stop();
}


/*******************************************************************************
* Function Name: Segments_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Segments_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < Segments_NUM_COM; i++)
    {
        Segments_segLBuffer[i] = Segments_backup.segLBackup[i];
        #if (Segments_NUM_SEG > 8u) 
            Segments_segMBuffer[i] = Segments_backup.segMBackup[i];
        #endif /* (Segments_NUM_SEG > 8u) */
        #if (Segments_NUM_SEG > 16u) 
            Segments_segHBuffer[i] = Segments_backup.segHBackup[i];
        #endif /* (Segments_NUM_SEG > 16u) */
    }
    
    if(Segments_backup.ledEnableState == Segments_ENABLED)
    {
        /* Enable the component */
        Segments_Enable();
    }
}


/* [] END OF FILE */

