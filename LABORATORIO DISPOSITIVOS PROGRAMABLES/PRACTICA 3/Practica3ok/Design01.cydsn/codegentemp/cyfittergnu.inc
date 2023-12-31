/*******************************************************************************
* File Name: cyfittergnu.inc
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* A */
.set A__0__INTTYPE, CYREG_PICU0_INTTYPE0
.set A__0__MASK, 0x01
.set A__0__PC, CYREG_PRT0_PC0
.set A__0__PORT, 0
.set A__0__SHIFT, 0
.set A__AG, CYREG_PRT0_AG
.set A__AMUX, CYREG_PRT0_AMUX
.set A__BIE, CYREG_PRT0_BIE
.set A__BIT_MASK, CYREG_PRT0_BIT_MASK
.set A__BYP, CYREG_PRT0_BYP
.set A__CTL, CYREG_PRT0_CTL
.set A__DM0, CYREG_PRT0_DM0
.set A__DM1, CYREG_PRT0_DM1
.set A__DM2, CYREG_PRT0_DM2
.set A__DR, CYREG_PRT0_DR
.set A__INP_DIS, CYREG_PRT0_INP_DIS
.set A__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set A__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set A__LCD_EN, CYREG_PRT0_LCD_EN
.set A__MASK, 0x01
.set A__PORT, 0
.set A__PRT, CYREG_PRT0_PRT
.set A__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set A__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set A__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set A__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set A__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set A__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set A__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set A__PS, CYREG_PRT0_PS
.set A__SHIFT, 0
.set A__SLW, CYREG_PRT0_SLW

/* B */
.set B__0__INTTYPE, CYREG_PICU0_INTTYPE1
.set B__0__MASK, 0x02
.set B__0__PC, CYREG_PRT0_PC1
.set B__0__PORT, 0
.set B__0__SHIFT, 1
.set B__AG, CYREG_PRT0_AG
.set B__AMUX, CYREG_PRT0_AMUX
.set B__BIE, CYREG_PRT0_BIE
.set B__BIT_MASK, CYREG_PRT0_BIT_MASK
.set B__BYP, CYREG_PRT0_BYP
.set B__CTL, CYREG_PRT0_CTL
.set B__DM0, CYREG_PRT0_DM0
.set B__DM1, CYREG_PRT0_DM1
.set B__DM2, CYREG_PRT0_DM2
.set B__DR, CYREG_PRT0_DR
.set B__INP_DIS, CYREG_PRT0_INP_DIS
.set B__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set B__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set B__LCD_EN, CYREG_PRT0_LCD_EN
.set B__MASK, 0x02
.set B__PORT, 0
.set B__PRT, CYREG_PRT0_PRT
.set B__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set B__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set B__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set B__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set B__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set B__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set B__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set B__PS, CYREG_PRT0_PS
.set B__SHIFT, 1
.set B__SLW, CYREG_PRT0_SLW

/* C */
.set C__0__INTTYPE, CYREG_PICU0_INTTYPE2
.set C__0__MASK, 0x04
.set C__0__PC, CYREG_PRT0_PC2
.set C__0__PORT, 0
.set C__0__SHIFT, 2
.set C__AG, CYREG_PRT0_AG
.set C__AMUX, CYREG_PRT0_AMUX
.set C__BIE, CYREG_PRT0_BIE
.set C__BIT_MASK, CYREG_PRT0_BIT_MASK
.set C__BYP, CYREG_PRT0_BYP
.set C__CTL, CYREG_PRT0_CTL
.set C__DM0, CYREG_PRT0_DM0
.set C__DM1, CYREG_PRT0_DM1
.set C__DM2, CYREG_PRT0_DM2
.set C__DR, CYREG_PRT0_DR
.set C__INP_DIS, CYREG_PRT0_INP_DIS
.set C__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set C__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set C__LCD_EN, CYREG_PRT0_LCD_EN
.set C__MASK, 0x04
.set C__PORT, 0
.set C__PRT, CYREG_PRT0_PRT
.set C__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set C__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set C__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set C__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set C__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set C__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set C__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set C__PS, CYREG_PRT0_PS
.set C__SHIFT, 2
.set C__SLW, CYREG_PRT0_SLW

