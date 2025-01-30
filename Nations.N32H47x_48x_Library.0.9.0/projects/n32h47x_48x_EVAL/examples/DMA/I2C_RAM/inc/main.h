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
 */

#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif


typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} Status;

#define LED_GPIO                 GPIOA
#define LED_GPIO_CLK             RCC_AHB_PERIPHEN_GPIOA
#define LED_PIN                  GPIO_PIN_3

#if defined (N32H475)

#define USER1_I2C                I2C1
#define USER1_I2C_CLK            RCC_APB1_PERIPH_I2C1
#define USER1_I2C_GPIO           GPIOG
#define USER1_I2C_GPIO_CLK       RCC_AHB_PERIPHEN_GPIOG
#define USER1_I2C_PIN_SCL        GPIO_PIN_14
#define USER1_I2C_PIN_SDA        GPIO_PIN_15
#define USER1_I2C_PIN_AF         GPIO_AF7

#define USER1_I2C_DMA            DMA1
#define USER1_I2C_DMA_CLK        RCC_AHB_PERIPHEN_DMA1
#define USER1_I2C_TX_DMA_CHANNEL DMA1_CH2
#define USER1_I2C_TX_DMA_FLAG    DMA_FLAG_TC2

#define USER2_I2C                I2C2
#define USER2_I2C_CLK            RCC_APB1_PERIPH_I2C2
#define USER2_I2C_GPIO           GPIOA
#define USER2_I2C_GPIO_CLK       RCC_AHB_PERIPHEN_GPIOA
#define USER2_I2C_PIN_SCL        GPIO_PIN_4
#define USER2_I2C_PIN_SDA        GPIO_PIN_5
#define USER2_I2C_PIN_AF         GPIO_AF11

#define USER2_I2C_DMA            DMA1
#define USER2_I2C_DMA_CLK        RCC_AHB_PERIPHEN_DMA1
#define USER2_I2C_RX_DMA_CHANNEL DMA1_CH4
#define USER2_I2C_RX_DMA_FLAG    DMA_FLAG_TC4

#else

#define USER1_I2C                I2C1
#define USER1_I2C_CLK            RCC_APB1_PERIPH_I2C1
#define USER1_I2C_GPIO           GPIOB
#define USER1_I2C_GPIO_CLK       RCC_AHB_PERIPHEN_GPIOB
#define USER1_I2C_PIN_SCL        GPIO_PIN_6
#define USER1_I2C_PIN_SDA        GPIO_PIN_7
#define USER1_I2C_PIN_AF         GPIO_AF2

#define USER1_I2C_DMA            DMA1
#define USER1_I2C_DMA_CLK        RCC_AHB_PERIPHEN_DMA1
#define USER1_I2C_TX_DMA_CHANNEL DMA1_CH2
#define USER1_I2C_TX_DMA_FLAG    DMA_FLAG_TC2

#define USER2_I2C                I2C2
#define USER2_I2C_CLK            RCC_APB1_PERIPH_I2C2
#define USER2_I2C_GPIO           GPIOB
#define USER2_I2C_GPIO_CLK       RCC_AHB_PERIPHEN_GPIOB
#define USER2_I2C_PIN_SCL        GPIO_PIN_10
#define USER2_I2C_PIN_SDA        GPIO_PIN_11
#define USER2_I2C_PIN_AF         GPIO_AF7

#define USER2_I2C_DMA            DMA1
#define USER2_I2C_DMA_CLK        RCC_AHB_PERIPHEN_DMA1
#define USER2_I2C_RX_DMA_CHANNEL DMA1_CH4
#define USER2_I2C_RX_DMA_FLAG    DMA_FLAG_TC4

#endif

#define BUFFER_SIZE             (8)
#define I2C1_ADDRESS7           0x30
#define I2C2_ADDRESS7           0xA0
#define I2C_CLK_SPEED           100000

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */


