;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.4
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; ADC
ADC_ADC_SAR__CLK EQU CYREG_SAR1_CLK
ADC_ADC_SAR__CSR0 EQU CYREG_SAR1_CSR0
ADC_ADC_SAR__CSR1 EQU CYREG_SAR1_CSR1
ADC_ADC_SAR__CSR2 EQU CYREG_SAR1_CSR2
ADC_ADC_SAR__CSR3 EQU CYREG_SAR1_CSR3
ADC_ADC_SAR__CSR4 EQU CYREG_SAR1_CSR4
ADC_ADC_SAR__CSR5 EQU CYREG_SAR1_CSR5
ADC_ADC_SAR__CSR6 EQU CYREG_SAR1_CSR6
ADC_ADC_SAR__PM_ACT_CFG EQU CYREG_PM_ACT_CFG11
ADC_ADC_SAR__PM_ACT_MSK EQU 0x02
ADC_ADC_SAR__PM_STBY_CFG EQU CYREG_PM_STBY_CFG11
ADC_ADC_SAR__PM_STBY_MSK EQU 0x02
ADC_ADC_SAR__SW0 EQU CYREG_SAR1_SW0
ADC_ADC_SAR__SW2 EQU CYREG_SAR1_SW2
ADC_ADC_SAR__SW3 EQU CYREG_SAR1_SW3
ADC_ADC_SAR__SW4 EQU CYREG_SAR1_SW4
ADC_ADC_SAR__SW6 EQU CYREG_SAR1_SW6
ADC_ADC_SAR__TR0 EQU CYREG_SAR1_TR0
ADC_ADC_SAR__WRK0 EQU CYREG_SAR1_WRK0
ADC_ADC_SAR__WRK1 EQU CYREG_SAR1_WRK1
ADC_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
ADC_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
ADC_IRQ__INTC_MASK EQU 0x01
ADC_IRQ__INTC_NUMBER EQU 0
ADC_IRQ__INTC_PRIOR_NUM EQU 7
ADC_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
ADC_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
ADC_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
ADC_theACLK__CFG0 EQU CYREG_CLKDIST_ACFG0_CFG0
ADC_theACLK__CFG1 EQU CYREG_CLKDIST_ACFG0_CFG1
ADC_theACLK__CFG2 EQU CYREG_CLKDIST_ACFG0_CFG2
ADC_theACLK__CFG2_SRC_SEL_MASK EQU 0x07
ADC_theACLK__CFG3 EQU CYREG_CLKDIST_ACFG0_CFG3
ADC_theACLK__CFG3_PHASE_DLY_MASK EQU 0x0F
ADC_theACLK__INDEX EQU 0x00
ADC_theACLK__PM_ACT_CFG EQU CYREG_PM_ACT_CFG1
ADC_theACLK__PM_ACT_MSK EQU 0x01
ADC_theACLK__PM_STBY_CFG EQU CYREG_PM_STBY_CFG1
ADC_theACLK__PM_STBY_MSK EQU 0x01