/* D */
.set D__0__INTTYPE, CYREG_PICU0_INTTYPE3
.set D__0__MASK, 0x08
.set D__0__PC, CYREG_PRT0_PC3
.set D__0__PORT, 0
.set D__0__SHIFT, 3
.set D__AG, CYREG_PRT0_AG
.set D__AMUX, CYREG_PRT0_AMUX
.set D__BIE, CYREG_PRT0_BIE
.set D__BIT_MASK, CYREG_PRT0_BIT_MASK
.set D__BYP, CYREG_PRT0_BYP
.set D__CTL, CYREG_PRT0_CTL
.set D__DM0, CYREG_PRT0_DM0
.set D__DM1, CYREG_PRT0_DM1
.set D__DM2, CYREG_PRT0_DM2
.set D__DR, CYREG_PRT0_DR
.set D__INP_DIS, CYREG_PRT0_INP_DIS
.set D__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set D__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set D__LCD_EN, CYREG_PRT0_LCD_EN
.set D__MASK, 0x08
.set D__PORT, 0
.set D__PRT, CYREG_PRT0_PRT
.set D__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set D__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set D__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set D__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set D__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set D__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set D__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set D__PS, CYREG_PRT0_PS
.set D__SHIFT, 3
.set D__SLW, CYREG_PRT0_SLW

/* E */
.set E__0__INTTYPE, CYREG_PICU0_INTTYPE4
.set E__0__MASK, 0x10
.set E__0__PC, CYREG_PRT0_PC4
.set E__0__PORT, 0
.set E__0__SHIFT, 4
.set E__AG, CYREG_PRT0_AG
.set E__AMUX, CYREG_PRT0_AMUX
.set E__BIE, CYREG_PRT0_BIE
.set E__BIT_MASK, CYREG_PRT0_BIT_MASK
.set E__BYP, CYREG_PRT0_BYP
.set E__CTL, CYREG_PRT0_CTL
.set E__DM0, CYREG_PRT0_DM0
.set E__DM1, CYREG_PRT0_DM1
.set E__DM2, CYREG_PRT0_DM2
.set E__DR, CYREG_PRT0_DR
.set E__INP_DIS, CYREG_PRT0_INP_DIS
.set E__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set E__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set E__LCD_EN, CYREG_PRT0_LCD_EN
.set E__MASK, 0x10
.set E__PORT, 0
.set E__PRT, CYREG_PRT0_PRT
.set E__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set E__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set E__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set E__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set E__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set E__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set E__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set E__PS, CYREG_PRT0_PS
.set E__SHIFT, 4
.set E__SLW, CYREG_PRT0_SLW

/* F */
.set F__0__INTTYPE, CYREG_PICU0_INTTYPE5
.set F__0__MASK, 0x20
.set F__0__PC, CYREG_PRT0_PC5
.set F__0__PORT, 0
.set F__0__SHIFT, 5
.set F__AG, CYREG_PRT0_AG
.set F__AMUX, CYREG_PRT0_AMUX
.set F__BIE, CYREG_PRT0_BIE
.set F__BIT_MASK, CYREG_PRT0_BIT_MASK
.set F__BYP, CYREG_PRT0_BYP
.set F__CTL, CYREG_PRT0_CTL
.set F__DM0, CYREG_PRT0_DM0
.set F__DM1, CYREG_PRT0_DM1
.set F__DM2, CYREG_PRT0_DM2
.set F__DR, CYREG_PRT0_DR
.set F__INP_DIS, CYREG_PRT0_INP_DIS
.set F__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set F__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set F__LCD_EN, CYREG_PRT0_LCD_EN
.set F__MASK, 0x20
.set F__PORT, 0
.set F__PRT, CYREG_PRT0_PRT
.set F__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set F__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set F__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set F__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set F__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set F__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set F__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set F__PS, CYREG_PRT0_PS
.set F__SHIFT, 5
.set F__SLW, CYREG_PRT0_SLW

