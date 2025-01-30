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
*\*\file n32h47x_48x_msp.c
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved.
**/
#include "n32h47x_48x_msp.h"

/**
*\*\name    SHRTPLL_Init.
*\*\fun     Config SHRTPLL clock
*\*\param   SHRTPLL_source
*\*\          - RCC_SHRTPLL_SRC_HSI         HSI oscillator clock selected as SHRTPLL clock entry
*\*\          - RCC_SHRTPLL_SRC_HSE         HSE oscillator clock selected as SHRTPLL clock entry
*\*\param   fin(SHRTPLL input frequency):
*\*\         1000000 ~ 50000000 (Hz)
*\*\param   fout(SHRTPLL output frequency):
*\*\         75000000 ~ 250000000 (Hz)
*\*\return  none 
**/
static void SHRTPLL_Init(uint32_t SHRTPLL_source, uint64_t fin, uint64_t fout)
{
    ErrorStatus ClockStatus;

    if(SHRTPLL_source == RCC_SHRTPLL_SRC_HSE)
    {
        /* Enable HSE */
        RCC_ConfigHse(RCC_HSE_ENABLE);

        /* Wait till HSE is ready */
        ClockStatus = RCC_WaitHseStable();
           
    }
    else
    {
        /* Enable HSI */
        RCC_EnableHsi(ENABLE);

        /* Wait till HSI is ready */
        ClockStatus = RCC_WaitHsiStable();
    }
    
    if(ClockStatus != SUCCESS)
    {
        /* clock source fails to start-up */
        while (1)
        {
        }
    }

    /* Enable Prefetch Buffer */
    if(RCC_ConfigSHRTPll(SHRTPLL_source, fin, fout, ENABLE) == SUCCESS)
    {
        
         /* Wait till SHRTPLL is used as system clock source */
        while (RCC_GetFlagStatus(RCC_FLAG_SHRTPLLRDF) != SET)
        {
        }
    }
    else
    {
        /* SHRTPLL fails  */
        while (1)
        {
        }
    }
}

/**
*\*\name  SHRTIM1_MspInit
*\*\param  None
*\*\return None
**/
void SHRTIM1_MspInit(void)
{
    GPIO_InitType GPIO_InitStructure;
    GPIO_InitStruct(&GPIO_InitStructure);

    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOA, ENABLE);
    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOB, ENABLE);

    /* Configure SHRTIM output: TA2 (PA9) */
    GPIO_InitStructure.Pin = GPIO_PIN_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Slew_Rate = GPIO_SLEW_RATE_FAST;
    GPIO_InitStructure.GPIO_Pull = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF6;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    /* Configure SHRTIM output: TB1 (PA10) */
    GPIO_InitStructure.Pin = GPIO_PIN_10;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF12;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    /* Configure SHRTIM output: TC2 (PB13) */
    GPIO_InitStructure.Pin = GPIO_PIN_13;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF10;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);

    /* Configure SHRTIM output: TD1 (PB14) */
    GPIO_InitStructure.Pin = GPIO_PIN_14;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF10;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);

    /* Configure SHRTIM output: TD2 (PB15) */
    GPIO_InitStructure.Pin = GPIO_PIN_15;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF10;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);

    /* Configure SHRTIM input: FAULT1 (PA12) */
    GPIO_InitStructure.Pin = GPIO_PIN_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Pull = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Slew_Rate  = GPIO_SLEW_RATE_FAST;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF12;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    /* Configure and enable SHRTIM MASTER timer interrupt channel in NVIC */
    NVIC_SetPriority(SHRT1_MST_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
    NVIC_EnableIRQ(SHRT1_MST_IRQn);

    /* Initialize SHRTPLL */
    SHRTPLL_Init(RCC_SHRTPLL_SRC_HSE, HSE_VALUE, SHRTIM_INPUT_CLOCK);

    RCC_EnableAHBPeriphClk(RCC_AHB_PERIPHEN_SHRTIM, ENABLE);

}

/**
*\*\name ADC_MspInit
*\*\param none
*\*\retval none
*\*/
void ADC_MspInit(void)
{
    GPIO_InitType GPIO_InitStructure;
    DMA_InitType DMA_InitStructure;

    RCC_EnableAHBPeriphClk(RCC_AHB_PERIPHEN_DMA1, ENABLE);
    
    /* Enable GPIOA and ADC1 clocks */
    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOA | RCC_AHB_PERIPHEN_ADC1, ENABLE);

    /* Enable AFIO clocks */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_AFIO, ENABLE);
    
    /* RCC_ADCHCLK_DIV3*/
    ADC_ConfigClk(ADC_CTRL3_CKMOD_AHB, RCC_ADCHCLK_DIV3);
    
    /* selsect HSI as RCC ADC1M CLK Source */
    RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8);
    
    /* Configure PA0  as analog input ------------------------------*/
    GPIO_InitStruct(&GPIO_InitStructure);
    GPIO_InitStructure.Pin       = GPIO_PIN_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_ANALOG;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
    
    /* DMA channel1 configuration ----------------------------------------------*/
    DMA_StructInit(&DMA_InitStructure);
    DMA_DeInit(DMA1_CH1);
    DMA_InitStructure.Direction      = DMA_DIR_PERIPH_SRC;
    DMA_InitStructure.PeriphInc      = DMA_PERIPH_INC_DISABLE;
    DMA_InitStructure.MemoryInc      = DMA_MEM_INC_ENABLE;
    DMA_InitStructure.PeriphDataSize = DMA_PERIPH_DATA_WIDTH_HALFWORD;
    DMA_InitStructure.MemDataSize    = DMA_MEM_DATA_WIDTH_HALFWORD;//DMA_MEM_DATA_WIDTH_BYTE
    DMA_InitStructure.CircularMode   = DMA_MODE_CIRCULAR;
    DMA_InitStructure.Priority       = DMA_PRIORITY_HIGH;
    DMA_InitStructure.Mem2Mem        = DMA_M2M_DISABLE;
    
    DMA_Init(DMA1_CH1, &DMA_InitStructure);
    
    DMA_RequestRemap(DMA_REMAP_ADC1, DMA1_CH1, ENABLE);
}
