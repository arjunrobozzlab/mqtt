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
*\*\file smartcard.h
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved.
**/

#ifndef __SMARTCARD_H__
#define __SMARTCARD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32h47x_48x.h"
#include "main.h"

/* Exported constants */
#define T0_PROTOCOL        0x00  /* T0 protocol */
#define DIRECT             0x3B  /* Direct bit convention */
#define INDIRECT           0x3F  /* Indirect bit convention */
#define SETUP_LENGTH       20
#define HIST_LENGTH        20
#define LC_MAX             255 //20
#define SC_RECEIVE_TIMEOUT 0x4000  /* Direction to reader */

/* SC Tree Structure -----------------------------------------------------------
                              MasterFile
                           ________|___________
                          |        |           |
                        System   UserData     Note
------------------------------------------------------------------------------*/

#define SC_USART                 USART3
#define SC_USART_CLK             RCC_APB1_PERIPH_USART3
#define SC_USART_GPIO            GPIOF
#define SC_USART_GPIO_CLK        RCC_AHB_PERIPHEN_GPIOF
#define SC_USART_PIN_TX          GPIO_PIN_11
#define SC_USART_CK_GPIO         GPIOC
#define SC_USART_GPIO_CK_CLK     RCC_AHB_PERIPHEN_GPIOC
#define SC_USART_PIN_CK          GPIO_PIN_12
#define SC_USART_Tx_GPIO_AF      GPIO_AF17
#define SC_USART_Clk_GPIO_AF     GPIO_AF6
#define SC_USART_APBxClkCmd      RCC_EnableAPB1PeriphClk
#define SC_USART_IRQn            USART3_IRQn
#define SC_USART_IRQHandler      USART3_IRQHandler 

#define SC_USART_DMAx           DMA1
#define SC_USART_DMAx_CLK       RCC_AHB_PERIPHEN_DMA1
#define SC_USART_DR_Base        (USART3_BASE + 0x10)
#define SC_USART_Tx_DMA_Channel DMA1_CH7
#define SC_USART_Tx_DMA_FLAG    DMA_FLAG_TC7
#define SC_USART_Tx_DMA_REMAP   DMA_REMAP_USART3_TX
#define SC_USART_Rx_DMA_Channel DMA1_CH6
#define SC_USART_Rx_DMA_FLAG    DMA_FLAG_TC6
#define SC_USART_Rx_DMA_REMAP   DMA_REMAP_USART3_RX

#define SC_PIN_RESET              GPIO_PIN_3
#define SC_PIN_RESET_GPIO         GPIOB
#define SC_PIN_RESET_GPIO_CLK     RCC_AHB_PERIPHEN_GPIOB




/* SC ADPU Command: Operation Code */
#define SC_CLA_GSM11       0xA0

/* Data Area Management Commands */
#define SC_SELECT_FILE     0xA4
#define SC_GET_RESPONCE    0xC0
#define SC_STATUS          0xF2
#define SC_UPDATE_BINARY   0xD6
#define SC_READ_BINARY     0xB0
#define SC_WRITE_BINARY    0xD0
#define SC_UPDATE_RECORD   0xDC
#define SC_READ_RECORD     0xB2

/* Administrative Commands */
#define SC_CREATE_FILE     0xE0

/* Safety Management Commands */
#define SC_VERIFY          0x20
#define SC_CHANGE          0x24
#define SC_DISABLE         0x26
#define SC_ENABLE          0x28
#define SC_UNBLOCK         0x2C
#define SC_EXTERNAL_AUTH   0x82
#define SC_GET_CHALLENGE   0x84

/* Answer to reset Commands */
#define SC_GET_A2R         0x00

/* SC STATUS: Status Code */
#define SC_EF_SELECTED     0x9F
#define SC_DF_SELECTED     0x9F
#define SC_OP_TERMINATED   0x9000

/* Smartcard Voltage */
#define SC_VOLTAGE_5V      0
#define SC_VOLTAGE_3V      1



/* Answer to reset state */