/* G */
.set G__0__INTTYPE, CYREG_PICU0_INTTYPE6
.set G__0__MASK, 0x40
.set G__0__PC, CYREG_PRT0_PC6
.set G__0__PORT, 0
.set G__0__SHIFT, 6
.set G__AG, CYREG_PRT0_AG
.set G__AMUX, CYREG_PRT0_AMUX
.set G__BIE, CYREG_PRT0_BIE
.set G__BIT_MASK, CYREG_PRT0_BIT_MASK
.set G__BYP, CYREG_PRT0_BYP
.set G__CTL, CYREG_PRT0_CTL
.set G__DM0, CYREG_PRT0_DM0
.set G__DM1, CYREG_PRT0_DM1
.set G__DM2, CYREG_PRT0_DM2
.set G__DR, CYREG_PRT0_DR
.set G__INP_DIS, CYREG_PRT0_INP_DIS
.set G__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set G__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set G__LCD_EN, CYREG_PRT0_LCD_EN
.set G__MASK, 0x40
.set G__PORT, 0
.set G__PRT, CYREG_PRT0_PRT
.set G__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set G__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set G__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set G__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set G__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set G__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set G__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set G__PS, CYREG_PRT0_PS
.set G__SHIFT, 6
.set G__SLW, CYREG_PRT0_SLW

/* X */
.set X__0__INTTYPE, CYREG_PICU2_INTTYPE0
.set X__0__MASK, 0x01
.set X__0__PC, CYREG_PRT2_PC0
.set X__0__PORT, 2
.set X__0__SHIFT, 0
.set X__AG, CYREG_PRT2_AG
.set X__AMUX, CYREG_PRT2_AMUX
.set X__BIE, CYREG_PRT2_BIE
.set X__BIT_MASK, CYREG_PRT2_BIT_MASK
.set X__BYP, CYREG_PRT2_BYP
.set X__CTL, CYREG_PRT2_CTL
.set X__DM0, CYREG_PRT2_DM0
.set X__DM1, CYREG_PRT2_DM1
.set X__DM2, CYREG_PRT2_DM2
.set X__DR, CYREG_PRT2_DR
.set X__INP_DIS, CYREG_PRT2_INP_DIS
.set X__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set X__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set X__LCD_EN, CYREG_PRT2_LCD_EN
.set X__MASK, 0x01
.set X__PORT, 2
.set X__PRT, CYREG_PRT2_PRT
.set X__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set X__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set X__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set X__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set X__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set X__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set X__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set X__PS, CYREG_PRT2_PS
.set X__SHIFT, 0
.set X__SLW, CYREG_PRT2_SLW

/* RGB */
.set RGB__0__INTTYPE, CYREG_PICU15_INTTYPE2
.set RGB__0__MASK, 0x04
.set RGB__0__PC, CYREG_IO_PC_PRT15_PC2
.set RGB__0__PORT, 15
.set RGB__0__SHIFT, 2
.set RGB__AG, CYREG_PRT15_AG
.set RGB__AMUX, CYREG_PRT15_AMUX
.set RGB__BIE, CYREG_PRT15_BIE
.set RGB__BIT_MASK, CYREG_PRT15_BIT_MASK
.set RGB__BYP, CYREG_PRT15_BYP
.set RGB__CTL, CYREG_PRT15_CTL
.set RGB__DM0, CYREG_PRT15_DM0
.set RGB__DM1, CYREG_PRT15_DM1
.set RGB__DM2, CYREG_PRT15_DM2
.set RGB__DR, CYREG_PRT15_DR
.set RGB__INP_DIS, CYREG_PRT15_INP_DIS
.set RGB__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set RGB__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set RGB__LCD_EN, CYREG_PRT15_LCD_EN
.set RGB__MASK, 0x04
.set RGB__PORT, 15
.set RGB__PRT, CYREG_PRT15_PRT
.set RGB__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set RGB__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set RGB__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set RGB__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set RGB__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set RGB__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set RGB__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set RGB__PS, CYREG_PRT15_PS
.set RGB__SHIFT, 2
.set RGB__SLW, CYREG_PRT15_SLW

