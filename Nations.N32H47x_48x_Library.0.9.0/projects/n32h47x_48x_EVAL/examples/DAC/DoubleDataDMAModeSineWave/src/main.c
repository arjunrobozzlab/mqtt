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


const uint16_t Sine12bit[32] = {2047, 2447, 2831, 3185, 3498, 3750, 3939, 4056, 4095, 4056, 3939,
                                3750, 3495, 3185, 2831, 2447, 2047, 1647, 1263, 909,  599,  344,
                                155,  38,   0,    38,   155,  344,  599,  909,  1263, 1647};
uint32_t Sine32bit[16] = {0};

                                
void RCC_Configuration(void);
void GPIO_Configuration(void);
void DAC_Configuratoin(void);
void DMA_Config(void);
void GTIM1_Init(void);

/**
*\*\name    main.
*\*\fun     main program.
*\*\return  none
**/
int main(void)
{
    uint8_t index = 0;
    /* System clocks configuration ---------------------------------------------*/
    RCC_Configuration();

    /* GPIO configuration ------------------------------------------------------*/
    GPIO_Configuration();
    
    /* DMA1 channel1 configuration ---------------------------------------------*/
    DMA_Config();

    /* DAC configuration -------------------------------------------------------*/
    DAC_Configuratoin();
    
    /* GTIM1 configuration -----------------------------------------------------*/
    GTIM1_Init();
    
    /* Fill Sine32bit table */
    for (index = 0; index < 16; index++ )
    {
        Sine32bit[index] = (Sine12bit[2*index+1] << 16) + (Sine12bit[2*index]);
    }
    /* Enable DMA1 channel1 */
    DMA_EnableChannel(DMA1_CH1, ENABLE);
    
    TIM_Enable(GTIM1, ENABLE);
    while (1)
    {

    }
}
/**
*\*\name    GTIM1_Init.
*\*\fun     Configures the GTIM1 as DAC trigger source.
*\*\return  none
**/
void GTIM1_Init(void)
{
    TIM_TimeBaseInitType TIM_TimeBaseStructure;
    uint16_t  PrescalerValue ;
    PrescalerValue = (uint32_t)(SystemCoreClock / 16000000) - 1;
    /* GTIM1 Configuration */
    /* Time base configuration */
    TIM_InitTimBaseStruct(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.Period    = 16-1; 
    TIM_TimeBaseStructure.Prescaler = PrescalerValue;
    TIM_TimeBaseStructure.ClkDiv    = TIM_CLK_DIV1;
    TIM_TimeBaseStructure.CounterMode   = TIM_CNT_MODE_UP;
    TIM_InitTimeBase(GTIM1, &TIM_TimeBaseStructure);

    /* GTIM1 TRGO selection */
    TIM_SelectOutputTrig(GTIM1, TIM_TRGO_SRC_UPDATE);
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
    DAC_InitStructure.DAC_Trigger                       = DAC_Trigger_GTIM1_TRGO;
    DAC_InitStructure.DAC_WaveGeneration                = DAC_WaveGeneration_None;
    DAC_InitStructure.DAC_DMADoubleDataMode             = ENABLE;
    DAC_InitStructure.DAC_OutputBuffer                  = DISABLE;
    DAC_InitStructure.DAC_ConnectOnChipPeripheral       = DISABLE;
    DAC_InitStructure.DAC_ConnectExternalPin            = ENABLE;
    DAC_InitStructure.DAC_TriggerEnable                 = ENABLE;
    DAC_Init(DAC1, &DAC_InitStructure);
    /* Enable DAC1 DMA function */
    DAC_DmaEnable(DAC1, ENABLE);
    /* Enable DAC1  */
    DAC_Enable(DAC1, ENABLE);
}

/**
*\*\name    RCC_Configuration.
*\*\fun     Configures the different system clocks.
*\*\return  none
**/
void RCC_Configuration(void)
{
    /* Enable peripheral clocks ------------------------------------------------*/
    /* Enable DMA1 clocks */
    RCC_EnableAHBPeriphClk(RCC_AHB_PERIPHEN_DMA1, ENABLE);
    /* Enable GPIOA, GPIOB, GPIOC clocks */
    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOA | RCC_AHB_PERIPHEN_GPIOB | RCC_AHB_PERIPHEN_GPIOC, ENABLE);
    
    /* Enable DAC1 DAC2 GTIM1 clocks */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_DAC12 | RCC_APB1_PERIPH_GTIM1 ,ENABLE);
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
    /* DAC1_OUT  */
    GPIO_InitStructure.Pin        = GPIO_PIN_4 ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_ANALOG;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
}

/**
*\*\name    DMA_Config.
*\*\fun     DMA_Initial program.
*\*\return  none
**/
void DMA_Config(void)
{
    DMA_InitType DMA_InitStructure;
    DMA_StructInit(&DMA_InitStructure);
    DMA_InitStructure.PeriphAddr     = (uint32_t)&DAC12->DR12CH1;
    DMA_InitStructure.MemAddr        = (uint32_t)Sine32bit;
    DMA_InitStructure.Direction      = DMA_DIR_PERIPH_DST;
    DMA_InitStructure.BufSize        = 16;
    DMA_InitStructure.PeriphInc      = DMA_PERIPH_INC_DISABLE;
    DMA_InitStructure.MemoryInc      = DMA_MEM_INC_ENABLE;
    DMA_InitStructure.PeriphDataSize = DMA_PERIPH_DATA_WIDTH_WORD;
    DMA_InitStructure.MemDataSize    = DMA_MEM_DATA_WIDTH_WORD;
    DMA_InitStructure.CircularMode   = DMA_MODE_CIRCULAR;
    DMA_InitStructure.Priority       = DMA_PRIORITY_HIGH;
    DMA_InitStructure.Mem2Mem        = DMA_M2M_DISABLE;
    DMA_Init(DMA1_CH1, &DMA_InitStructure);
    
    DMA_RequestRemap(DMA_REMAP_DAC1_DMA,DMA1_CH1,ENABLE);
}
