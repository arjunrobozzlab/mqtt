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
#include "main.h"
#include "misc.h"
#include "log.h"
#include <stdio.h>
#include "n32h47x_48x_rcc.h"
#include "n32h47x_48x_gpio.h"
#include "n32h47x_48x_exti.h"

/**
**  NVIC IRQ Priority
**/

__IO uint8_t PreemptionPriorityValue = 0;
__IO uint8_t Key_Status              = 0;

/**
*\*\name   main
*\*\fun    Main program.
*\*\return none
**/
int main(void)
{    
    /* log Init */
    log_init();
    log_info("NVIC IRQ Priority \r\n");

    KeyInputExtiInit(KEY_INPUT_PORT, KEY_INPUT_PIN);
    /* Configure the SysTick Handler Priority: Preemption priority(0) and subpriority */
    NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptionPriorityValue, 0));

    while (1)
    {
        if (Key_Status == 1)
        {
            log_info("Key_Status = 1 \r\n");
            /* Configure the SysTick Handler Priority: Preemption priority(2) and subpriority */
            NVIC_SetPriority(SysTick_IRQn,
                             NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptionPriorityValue + 2, 0));
        }
        else if (Key_Status == 2)
        {
            log_info("NVIC IRQ Priority Test End \r\n");
        }
        else
        {
            log_info("Key_Status = 0 \r\n");
        }

        /* Insert delay Time */
        Delay(0x8FFFFF);
    }
  
}

void KeyInputExtiInit(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_InitType GPIO_InitStructure;
    EXTI_InitType EXTI_InitStructure;
    NVIC_InitType NVIC_InitStructure;

    /* Enable the GPIO Clock */
    RCC_EnableAHB1PeriphClk(KEY_INPUT_PORT_CLK,ENABLE);
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_AFIO,ENABLE);


    /*Configure the GPIO pin as input floating*/
    GPIO_InitStructure.Pin        = Pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_INPUT;
    GPIO_InitStructure.GPIO_Pull  = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Slew_Rate = GPIO_SLEW_RATE_FAST;
    GPIO_InitPeripheral(GPIOx, &GPIO_InitStructure);

    /*Configure key EXTI Line to key input Pin*/
    GPIO_ConfigEXTILine(KEY_INPUT_LIN_SOURCE, KEY_INPUT_PORT_SOURCE,KEY_INPUT_PIN_SOURCE);

    /*Configure key EXTI line*/
    EXTI_InitStructure.EXTI_Line    = KEY_INPUT_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);
    
    /* Configure two bits for preemption priority */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    /*Set key input interrupt priority*/
    NVIC_InitStructure.NVIC_IRQChannel                   = KEY_INPUT_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x00;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}


/**
*\*\name    EXTIx_IRQHandler.
*\*\fun     This function handles EXTIx exception.
*\*\param   none
*\*\return  none 
**/
#ifdef N32H487
void EXTI15_10_IRQHandler(void)
{
    log_info("EXTI15 IRQHandler Start \r\n");
    if (EXTI_GetITStatus(KEY_INPUT_EXTI_LINE) != RESET)
    {
        /* Generate SysTick exception */
        SCB->ICSR |= 0x04000000;

        /* Clears the SEL Button EXTI line pending bits */
        EXTI_ClrStatusFlag(KEY_INPUT_EXTI_LINE);
    }
    log_info("EXTI15 IRQHandler End \r\n");
}
#else
void EXTI4_IRQHandler(void)
{
    log_info("EXTI4 IRQHandler Start \r\n");
    if (EXTI_GetITStatus(KEY_INPUT_EXTI_LINE) != RESET)
    {
        /* Generate SysTick exception */
        SCB->ICSR |= 0x04000000;

        /* Clears the SEL Button EXTI line pending bits */
        EXTI_ClrStatusFlag(KEY_INPUT_EXTI_LINE);
    }
    log_info("EXTI4 IRQHandler End \r\n");
    
}
#endif


/**
\*\*fun  Inserts a delay time.
\*\*param nCount specifies the delay time length.
**/
void Delay(__IO uint32_t nCount)
{
    for (; nCount != 0; nCount--)
        ;
}