/* Led_0 */
.set Led_0__0__INTTYPE, CYREG_PICU12_INTTYPE7
.set Led_0__0__MASK, 0x80
.set Led_0__0__PC, CYREG_PRT12_PC7
.set Led_0__0__PORT, 12
.set Led_0__0__SHIFT, 7
.set Led_0__AG, CYREG_PRT12_AG
.set Led_0__BIE, CYREG_PRT12_BIE
.set Led_0__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Led_0__BYP, CYREG_PRT12_BYP
.set Led_0__DM0, CYREG_PRT12_DM0
.set Led_0__DM1, CYREG_PRT12_DM1
.set Led_0__DM2, CYREG_PRT12_DM2
.set Led_0__DR, CYREG_PRT12_DR
.set Led_0__INP_DIS, CYREG_PRT12_INP_DIS
.set Led_0__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Led_0__MASK, 0x80
.set Led_0__PORT, 12
.set Led_0__PRT, CYREG_PRT12_PRT
.set Led_0__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Led_0__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Led_0__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Led_0__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Led_0__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Led_0__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Led_0__PS, CYREG_PRT12_PS
.set Led_0__SHIFT, 7
.set Led_0__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Led_0__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Led_0__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Led_0__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Led_0__SLW, CYREG_PRT12_SLW

/* Led_1 */
.set Led_1__0__INTTYPE, CYREG_PICU12_INTTYPE6
.set Led_1__0__MASK, 0x40
.set Led_1__0__PC, CYREG_PRT12_PC6
.set Led_1__0__PORT, 12
.set Led_1__0__SHIFT, 6
.set Led_1__AG, CYREG_PRT12_AG
.set Led_1__BIE, CYREG_PRT12_BIE
.set Led_1__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Led_1__BYP, CYREG_PRT12_BYP
.set Led_1__DM0, CYREG_PRT12_DM0
.set Led_1__DM1, CYREG_PRT12_DM1
.set Led_1__DM2, CYREG_PRT12_DM2
.set Led_1__DR, CYREG_PRT12_DR
.set Led_1__INP_DIS, CYREG_PRT12_INP_DIS
.set Led_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Led_1__MASK, 0x40
.set Led_1__PORT, 12
.set Led_1__PRT, CYREG_PRT12_PRT
.set Led_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Led_1__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Led_1__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Led_1__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Led_1__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Led_1__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Led_1__PS, CYREG_PRT12_PS
.set Led_1__SHIFT, 6
.set Led_1__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Led_1__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Led_1__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Led_1__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Led_1__SLW, CYREG_PRT12_SLW

/* Led_2 */
.set Led_2__0__INTTYPE, CYREG_PICU12_INTTYPE5
.set Led_2__0__MASK, 0x20
.set Led_2__0__PC, CYREG_PRT12_PC5
.set Led_2__0__PORT, 12
.set Led_2__0__SHIFT, 5
.set Led_2__AG, CYREG_PRT12_AG
.set Led_2__BIE, CYREG_PRT12_BIE
.set Led_2__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Led_2__BYP, CYREG_PRT12_BYP
.set Led_2__DM0, CYREG_PRT12_DM0
.set Led_2__DM1, CYREG_PRT12_DM1
.set Led_2__DM2, CYREG_PRT12_DM2
.set Led_2__DR, CYREG_PRT12_DR
.set Led_2__INP_DIS, CYREG_PRT12_INP_DIS
.set Led_2__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Led_2__MASK, 0x20
.set Led_2__PORT, 12
.set Led_2__PRT, CYREG_PRT12_PRT
.set Led_2__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Led_2__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Led_2__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Led_2__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Led_2__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Led_2__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Led_2__PS, CYREG_PRT12_PS
.set Led_2__SHIFT, 5
.set Led_2__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Led_2__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Led_2__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Led_2__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Led_2__SLW, CYREG_PRT12_SLW

/* Led_3 */
.set Led_3__0__INTTYPE, CYREG_PICU12_INTTYPE4
.set Led_3__0__MASK, 0x10
.set Led_3__0__PC, CYREG_PRT12_PC4
.set Led_3__0__PORT, 12
.set Led_3__0__SHIFT, 4
.set Led_3__AG, CYREG_PRT12_AG
.set Led_3__BIE, CYREG_PRT12_BIE
.set Led_3__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Led_3__BYP, CYREG_PRT12_BYP
.set Led_3__DM0, CYREG_PRT12_DM0
.set Led_3__DM1, CYREG_PRT12_DM1
.set Led_3__DM2, CYREG_PRT12_DM2
.set Led_3__DR, CYREG_PRT12_DR
.set Led_3__INP_DIS, CYREG_PRT12_INP_DIS
.set Led_3__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Led_3__MASK, 0x10
.set Led_3__PORT, 12
.set Led_3__PRT, CYREG_PRT12_PRT
.set Led_3__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Led_3__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Led_3__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Led_3__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Led_3__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Led_3__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Led_3__PS, CYREG_PRT12_PS
.set Led_3__SHIFT, 4
.set Led_3__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Led_3__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Led_3__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Led_3__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Led_3__SLW, CYREG_PRT12_SLW