; LCD
LCD_LCDPort__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
LCD_LCDPort__0__MASK EQU 0x01
LCD_LCDPort__0__PC EQU CYREG_PRT2_PC0
LCD_LCDPort__0__PORT EQU 2
LCD_LCDPort__0__SHIFT EQU 0
LCD_LCDPort__1__INTTYPE EQU CYREG_PICU2_INTTYPE1
LCD_LCDPort__1__MASK EQU 0x02
LCD_LCDPort__1__PC EQU CYREG_PRT2_PC1
LCD_LCDPort__1__PORT EQU 2
LCD_LCDPort__1__SHIFT EQU 1
LCD_LCDPort__2__INTTYPE EQU CYREG_PICU2_INTTYPE2
LCD_LCDPort__2__MASK EQU 0x04
LCD_LCDPort__2__PC EQU CYREG_PRT2_PC2
LCD_LCDPort__2__PORT EQU 2
LCD_LCDPort__2__SHIFT EQU 2
LCD_LCDPort__3__INTTYPE EQU CYREG_PICU2_INTTYPE3
LCD_LCDPort__3__MASK EQU 0x08
LCD_LCDPort__3__PC EQU CYREG_PRT2_PC3
LCD_LCDPort__3__PORT EQU 2
LCD_LCDPort__3__SHIFT EQU 3
LCD_LCDPort__4__INTTYPE EQU CYREG_PICU2_INTTYPE4
LCD_LCDPort__4__MASK EQU 0x10
LCD_LCDPort__4__PC EQU CYREG_PRT2_PC4
LCD_LCDPort__4__PORT EQU 2
LCD_LCDPort__4__SHIFT EQU 4
LCD_LCDPort__5__INTTYPE EQU CYREG_PICU2_INTTYPE5
LCD_LCDPort__5__MASK EQU 0x20
LCD_LCDPort__5__PC EQU CYREG_PRT2_PC5
LCD_LCDPort__5__PORT EQU 2
LCD_LCDPort__5__SHIFT EQU 5
LCD_LCDPort__6__INTTYPE EQU CYREG_PICU2_INTTYPE6
LCD_LCDPort__6__MASK EQU 0x40
LCD_LCDPort__6__PC EQU CYREG_PRT2_PC6
LCD_LCDPort__6__PORT EQU 2
LCD_LCDPort__6__SHIFT EQU 6
LCD_LCDPort__AG EQU CYREG_PRT2_AG
LCD_LCDPort__AMUX EQU CYREG_PRT2_AMUX
LCD_LCDPort__BIE EQU CYREG_PRT2_BIE
LCD_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
LCD_LCDPort__BYP EQU CYREG_PRT2_BYP
LCD_LCDPort__CTL EQU CYREG_PRT2_CTL
LCD_LCDPort__DM0 EQU CYREG_PRT2_DM0
LCD_LCDPort__DM1 EQU CYREG_PRT2_DM1
LCD_LCDPort__DM2 EQU CYREG_PRT2_DM2
LCD_LCDPort__DR EQU CYREG_PRT2_DR
LCD_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
LCD_LCDPort__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
LCD_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
LCD_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
LCD_LCDPort__MASK EQU 0x7F
LCD_LCDPort__PORT EQU 2
LCD_LCDPort__PRT EQU CYREG_PRT2_PRT
LCD_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
LCD_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
LCD_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
LCD_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
LCD_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
LCD_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
LCD_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
LCD_LCDPort__PS EQU CYREG_PRT2_PS
LCD_LCDPort__SHIFT EQU 0
LCD_LCDPort__SLW EQU CYREG_PRT2_SLW

; Peso
Peso__0__INTTYPE EQU CYREG_PICU1_INTTYPE6
Peso__0__MASK EQU 0x40
Peso__0__PC EQU CYREG_PRT1_PC6
Peso__0__PORT EQU 1
Peso__0__SHIFT EQU 6
Peso__AG EQU CYREG_PRT1_AG
Peso__AMUX EQU CYREG_PRT1_AMUX
Peso__BIE EQU CYREG_PRT1_BIE
Peso__BIT_MASK EQU CYREG_PRT1_BIT_MASK
Peso__BYP EQU CYREG_PRT1_BYP
Peso__CTL EQU CYREG_PRT1_CTL
Peso__DM0 EQU CYREG_PRT1_DM0
Peso__DM1 EQU CYREG_PRT1_DM1
Peso__DM2 EQU CYREG_PRT1_DM2
Peso__DR EQU CYREG_PRT1_DR
Peso__INP_DIS EQU CYREG_PRT1_INP_DIS
Peso__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
Peso__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
Peso__LCD_EN EQU CYREG_PRT1_LCD_EN
Peso__MASK EQU 0x40
Peso__PORT EQU 1
Peso__PRT EQU CYREG_PRT1_PRT
Peso__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
Peso__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
Peso__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
Peso__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
Peso__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
Peso__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
Peso__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
Peso__PS EQU CYREG_PRT1_PS
Peso__SHIFT EQU 6
Peso__SLW EQU CYREG_PRT1_SLW

