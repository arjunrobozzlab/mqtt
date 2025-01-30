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
*\*\file usbhs_bsp.h
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved.
**/
#ifndef __USBHS_BSP__H__
#define __USBHS_BSP__H__

#include "usbhs_core.h"


#define LED1_PORT   GPIOA
#define LED1_PIN    GPIO_PIN_3
#define LED1_CLOCK  RCC_AHB_PERIPHEN_GPIOA

#define LED2_PORT   GPIOA
#define LED2_PIN    GPIO_PIN_8
#define LED2_CLOCK  RCC_AHB_PERIPHEN_GPIOA

#define KEY_BUTTON_S2_GPIO_PORT          GPIOC
#define KEY_BUTTON_S2_GPIO_CLK           RCC_AHB_PERIPHEN_GPIOC
#define KEY_BUTTON_S2_PIN                GPIO_PIN_13

#define KEY_BUTTON_S3_GPIO_PORT          GPIOA
#define KEY_BUTTON_S3_GPIO_CLK           RCC_AHB_PERIPHEN_GPIOA
#define KEY_BUTTON_S3_PIN                GPIO_PIN_15

#define KEY_BUTTON_S4_GPIO_PORT          GPIOC
#define KEY_BUTTON_S4_GPIO_CLK           RCC_AHB_PERIPHEN_GPIOC
#define KEY_BUTTON_S4_PIN                GPIO_PIN_8


void LED_Init(GPIO_Module* GPIOx,uint16_t Pin,uint32_t clock);
void LED_On(GPIO_Module* GPIOx,uint16_t Pin);
void LED_Off(GPIO_Module* GPIOx,uint16_t Pin);
void LED_Blink(GPIO_Module* GPIOx,uint16_t Pin);

void USB_BSP_Init(void);
void USB_BSP_uDelay(const uint32_t usec);
void USB_BSP_mDelay(const uint32_t msec);
void USB_BSP_EnableInterrupt(USB_CORE_MODULE *USBx);

#endif /* __USBHS_BSP__H__ */