/* Led_4 */
.set Led_4__0__INTTYPE, CYREG_PICU12_INTTYPE3
.set Led_4__0__MASK, 0x08
.set Led_4__0__PC, CYREG_PRT12_PC3
.set Led_4__0__PORT, 12
.set Led_4__0__SHIFT, 3
.set Led_4__AG, CYREG_PRT12_AG
.set Led_4__BIE, CYREG_PRT12_BIE
.set Led_4__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Led_4__BYP, CYREG_PRT12_BYP
.set Led_4__DM0, CYREG_PRT12_DM0
.set Led_4__DM1, CYREG_PRT12_DM1
.set Led_4__DM2, CYREG_PRT12_DM2
.set Led_4__DR, CYREG_PRT12_DR
.set Led_4__INP_DIS, CYREG_PRT12_INP_DIS
.set Led_4__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Led_4__MASK, 0x08
.set Led_4__PORT, 12
.set Led_4__PRT, CYREG_PRT12_PRT
.set Led_4__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Led_4__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Led_4__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Led_4__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Led_4__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Led_4__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Led_4__PS, CYREG_PRT12_PS
.set Led_4__SHIFT, 3
.set Led_4__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Led_4__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Led_4__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Led_4__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Led_4__SLW, CYREG_PRT12_SLW

/* Led_5 */
.set Led_5__0__INTTYPE, CYREG_PICU12_INTTYPE2
.set Led_5__0__MASK, 0x04
.set Led_5__0__PC, CYREG_PRT12_PC2
.set Led_5__0__PORT, 12
.set Led_5__0__SHIFT, 2
.set Led_5__AG, CYREG_PRT12_AG
.set Led_5__BIE, CYREG_PRT12_BIE
.set Led_5__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Led_5__BYP, CYREG_PRT12_BYP
.set Led_5__DM0, CYREG_PRT12_DM0
.set Led_5__DM1, CYREG_PRT12_DM1
.set Led_5__DM2, CYREG_PRT12_DM2
.set Led_5__DR, CYREG_PRT12_DR
.set Led_5__INP_DIS, CYREG_PRT12_INP_DIS
.set Led_5__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Led_5__MASK, 0x04
.set Led_5__PORT, 12
.set Led_5__PRT, CYREG_PRT12_PRT
.set Led_5__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Led_5__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Led_5__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Led_5__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Led_5__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Led_5__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Led_5__PS, CYREG_PRT12_PS
.set Led_5__SHIFT, 2
.set Led_5__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Led_5__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Led_5__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Led_5__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Led_5__SLW, CYREG_PRT12_SLW

/* Led_6 */
.set Led_6__0__INTTYPE, CYREG_PICU12_INTTYPE1
.set Led_6__0__MASK, 0x02
.set Led_6__0__PC, CYREG_PRT12_PC1
.set Led_6__0__PORT, 12
.set Led_6__0__SHIFT, 1
.set Led_6__AG, CYREG_PRT12_AG
.set Led_6__BIE, CYREG_PRT12_BIE
.set Led_6__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Led_6__BYP, CYREG_PRT12_BYP
.set Led_6__DM0, CYREG_PRT12_DM0
.set Led_6__DM1, CYREG_PRT12_DM1
.set Led_6__DM2, CYREG_PRT12_DM2
.set Led_6__DR, CYREG_PRT12_DR
.set Led_6__INP_DIS, CYREG_PRT12_INP_DIS
.set Led_6__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Led_6__MASK, 0x02
.set Led_6__PORT, 12
.set Led_6__PRT, CYREG_PRT12_PRT
.set Led_6__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Led_6__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Led_6__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Led_6__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Led_6__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Led_6__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Led_6__PS, CYREG_PRT12_PS
.set Led_6__SHIFT, 1
.set Led_6__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Led_6__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Led_6__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Led_6__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Led_6__SLW, CYREG_PRT12_SLW