; timer
timer__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
timer__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
timer__INTC_MASK EQU 0x20000
timer__INTC_NUMBER EQU 17
timer__INTC_PRIOR_NUM EQU 7
timer__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_17
timer__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
timer__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Buzzer
Buzzer__0__INTTYPE EQU CYREG_PICU1_INTTYPE5
Buzzer__0__MASK EQU 0x20
Buzzer__0__PC EQU CYREG_PRT1_PC5
Buzzer__0__PORT EQU 1
Buzzer__0__SHIFT EQU 5
Buzzer__AG EQU CYREG_PRT1_AG
Buzzer__AMUX EQU CYREG_PRT1_AMUX
Buzzer__BIE EQU CYREG_PRT1_BIE
Buzzer__BIT_MASK EQU CYREG_PRT1_BIT_MASK
Buzzer__BYP EQU CYREG_PRT1_BYP
Buzzer__CTL EQU CYREG_PRT1_CTL
Buzzer__DM0 EQU CYREG_PRT1_DM0
Buzzer__DM1 EQU CYREG_PRT1_DM1
Buzzer__DM2 EQU CYREG_PRT1_DM2
Buzzer__DR EQU CYREG_PRT1_DR
Buzzer__INP_DIS EQU CYREG_PRT1_INP_DIS
Buzzer__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
Buzzer__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
Buzzer__LCD_EN EQU CYREG_PRT1_LCD_EN
Buzzer__MASK EQU 0x20
Buzzer__PORT EQU 1
Buzzer__PRT EQU CYREG_PRT1_PRT
Buzzer__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
Buzzer__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
Buzzer__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
Buzzer__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
Buzzer__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
Buzzer__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
Buzzer__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
Buzzer__PS EQU CYREG_PRT1_PS
Buzzer__SHIFT EQU 5
Buzzer__SLW EQU CYREG_PRT1_SLW

; Clock_1
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x00
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x01
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x01

; counter
counter_CounterHW__CAP0 EQU CYREG_TMR0_CAP0
counter_CounterHW__CAP1 EQU CYREG_TMR0_CAP1
counter_CounterHW__CFG0 EQU CYREG_TMR0_CFG0
counter_CounterHW__CFG1 EQU CYREG_TMR0_CFG1
counter_CounterHW__CFG2 EQU CYREG_TMR0_CFG2
counter_CounterHW__CNT_CMP0 EQU CYREG_TMR0_CNT_CMP0
counter_CounterHW__CNT_CMP1 EQU CYREG_TMR0_CNT_CMP1
counter_CounterHW__PER0 EQU CYREG_TMR0_PER0
counter_CounterHW__PER1 EQU CYREG_TMR0_PER1
counter_CounterHW__PM_ACT_CFG EQU CYREG_PM_ACT_CFG3
counter_CounterHW__PM_ACT_MSK EQU 0x01
counter_CounterHW__PM_STBY_CFG EQU CYREG_PM_STBY_CFG3
counter_CounterHW__PM_STBY_MSK EQU 0x01
counter_CounterHW__RT0 EQU CYREG_TMR0_RT0
counter_CounterHW__RT1 EQU CYREG_TMR0_RT1
counter_CounterHW__SR0 EQU CYREG_TMR0_SR0

; Temperatura
Temperatura__0__INTTYPE EQU CYREG_PICU1_INTTYPE7
Temperatura__0__MASK EQU 0x80
Temperatura__0__PC EQU CYREG_PRT1_PC7
Temperatura__0__PORT EQU 1
Temperatura__0__SHIFT EQU 7
Temperatura__AG EQU CYREG_PRT1_AG
Temperatura__AMUX EQU CYREG_PRT1_AMUX
Temperatura__BIE EQU CYREG_PRT1_BIE
Temperatura__BIT_MASK EQU CYREG_PRT1_BIT_MASK
Temperatura__BYP EQU CYREG_PRT1_BYP
Temperatura__CTL EQU CYREG_PRT1_CTL
Temperatura__DM0 EQU CYREG_PRT1_DM0
Temperatura__DM1 EQU CYREG_PRT1_DM1
Temperatura__DM2 EQU CYREG_PRT1_DM2
Temperatura__DR EQU CYREG_PRT1_DR
Temperatura__INP_DIS EQU CYREG_PRT1_INP_DIS
Temperatura__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
Temperatura__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
Temperatura__LCD_EN EQU CYREG_PRT1_LCD_EN
Temperatura__MASK EQU 0x80
Temperatura__PORT EQU 1
Temperatura__PRT EQU CYREG_PRT1_PRT
Temperatura__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
Temperatura__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
Temperatura__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
Temperatura__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
Temperatura__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
Temperatura__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
Temperatura__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
Temperatura__PS EQU CYREG_PRT1_PS
Temperatura__SHIFT EQU 7
Temperatura__SLW EQU CYREG_PRT1_SLW

