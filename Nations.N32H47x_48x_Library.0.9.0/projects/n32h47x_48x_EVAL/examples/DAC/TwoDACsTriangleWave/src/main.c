/**
*     Copyright (c) 2023, Nations Technologies Inc.
* 
*     All rights reserved.
*
*     This software is the exclusive property of Nations Technologies Inc. (Hereinafter 
* referred to as NATIONS). This software, and the product of NATIONS described herein 
* (Hereinafter referred to as the Product) are owned by NATIONS under the laws and treaties
* of the People's Republic of China and other applicable jurisdictions worldwide.
*
*     NATIONS does not grant any license under its patents, copyrights, trademarks, or other 
* intellectual property rights. Names and brands of third party may be mentioned or referred 
* thereto (if any) for identification purposes only.
*
*     NATIONS reserves the right to make changes, corrections, enhancements, modifications, and 
* improvements to this software at any time without notice. Please contact NATIONS and obtain 
* the latest version of this software before placing orders.

*     Although NATIONS has attempted to provide accurate and reliable information, NATIONS assumes 
* no responsibility for the accuracy and reliability of this software.
* 
*     It is the responsibility of the user of this software to properly design, program, and test 
* the functionality and safety of any application made of this information and any resulting product. 
* In no event shall NATIONS be liable for any direct, indirect, incidental, special,exemplary, or 
* consequential damages arising in any way out of the use of this software or the Product.
*
*     NATIONS Products are neither intended nor warranted for usage in systems or equipment, any
* malfunction or failure of which may cause loss of human life, bodily injury or severe property 
* damage. Such applications are deemed, "Insecure Usage".
*
*     All Insecure Usage shall be made at user's risk. User shall indemnify NATIONS and hold NATIONS 
* harmless from and against all claims, costs, damages, and other liabilities, arising from or related 
* to any customer's Insecure Usage.

*     Any express or implied warranty with regard to this software or the Product, including,but not 
* limited to, the warranties of merchantability, fitness for a particular purpose and non-infringement
* are disclaimed to the fullest extent permitted by law.

*     Unless otherwise explicitly permitted by NATIONS, anyone may not duplicate, modify, transcribe
* or otherwise distribute this software for any purposes, in whole or in part.
*
*     NATIONS products and technologies shall not be used for or incorporated into any products or systems
* whose manufacture, use, or sale is prohibited under any applicable domestic or foreign laws or regulations. 
* User shall comply with any applicable export control laws and regulations promulgated and administered by 
* the governments of any countries asserting jurisdiction over the parties or transactions.
**/

/**
*\*\file main.c
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved.
 */
#include "main.h"



void RCC_Configuration(void);
void GPIO_Configuration(void);
void DAC_Configuratoin(void);
void ATIM1_Init(void);
/**
*\*\name    main.
*\*\fun     main program.
*\*\return  none
**/
int main(void)
{
    /* System clocks configuration ---------------------------------------------*/
    RCC_Configuration();

    /* GPIO configuration ------------------------------------------------------*/
    GPIO_Configuration();

    /* DAC configuration ------------------------------------------------------*/
    DAC_Configuratoin();
    
    /* ATIM1 configuration ------------------------------------------------------*/
    ATIM1_Init();
    
    /* ATIM1 enable counter */
    TIM_Enable(ATIM1, ENABLE);
    
    while (1)
    {
    }
}

/**
*\*\name    DAC_Configuratoin.
*\*\fun     Configures the DAC1 module.
*\*\return  none
**/
void DAC_Configuratoin(void)
{
    DAC_InitType DAC_InitStructure;

    DAC_StructInit(&DAC_InitStructure);
    /* DAC1 Configuration */
    DAC_InitStructure.DAC_Trigger                       = DAC_Trigger_ATIM1_TRGO;
    DAC_InitStructure.DAC_WaveGeneration                = DAC_WaveGeneration_Triangle;
    DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude  = DAC_TriangleAmplitude_2047;
    DAC_InitStructure.DAC_OutputBuffer                  = DISABLE;
    DAC_InitStructure.DAC_ConnectOnChipPeripheral       = DISABLE;
    DAC_InitStructure.DAC_ConnectExternalPin            = ENABLE;
    DAC_InitStructure.DAC_TriggerEnable                 = ENABLE;
    DAC_Init(DAC1, &DAC_InitStructure);
    
    /* DAC2 Configuration */
    DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude  = DAC_TriangleAmplitude_1023;
    DAC_Init(DAC2, &DAC_InitStructure);
    
    /* Set DAC1 DAC2 DHR12R register */
    DAC_SetDualChData(DAC12,DAC_ALIGN_R_12BIT, 0x100, 0x100);
    /* Enable DAC1  */
    DAC_Enable(DAC1, ENABLE);
    /* Enable DAC2  */
    DAC_Enable(DAC2, ENABLE);
}
void ATIM1_Init(void)
{
    TIM_TimeBaseInitType TIM_TimeBaseStructure;
    uint16_t PrescalerValue ;
    PrescalerValue = (uint32_t)(SystemCoreClock / 16000000) - 1;
    /* ATIM1 Configuration */
    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.Period    = 16-1;
    TIM_TimeBaseStructure.Prescaler = PrescalerValue;
    TIM_TimeBaseStructure.ClkDiv    = TIM_CLK_DIV1;
    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;
    TIM_InitTimeBase(ATIM1, &TIM_TimeBaseStructure);

    /* ATIM1 TRGO selection */
    TIM_SelectOutputTrig(ATIM1, TIM_TRGO_SRC_UPDATE);
}
/**
*\*\name    RCC_Configuration.
*\*\fun     Configures the different system clocks.
*\*\return  none
**/
void RCC_Configuration(void)
{
    /* Enable GPIOA, GPIOB, GPIOC clocks */
    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOA | RCC_AHB_PERIPHEN_GPIOB | RCC_AHB_PERIPHEN_GPIOC, ENABLE);
    /* Enable ATIM1 clocks */
    RCC_EnableAHBPeriphClk(RCC_AHB_PERIPHEN_ATIM1, ENABLE);
    
    /* Enable DAC1 DAC2 clocks */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_DAC12 ,ENABLE);
    /* Config DAC12 prescaler factor,DAC_CLK = 1M*/
    #if defined (N32H473) || defined (N32H474)
    DAC_ConfigClkPrescaler(DAC12,100);
    #elif defined (N32H475) || defined (N32H482) || defined (N32H487) 
    DAC_ConfigClkPrescaler(DAC12,120);
    #endif
    DAC_SetHighFrequencyMode(DAC12,DAC_HIGH_FREQ_MODE_BELOW_160M);
}

/**
*\*\name    GPIO_Configuration.
*\*\fun     Configures the different GPIO ports.
*\*\return  none
**/
void GPIO_Configuration(void)
{
    GPIO_InitType GPIO_InitStructure;
    // DAC1_OUT DAC2_OUT
    GPIO_InitStructure.Pin        = GPIO_PIN_4 | GPIO_PIN_5 ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_ANALOG;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
}