/* Led_7 */
.set Led_7__0__INTTYPE, CYREG_PICU12_INTTYPE0
.set Led_7__0__MASK, 0x01
.set Led_7__0__PC, CYREG_PRT12_PC0
.set Led_7__0__PORT, 12
.set Led_7__0__SHIFT, 0
.set Led_7__AG, CYREG_PRT12_AG
.set Led_7__BIE, CYREG_PRT12_BIE
.set Led_7__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Led_7__BYP, CYREG_PRT12_BYP
.set Led_7__DM0, CYREG_PRT12_DM0
.set Led_7__DM1, CYREG_PRT12_DM1
.set Led_7__DM2, CYREG_PRT12_DM2
.set Led_7__DR, CYREG_PRT12_DR
.set Led_7__INP_DIS, CYREG_PRT12_INP_DIS
.set Led_7__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Led_7__MASK, 0x01
.set Led_7__PORT, 12
.set Led_7__PRT, CYREG_PRT12_PRT
.set Led_7__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Led_7__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Led_7__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Led_7__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Led_7__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Led_7__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Led_7__PS, CYREG_PRT12_PS
.set Led_7__SHIFT, 0
.set Led_7__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Led_7__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Led_7__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Led_7__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Led_7__SLW, CYREG_PRT12_SLW

/* Boton2 */
.set Boton2__0__INTTYPE, CYREG_PICU15_INTTYPE4
.set Boton2__0__MASK, 0x10
.set Boton2__0__PC, CYREG_IO_PC_PRT15_PC4
.set Boton2__0__PORT, 15
.set Boton2__0__SHIFT, 4
.set Boton2__AG, CYREG_PRT15_AG
.set Boton2__AMUX, CYREG_PRT15_AMUX
.set Boton2__BIE, CYREG_PRT15_BIE
.set Boton2__BIT_MASK, CYREG_PRT15_BIT_MASK
.set Boton2__BYP, CYREG_PRT15_BYP
.set Boton2__CTL, CYREG_PRT15_CTL
.set Boton2__DM0, CYREG_PRT15_DM0
.set Boton2__DM1, CYREG_PRT15_DM1
.set Boton2__DM2, CYREG_PRT15_DM2
.set Boton2__DR, CYREG_PRT15_DR
.set Boton2__INP_DIS, CYREG_PRT15_INP_DIS
.set Boton2__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set Boton2__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set Boton2__LCD_EN, CYREG_PRT15_LCD_EN
.set Boton2__MASK, 0x10
.set Boton2__PORT, 15
.set Boton2__PRT, CYREG_PRT15_PRT
.set Boton2__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set Boton2__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set Boton2__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set Boton2__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set Boton2__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set Boton2__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set Boton2__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set Boton2__PS, CYREG_PRT15_PS
.set Boton2__SHIFT, 4
.set Boton2__SLW, CYREG_PRT15_SLW

/* Buzzer */
.set Buzzer__0__INTTYPE, CYREG_PICU0_INTTYPE7
.set Buzzer__0__MASK, 0x80
.set Buzzer__0__PC, CYREG_PRT0_PC7
.set Buzzer__0__PORT, 0
.set Buzzer__0__SHIFT, 7
.set Buzzer__AG, CYREG_PRT0_AG
.set Buzzer__AMUX, CYREG_PRT0_AMUX
.set Buzzer__BIE, CYREG_PRT0_BIE
.set Buzzer__BIT_MASK, CYREG_PRT0_BIT_MASK
.set Buzzer__BYP, CYREG_PRT0_BYP
.set Buzzer__CTL, CYREG_PRT0_CTL
.set Buzzer__DM0, CYREG_PRT0_DM0
.set Buzzer__DM1, CYREG_PRT0_DM1
.set Buzzer__DM2, CYREG_PRT0_DM2
.set Buzzer__DR, CYREG_PRT0_DR
.set Buzzer__INP_DIS, CYREG_PRT0_INP_DIS
.set Buzzer__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set Buzzer__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set Buzzer__LCD_EN, CYREG_PRT0_LCD_EN
.set Buzzer__MASK, 0x80
.set Buzzer__PORT, 0
.set Buzzer__PRT, CYREG_PRT0_PRT
.set Buzzer__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set Buzzer__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set Buzzer__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set Buzzer__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set Buzzer__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set Buzzer__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set Buzzer__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set Buzzer__PS, CYREG_PRT0_PS
.set Buzzer__SHIFT, 7
.set Buzzer__SLW, CYREG_PRT0_SLW