; clavecorrecta
clavecorrecta__0__INTTYPE EQU CYREG_PICU0_INTTYPE7
clavecorrecta__0__MASK EQU 0x80
clavecorrecta__0__PC EQU CYREG_PRT0_PC7
clavecorrecta__0__PORT EQU 0
clavecorrecta__0__SHIFT EQU 7
clavecorrecta__AG EQU CYREG_PRT0_AG
clavecorrecta__AMUX EQU CYREG_PRT0_AMUX
clavecorrecta__BIE EQU CYREG_PRT0_BIE
clavecorrecta__BIT_MASK EQU CYREG_PRT0_BIT_MASK
clavecorrecta__BYP EQU CYREG_PRT0_BYP
clavecorrecta__CTL EQU CYREG_PRT0_CTL
clavecorrecta__DM0 EQU CYREG_PRT0_DM0
clavecorrecta__DM1 EQU CYREG_PRT0_DM1
clavecorrecta__DM2 EQU CYREG_PRT0_DM2
clavecorrecta__DR EQU CYREG_PRT0_DR
clavecorrecta__INP_DIS EQU CYREG_PRT0_INP_DIS
clavecorrecta__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
clavecorrecta__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
clavecorrecta__LCD_EN EQU CYREG_PRT0_LCD_EN
clavecorrecta__MASK EQU 0x80
clavecorrecta__PORT EQU 0
clavecorrecta__PRT EQU CYREG_PRT0_PRT
clavecorrecta__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
clavecorrecta__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
clavecorrecta__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
clavecorrecta__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
clavecorrecta__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
clavecorrecta__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
clavecorrecta__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
clavecorrecta__PS EQU CYREG_PRT0_PS
clavecorrecta__SHIFT EQU 7
clavecorrecta__SLW EQU CYREG_PRT0_SLW

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 26
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E127069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 26
CYDEV_CHIP_MEMBER_4AA EQU 25
CYDEV_CHIP_MEMBER_4AB EQU 30
CYDEV_CHIP_MEMBER_4AC EQU 14
CYDEV_CHIP_MEMBER_4AD EQU 15
CYDEV_CHIP_MEMBER_4AE EQU 16
CYDEV_CHIP_MEMBER_4D EQU 20
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 27
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 24
CYDEV_CHIP_MEMBER_4I EQU 32
CYDEV_CHIP_MEMBER_4J EQU 21
CYDEV_CHIP_MEMBER_4K EQU 22
CYDEV_CHIP_MEMBER_4L EQU 31
CYDEV_CHIP_MEMBER_4M EQU 29
CYDEV_CHIP_MEMBER_4N EQU 11
CYDEV_CHIP_MEMBER_4O EQU 8
CYDEV_CHIP_MEMBER_4P EQU 28
CYDEV_CHIP_MEMBER_4Q EQU 17
CYDEV_CHIP_MEMBER_4R EQU 9
CYDEV_CHIP_MEMBER_4S EQU 12
CYDEV_CHIP_MEMBER_4T EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 23
CYDEV_CHIP_MEMBER_4W EQU 13
CYDEV_CHIP_MEMBER_4X EQU 7
CYDEV_CHIP_MEMBER_4Y EQU 18
CYDEV_CHIP_MEMBER_4Z EQU 19
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 33
CYDEV_CHIP_MEMBER_FM3 EQU 37
CYDEV_CHIP_MEMBER_FM4 EQU 38
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 34
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 35
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 36
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4AA_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AB_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AC_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AD_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AE_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4W_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4X_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Y_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Z_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000001
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END