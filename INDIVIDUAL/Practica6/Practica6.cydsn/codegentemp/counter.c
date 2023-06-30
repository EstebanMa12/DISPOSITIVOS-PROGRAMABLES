/*******************************************************************************
* File Name: counter.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
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

uint8 counter_initVar = 0u;


/*******************************************************************************
* Function Name: counter_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void counter_Init(void) 
{
        #if (!counter_UsingFixedFunction && !counter_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!counter_UsingFixedFunction && !counter_ControlRegRemoved) */
        
        #if(!counter_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 counter_interruptState;
        #endif /* (!counter_UsingFixedFunction) */
        
        #if (counter_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            counter_CONTROL &= counter_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                counter_CONTROL2 &= ((uint8)(~counter_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                counter_CONTROL3 &= ((uint8)(~counter_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (counter_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                counter_CONTROL |= counter_ONESHOT;
            #endif /* (counter_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            counter_CONTROL2 |= counter_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            counter_RT1 &= ((uint8)(~counter_RT1_MASK));
            counter_RT1 |= counter_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            counter_RT1 &= ((uint8)(~counter_SYNCDSI_MASK));
            counter_RT1 |= counter_SYNCDSI_EN;

        #else
            #if(!counter_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = counter_CONTROL & ((uint8)(~counter_CTRL_CMPMODE_MASK));
            counter_CONTROL = ctrl | counter_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = counter_CONTROL & ((uint8)(~counter_CTRL_CAPMODE_MASK));
            
            #if( 0 != counter_CAPTURE_MODE_CONF)
                counter_CONTROL = ctrl | counter_DEFAULT_CAPTURE_MODE;
            #else
                counter_CONTROL = ctrl;
            #endif /* 0 != counter_CAPTURE_MODE */ 
            
            #endif /* (!counter_ControlRegRemoved) */
        #endif /* (counter_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!counter_UsingFixedFunction)
            counter_ClearFIFO();
        #endif /* (!counter_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        counter_WritePeriod(counter_INIT_PERIOD_VALUE);
        #if (!(counter_UsingFixedFunction && (CY_PSOC5A)))
            counter_WriteCounter(counter_INIT_COUNTER_VALUE);
        #endif /* (!(counter_UsingFixedFunction && (CY_PSOC5A))) */
        counter_SetInterruptMode(counter_INIT_INTERRUPTS_MASK);
        
        #if (!counter_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)counter_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            counter_WriteCompare(counter_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            counter_interruptState = CyEnterCriticalSection();
            
            counter_STATUS_AUX_CTRL |= counter_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(counter_interruptState);
            
        #endif /* (!counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: counter_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void counter_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (counter_UsingFixedFunction)
        counter_GLOBAL_ENABLE |= counter_BLOCK_EN_MASK;
        counter_GLOBAL_STBY_ENABLE |= counter_BLOCK_STBY_EN_MASK;
    #endif /* (counter_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!counter_ControlRegRemoved || counter_UsingFixedFunction)
        counter_CONTROL |= counter_CTRL_ENABLE;                
    #endif /* (!counter_ControlRegRemoved || counter_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: counter_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  counter_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void counter_Start(void) 
{
    if(counter_initVar == 0u)
    {
        counter_Init();
        
        counter_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    counter_Enable();        
}


/*******************************************************************************
* Function Name: counter_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void counter_Stop(void) 
{
    /* Disable Counter */
    #if(!counter_ControlRegRemoved || counter_UsingFixedFunction)
        counter_CONTROL &= ((uint8)(~counter_CTRL_ENABLE));        
    #endif /* (!counter_ControlRegRemoved || counter_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (counter_UsingFixedFunction)
        counter_GLOBAL_ENABLE &= ((uint8)(~counter_BLOCK_EN_MASK));
        counter_GLOBAL_STBY_ENABLE &= ((uint8)(~counter_BLOCK_STBY_EN_MASK));
    #endif /* (counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: counter_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void counter_SetInterruptMode(uint8 interruptsMask) 
{
    counter_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: counter_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   counter_ReadStatusRegister(void) 
{
    return counter_STATUS;
}


#if(!counter_ControlRegRemoved)
/*******************************************************************************
* Function Name: counter_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   counter_ReadControlRegister(void) 
{
    return counter_CONTROL;
}


/*******************************************************************************
* Function Name: counter_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    counter_WriteControlRegister(uint8 control) 
{
    counter_CONTROL = control;
}

#endif  /* (!counter_ControlRegRemoved) */


#if (!(counter_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: counter_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void counter_WriteCounter(uint16 counter) \
                                   
{
    #if(counter_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (counter_GLOBAL_ENABLE & counter_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        counter_GLOBAL_ENABLE |= counter_BLOCK_EN_MASK;
        CY_SET_REG16(counter_COUNTER_LSB_PTR, (uint16)counter);
        counter_GLOBAL_ENABLE &= ((uint8)(~counter_BLOCK_EN_MASK));
    #else
        CY_SET_REG16(counter_COUNTER_LSB_PTR, counter);
    #endif /* (counter_UsingFixedFunction) */
}
#endif /* (!(counter_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: counter_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) The present value of the counter.
*
*******************************************************************************/
uint16 counter_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(counter_UsingFixedFunction)
		(void)CY_GET_REG16(counter_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(counter_COUNTER_LSB_PTR_8BIT);
	#endif/* (counter_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(counter_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(counter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(counter_STATICCOUNT_LSB_PTR));
    #endif /* (counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: counter_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint16) Present Capture value.
*
*******************************************************************************/
uint16 counter_ReadCapture(void) 
{
    #if(counter_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(counter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(counter_STATICCOUNT_LSB_PTR));
    #endif /* (counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: counter_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint16) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void counter_WritePeriod(uint16 period) 
{
    #if(counter_UsingFixedFunction)
        CY_SET_REG16(counter_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG16(counter_PERIOD_LSB_PTR, period);
    #endif /* (counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: counter_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) Present period value.
*
*******************************************************************************/
uint16 counter_ReadPeriod(void) 
{
    #if(counter_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(counter_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(counter_PERIOD_LSB_PTR));
    #endif /* (counter_UsingFixedFunction) */
}


#if (!counter_UsingFixedFunction)
/*******************************************************************************
* Function Name: counter_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void counter_WriteCompare(uint16 compare) \
                                   
{
    #if(counter_UsingFixedFunction)
        CY_SET_REG16(counter_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(counter_COMPARE_LSB_PTR, compare);
    #endif /* (counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: counter_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint16) Present compare value.
*
*******************************************************************************/
uint16 counter_ReadCompare(void) 
{
    return (CY_GET_REG16(counter_COMPARE_LSB_PTR));
}


#if (counter_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: counter_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void counter_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    counter_CONTROL &= ((uint8)(~counter_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    counter_CONTROL |= compareMode;
}
#endif  /* (counter_COMPARE_MODE_SOFTWARE) */


#if (counter_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: counter_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void counter_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    counter_CONTROL &= ((uint8)(~counter_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    counter_CONTROL |= ((uint8)((uint8)captureMode << counter_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (counter_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: counter_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void counter_ClearFIFO(void) 
{

    while(0u != (counter_ReadStatusRegister() & counter_STATUS_FIFONEMP))
    {
        (void)counter_ReadCapture();
    }

}
#endif  /* (!counter_UsingFixedFunction) */


/* [] END OF FILE */

