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
*\*\file main.h
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved.
**/
#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32h47x_48x.h"
#include "n32h47x_48x_exti.h"
#include "n32h47x_48x_gpio.h"
#include "n32h47x_48x_tim.h"
#include "n32h47x_48x_rcc.h"
#include "misc.h"


#define TIMx                   ATIM1
#define TIMx_CLK               RCC_AHB_PERIPHEN_ATIM1

#define TIMx_CH1_GPIO_CLK      RCC_AHB_PERIPHEN_GPIOA
#define TIMx_CH1_GPIO_PORT     GPIOA
#define TIMx_CH1_GPIO_PIN      GPIO_PIN_8
#define TIMx_CH1_GPIO_AF       GPIO_AF3

#define TIMx_CH2_GPIO_CLK      RCC_AHB_PERIPHEN_GPIOA
#define TIMx_CH2_GPIO_PORT     GPIOA
#define TIMx_CH2_GPIO_PIN      GPIO_PIN_9
#define TIMx_CH2_GPIO_AF       GPIO_AF3

#define TIMy                   GTIM5
#define TIMy_CLK               RCC_APB1_PERIPH_GTIM5
#define TIMy_CH1_GPIO_CLK      RCC_AHB_PERIPHEN_GPIOA
#define TIMy_CH1_GPIO_PORT     GPIOA
#define TIMy_CH1_GPIO_PIN      GPIO_PIN_2
#define TIMy_CH1_GPIO_AF       GPIO_AF7

#define TIMz                   GTIM6
#define TIMz_CLK               RCC_APB1_PERIPH_GTIM6
#define TIMz_CH1_GPIO_CLK      RCC_AHB_PERIPHEN_GPIOD
#define TIMz_CH1_GPIO_PORT     GPIOD
#define TIMz_CH1_GPIO_PIN      GPIO_PIN_5
#define TIMz_CH1_GPIO_AF       GPIO_AF5




void RCC_Configuration(void);
void GPIO_Configuration(void);



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