#define TA_BIT          (1<<4)  /* TAx presence bit (bit 4, 0x10) */
#define TB_BIT          (1<<5)  /* TBx presence bit (bit 5, 0x20) */
#define TC_BIT          (1<<6)  /* TCx presence bit (bit 6, 0x40) */
#define TD_BIT          (1<<7)  /* TDx presence bit (bit 7, 0x80) */
#define STATE_PARSE_TS                            1
#define STATE_PARSE_T0                            2
#define STATE_PARSE_TA                            3
#define STATE_PARSE_TB                            4
#define STATE_PARSE_TC                            5
#define STATE_PARSE_TD                            6
#define STATE_PARSE_HIST_BYTES                    7
#define STATE_PARSE_TCK                           8
#define STATE_PARSE_END                           255

/* Exported types */
typedef enum
{
    SC_POWER_ON = 0x00,
    SC_RESET_LOW = 0x01,
    SC_RESET_HIGH = 0x02,
    SC_ACTIVE = 0x03,
    SC_ACTIVE_ON_T0 = 0x04,
    SC_POWER_OFF = 0x05
} SC_State;

/* ATR structure - Answer To Reset */
typedef struct
{
    uint8_t TS;               /* Bit Convention */
    uint8_t T0;               /* High nibble = Number of setup byte; low nibble = Number of historical byte */
    uint8_t T[SETUP_LENGTH];  /* Setup array */
    uint8_t H[HIST_LENGTH];   /* Historical array */
    uint8_t TCK;              /* TCK */
    uint8_t Tlength;          /* Setup array dimension */
    uint8_t Hlength;          /* Historical array dimension */
} SC_ATR;

/* ADPU-Header command structure */
typedef struct
{
    uint8_t CLA;  /* Command class */
    uint8_t INS;  /* Operation code */
    uint8_t P1;   /* Selection Mode */
    uint8_t P2;   /* Selection Option */
} SC_Header;

/* ADPU-Body command structure */
typedef struct
{
    uint8_t LC;            /* Data field length */
    uint8_t Data[LC_MAX];  /* Command parameters */
    uint8_t LE;            /* Expected length of data to be returned */
} SC_Body;

/* ADPU Command structure */
typedef struct
{
    SC_Header Header;
    SC_Body Body;
} SC_ADPU_Commands;

/* SC response structure */
typedef struct
{
    uint8_t Data[LC_MAX];  /* Data returned from the card */
    uint8_t SW1;          /* Command Processing status */
    uint8_t SW2;          /* Command Processing qualification */
} SC_ADPU_Responce;

/* SC Initial structure */
typedef struct
{
    uint8_t Clk_Div;     /* USART Clk Div Value */
    uint8_t GT;          /* Guard Time*/
    uint8_t StopBits;  
    uint8_t Parity;
    uint8_t NackEn;
} SC_InitStructure;

typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} TestStatus;

//typedef enum
//{
//    Bit_RESET = 0,
//    Bit_SET
//} Bit_OperateType;

/* Exported macro */
/* Exported functions */
/* APPLICATION LAYER */
void SC_Handler(SC_State *SCState, SC_ADPU_Commands *SC_ADPU, SC_ADPU_Responce *SC_Response, SC_InitStructure *SC_InitCfg);
void SC_PowerCmd(FunctionalState NewState);
void SC_Reset(Bit_OperateType ResetState);
void SC_DetectPinConfig(void);
void SC_ParityErrorHandler(void);
void SC_PPSConfig(void);

void SC_APDU_Init(SC_ADPU_Commands *SC_ADPU, uint8_t SC_APDU_CLA, uint8_t SC_APDU_INS, uint8_t SC_APDU_P1, uint8_t SC_APDU_P2,
 uint8_t SC_APDU_LC, uint8_t *SC_APDU_Data, uint8_t SC_APDU_LE);
void SC_DeInit(void);

#ifdef __cplusplus
}
#endif

#endif /* __SMARTCARD_H__ */


