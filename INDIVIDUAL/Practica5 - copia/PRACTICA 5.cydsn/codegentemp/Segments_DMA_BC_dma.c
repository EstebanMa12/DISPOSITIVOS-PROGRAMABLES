/***************************************************************************
* File Name: Segments_DMA_BC_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <Segments_DMA_BC_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* Segments_DMA_BC__DRQ_CTL_REG
* 
* 
* Segments_DMA_BC__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* Segments_DMA_BC__NUMBEROF_TDS
* 
* Priority of this channel.
* Segments_DMA_BC__PRIORITY
* 
* True if Segments_DMA_BC_TERMIN_SEL is used.
* Segments_DMA_BC__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* Segments_DMA_BC__TERMIN_SEL
* 
* 
* True if Segments_DMA_BC_TERMOUT0_SEL is used.
* Segments_DMA_BC__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* Segments_DMA_BC__TERMOUT0_SEL
* 
* 
* True if Segments_DMA_BC_TERMOUT1_SEL is used.
* Segments_DMA_BC__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* Segments_DMA_BC__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of Segments_DMA_BC dma channel */
uint8 Segments_DMA_BC_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 Segments_DMA_BC_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 Segments_DMA_BC_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    Segments_DMA_BC_DmaHandle = (uint8)Segments_DMA_BC__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(Segments_DMA_BC_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)Segments_DMA_BC__TERMOUT0_SEL,
                                  (uint8)Segments_DMA_BC__TERMOUT1_SEL,
                                  (uint8)Segments_DMA_BC__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(Segments_DMA_BC_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(Segments_DMA_BC_DmaHandle, (uint8)Segments_DMA_BC__PRIORITY);
    
    return Segments_DMA_BC_DmaHandle;
}

/*********************************************************************
* Function Name: void Segments_DMA_BC_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with Segments_DMA_BC.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void Segments_DMA_BC_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(Segments_DMA_BC_DmaHandle);
}