/* boton1 */
.set boton1__0__INTTYPE, CYREG_PICU3_INTTYPE7
.set boton1__0__MASK, 0x80
.set boton1__0__PC, CYREG_PRT3_PC7
.set boton1__0__PORT, 3
.set boton1__0__SHIFT, 7
.set boton1__AG, CYREG_PRT3_AG
.set boton1__AMUX, CYREG_PRT3_AMUX
.set boton1__BIE, CYREG_PRT3_BIE
.set boton1__BIT_MASK, CYREG_PRT3_BIT_MASK
.set boton1__BYP, CYREG_PRT3_BYP
.set boton1__CTL, CYREG_PRT3_CTL
.set boton1__DM0, CYREG_PRT3_DM0
.set boton1__DM1, CYREG_PRT3_DM1
.set boton1__DM2, CYREG_PRT3_DM2
.set boton1__DR, CYREG_PRT3_DR
.set boton1__INP_DIS, CYREG_PRT3_INP_DIS
.set boton1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set boton1__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set boton1__LCD_EN, CYREG_PRT3_LCD_EN
.set boton1__MASK, 0x80
.set boton1__PORT, 3
.set boton1__PRT, CYREG_PRT3_PRT
.set boton1__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set boton1__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set boton1__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set boton1__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set boton1__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set boton1__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set boton1__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set boton1__PS, CYREG_PRT3_PS
.set boton1__SHIFT, 7
.set boton1__SLW, CYREG_PRT3_SLW

/* Clock_2 */
.set Clock_2__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set Clock_2__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set Clock_2__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set Clock_2__CFG2_SRC_SEL_MASK, 0x07
.set Clock_2__INDEX, 0x00
.set Clock_2__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock_2__PM_ACT_MSK, 0x01
.set Clock_2__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock_2__PM_STBY_MSK, 0x01

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 26
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E161069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 26
.set CYDEV_CHIP_MEMBER_4AA, 25
.set CYDEV_CHIP_MEMBER_4AB, 30
.set CYDEV_CHIP_MEMBER_4AC, 14
.set CYDEV_CHIP_MEMBER_4AD, 15
.set CYDEV_CHIP_MEMBER_4AE, 16
.set CYDEV_CHIP_MEMBER_4D, 20
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 27
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 24
.set CYDEV_CHIP_MEMBER_4I, 32
.set CYDEV_CHIP_MEMBER_4J, 21
.set CYDEV_CHIP_MEMBER_4K, 22
.set CYDEV_CHIP_MEMBER_4L, 31
.set CYDEV_CHIP_MEMBER_4M, 29
.set CYDEV_CHIP_MEMBER_4N, 11
.set CYDEV_CHIP_MEMBER_4O, 8
.set CYDEV_CHIP_MEMBER_4P, 28
.set CYDEV_CHIP_MEMBER_4Q, 17
.set CYDEV_CHIP_MEMBER_4R, 9
.set CYDEV_CHIP_MEMBER_4S, 12
.set CYDEV_CHIP_MEMBER_4T, 10
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_4V, 23
.set CYDEV_CHIP_MEMBER_4W, 13
.set CYDEV_CHIP_MEMBER_4X, 7
.set CYDEV_CHIP_MEMBER_4Y, 18
.set CYDEV_CHIP_MEMBER_4Z, 19
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 33
.set CYDEV_CHIP_MEMBER_FM3, 37
.set CYDEV_CHIP_MEMBER_FM4, 38
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 34
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 35
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 36
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4AA_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AB_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AC_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AD_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AE_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4T_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4V_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4W_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4X_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Y_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Z_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_ES, 17
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 33
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 33
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000000
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
