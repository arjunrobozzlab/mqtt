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
*\*\file usbhs_bsp.c
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved.
**/

#include "usbhs_bsp.h"
#include "usbhs_core.h"
#include "n32h47x_48x_gpio.h"
#include "n32h47x_48x_rcc.h"
#include "n32h47x_48x_exti.h"
#include "misc.h"

/**
*\*\name   KEY_Init.
*\*\fun    Initialize a GPIO as KEY port.
*\*\param  none
*\*\return none
*/
void KEY_Init(void)
{
    GPIO_InitType GPIO_InitStructure;
    
    RCC_EnableAHB1PeriphClk(KEY_BUTTON_GPIO_CLK | KEY_BUTTON_UP_CLK | KEY_BUTTON_DOWN_CLK | KEY_BUTTON_LEFT_CLK | KEY_BUTTON_RIGHT_CLK| KEY_BUTTON_SEL_CLK, ENABLE);
    
    GPIO_InitStruct(&GPIO_InitStructure);

    GPIO_InitStructure.Pin            = KEY_BUTTON_PIN;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitStructure.GPIO_Pull      = GPIO_PULL_DOWN;
    GPIO_InitPeripheral(KEY_BUTTON_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin            = KEY_BUTTON_UP_PIN ;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(KEY_BUTTON_UP_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.Pin            = KEY_BUTTON_DOWN_PIN ;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(KEY_BUTTON_DOWN_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.Pin            = KEY_BUTTON_LEFT_PIN ;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(KEY_BUTTON_LEFT_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.Pin            = KEY_BUTTON_RIGHT_PIN ;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(KEY_BUTTON_RIGHT_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.Pin            = KEY_BUTTON_SEL_PIN ;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(KEY_BUTTON_SEL_PORT, &GPIO_InitStructure);
}

/**
*\*\name    USB_BSP_Init.
*\*\fun     Initializes BSP configurations
*\*\param   none.
*\*\return  none.
*\*\
**/
void USB_BSP_Init(void)
{
    GPIO_InitType GPIO_InitStructure;

    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOA | RCC_AHB_PERIPHEN_GPIOB, ENABLE);

    /* Configure VBUS SOF ID Pins */
    GPIO_InitStruct(&GPIO_InitStructure);
    
    //set vbus
	GPIO_InitStructure.Pin              = GPIO_PIN_13;
    GPIO_InitStructure.GPIO_Mode        = GPIO_MODE_INPUT;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
   
    // SOF
    GPIO_InitStructure.Pin              = GPIO_PIN_4;
    GPIO_InitStructure.GPIO_Mode        = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate   = 8;  //SOF
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    // ID
    GPIO_InitStructure.Pin              = GPIO_PIN_12;
    GPIO_InitStructure.GPIO_Mode        = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate   = 14;  //ID
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);

    KEY_Init();
}

/**
*\*\name    USB_BSP_EnableInterrupt.
*\*\fun     Enable USB HS interrupt
*\*\param   none.
*\*\return  none.
*\*\
**/
void USB_BSP_EnableInterrupt(USB_CORE_MODULE *USBx)
{
    NVIC_InitType NVIC_InitStructure;
    EXTI_InitType EXTI_InitStructure;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitStructure.NVIC_IRQChannel = USB_HS_WKUP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);     

    NVIC_InitStructure.NVIC_IRQChannel = USB_HS_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    /* Configure the EXTI line 23 connected internally to the USBHS IP */
    EXTI_ClrITPendBit(EXTI_LINE23);
    EXTI_InitStructure.EXTI_Line    = EXTI_LINE23; 
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);
}

/**
*\*\name    USB_BSP_DriveVBUS.
*\*\fun     Drives the Vbus signal through IO
*\*\param   none.
*\*\return  none.
**/
void USB_BSP_DriveVBUS(USB_CORE_MODULE * pdev, uint8_t state)
{
    if(state)
    {
        GPIO_SetBits(USB_VBUS_DRIVER_PORT, USB_VBUS_DRIVER_PIN);
    }
    else
    {
        GPIO_ResetBits(USB_VBUS_DRIVER_PORT, USB_VBUS_DRIVER_PIN);
    }
}

/**
*\*\name    USB_BSP_ConfigVBUS.
*\*\fun     Configures the IO for the Vbus
*\*\param   none.
*\*\return  none.
**/
void USB_BSP_ConfigVBUS(USB_CORE_MODULE * pdev)
{
    GPIO_InitType GPIO_InitStructure;
    RCC_EnableAHB1PeriphClk(USB_VBUS_DRIVER_CLK, ENABLE);

    GPIO_ConfigPinRemap(0, 0, GPIO_RMP_SWJ_SWD);
    
    /* Configure VBUS driver Pin */
    GPIO_InitStruct(&GPIO_InitStructure);
    
    GPIO_InitStructure.Pin          = USB_VBUS_DRIVER_PIN;
    GPIO_InitStructure.GPIO_Mode    = GPIO_MODE_OUTPUT_PP;
    GPIO_InitPeripheral(USB_VBUS_DRIVER_PORT, &GPIO_InitStructure);
}

/**
*\*\name    USB_BSP_uDelay.
*\*\fun     This function provides delay time in micro sec
*\*\param   usec : Value of delay required in micro sec.
*\*\return  none.
*\*\
**/
void USB_BSP_uDelay (const uint32_t usec)
{
    uint32_t i, j;
    j = 30 * usec;
    for (i = 0UL; i < j; i++) 
    {
    }
}

/**
*\*\name    USB_BSP_mDelay.
*\*\fun     This function provides delay time in milli sec
*\*\param   usec : Value of delay required in milli sec.
*\*\return  none.
*\*\
**/
void USB_BSP_mDelay (const uint32_t msec)
{
    USB_BSP_uDelay(msec * 1000);
}
