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
**/

#include "n32h47x_48x_lptim.h"
#include "n32h47x_48x_pwr.h"
#include "n32h47x_48x_it.h"
#include "delay.h"
#include "log.h"


uint32_t NencCNT = 0U;


/**
*\*\name    LptimInOutPinConfig.
*\*\fun     Initialize configuration input/output pins.
*\*\param   none
*\*\return  none
**/
void LptimInOutPinConfig(void)
{
    GPIO_InitType GPIO_InitStructure;

    /* Enable the GPIO Clock */
    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOB, ENABLE);
    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOC, ENABLE);

    GPIO_InitStruct(&GPIO_InitStructure);
    /* Configure the GPIO pin */
    GPIO_InitStructure.Pin            = GPIO_PIN_0;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF5;
    GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);
    /* Configure the GPIO pin */
    GPIO_InitStructure.Pin            = GPIO_PIN_2;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF5;
    GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);
    
    /* Configure the GPIO pin */
    GPIO_InitStructure.Pin            = GPIO_PIN_0;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.GPIO_Alternate = GPIO_NO_AF;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
    /* Configure the GPIO pin */
    GPIO_InitStructure.Pin            = GPIO_PIN_1;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
}

/**
*\*\name    LptimNoEncodeConfig.
*\*\fun     Initialize configuration LPTIM Non-encoder mode.
*\*\param   none
*\*\return  none
**/
void LptimNoEncodeConfig(void)
{
    /* Reset LPTIM1 */
    LPTIM_DeInit(LPTIM1);
    /* Set the actual prescaler division ratio to 1 */
    LPTIM_SetPrescaler(LPTIM1, LPTIM_PRESCALER_DIV1);
    /* Set the source of the clock used by LPTIM1 */
    LPTIM_SetClockSource(LPTIM1, LPTIM_CLK_SOURCE_INTERNAL);
    /* Enables the Non-encoder mode of LPTIM1 */
    LPTIM_NoEncoderModeCmd(LPTIM1, ENABLE);
    /* Configure clock polarity in encoder mode */
    LPTIM_SetEncoderModeClockPolarity(LPTIM1, LPTIM_ENCODER_MODE_FALLING);
    /* Enables LPTIM1 */
    LPTIM_Cmd(LPTIM1, ENABLE);
    /* Set the auto reload value */
    LPTIM_SetAutoReloadValue(LPTIM1, 15000U);
    /* Set the compare value */
    LPTIM_SetCompareValue(LPTIM1, 10000U);
}

/**
*\*\name    LptimNoEncodeWaveOutput.
*\*\fun     Generate Non-encoder waves output.
*\*\param   Count
*\*\          - The number of waves
*\*\return  none
**/
void LptimNoEncodeWaveOutput(uint16_t Count)
{
    while(Count--)
    {
        GPIO_SetBits(GPIOB, GPIO_PIN_0);
        systick_delay_ms(2U);
        GPIO_ResetBits(GPIOB, GPIO_PIN_0);
        systick_delay_ms(2U);
        GPIO_SetBits(GPIOB, GPIO_PIN_1);
        systick_delay_ms(2U);
        GPIO_ResetBits(GPIOB, GPIO_PIN_1);
        systick_delay_ms(2U);
    }
}

/**
*\*\name    main.
*\*\fun     Main program.
*\*\param   none
*\*\return  none 
**/
int main(void)
{
    log_init();
    
    log_info("LPTIM_NENC demo go...\n");
    
    /* Enable PWR peripheral clock */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_PWR, ENABLE);
    /* Enable access to backup registers */
    PWR_BackupAccessEnable(ENABLE);

    /* Enable LSI */
    RCC_EnableLsi(ENABLE);
    /* Configure the LSI as the clock source for LPTIM1 */
    RCC_ConfigLPTIM1Clk(RCC_LPTIMCLK_SRC_LSI);
    
    /* Enable LPTIM1 peripheral clock */
    RCC_EnableLPTIMPeriphClk(RCC_LPTIM1_PERIPH_EN, ENABLE);
    
    /* Input pin config */
    /* IN1: PC0, IN2: PC2 */
    /* Waves OUT1: PB0, Waves OUT2: PB1 */
    LptimInOutPinConfig();
    /* Non-encoder mode config */
    LptimNoEncodeConfig();
    
    /* Start counting in continuous mode */
    LPTIM_StartCounter(LPTIM1, LPTIM_OPERATING_MODE_CONTINUOUS);

    /* Great 20 square waves ,and NencCNT should be equal to 20 */
    LptimNoEncodeWaveOutput(20U);

    /* Get actual counter value */
    NencCNT = LPTIM_GetCounterValue(LPTIM1);
    if (NencCNT != 20U)
    {
        log_info("LPTIM_NENC demo failed!!!\n");
    }
    else
    {
        log_info("LPTIM_NENC demo success!!!\n");
    }

    while (1);
}


