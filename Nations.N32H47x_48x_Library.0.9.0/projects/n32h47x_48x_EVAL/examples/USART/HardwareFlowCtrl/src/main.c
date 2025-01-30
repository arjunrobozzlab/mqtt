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

#define TxBufferSize1 (countof(TxBuffer1) - 1)
#define TxBufferSize2 (countof(TxBuffer2) - 1)

#define countof(a) (sizeof(a) / sizeof(*(a)))

USART_InitType USART_InitStructure;
uint8_t TxBuffer1[]    = "USART Flow_Control Mode Example: USARTy -> USARTz using CTS and RTS Flags";
uint8_t TxBuffer2[]    = "USART Flow_Control Mode Example: USARTz -> USARTy using CTS and RTS Flags";
uint8_t RxBuffer1[TxBufferSize2];
uint8_t RxBuffer2[TxBufferSize1];
uint32_t NbrOfDataToRead1 = TxBufferSize2;
uint32_t NbrOfDataToRead2 = TxBufferSize1;
uint8_t TxCounter1 = 0, RxCounter1 = 0;
uint8_t TxCounter2 = 0, RxCounter2 = 0;
volatile TestStatus TransferStatus1 = FAILED, TransferStatus2 = FAILED;

/**
*\*\name    main.
*\*\fun     Main program.
*\*\param   none
*\*\return  none
**/
int main(void)
{
    /* System Clocks Configuration */
    RCC_Configuration();
    
    /* Configure the GPIO ports */
    GPIO_Configuration();
    
    /* USARTy and USARTz configuration */
    USART_InitStructure.BaudRate            = 115200;
    USART_InitStructure.WordLength          = USART_WL_8B;
    USART_InitStructure.StopBits            = USART_STPB_1;
    USART_InitStructure.Parity              = USART_PE_NO;
    USART_InitStructure.HardwareFlowControl = USART_HFCTRL_CTS | USART_HFCTRL_RTS;
    USART_InitStructure.OverSampling        = USART_16OVER;
    USART_InitStructure.Mode                = USART_MODE_RX | USART_MODE_TX;

    /* Configure USARTy and USARTz */
    USART_Init(USARTy, &USART_InitStructure);
    USART_Init(USARTz, &USART_InitStructure);

    /* Enable the USARTy and USARTz */
    USART_Enable(USARTy, ENABLE);
    USART_Enable(USARTz, ENABLE);

    while (NbrOfDataToRead2--)
    {
        /* Send one byte from USARTy to USARTz */
        USART_SendData(USARTy, TxBuffer1[TxCounter1++]);
        /* Loop until USARTy DAT register is empty */
        while (USART_GetFlagStatus(USARTy, USART_FLAG_TXDE) == RESET)
        {
        }

        /* Loop until the USARTz Receive Data Register is not empty */
        while (USART_GetFlagStatus(USARTz, USART_FLAG_RXDNE) == RESET)
        {
        }
        /* Store the received byte in RxBuffer */
        RxBuffer2[RxCounter2++] = USART_ReceiveData(USARTz);
    }

    while (NbrOfDataToRead1--)
    {
        /* Send one byte from USARTy to USARTz */
        USART_SendData(USARTz, TxBuffer2[TxCounter2++]);
        /* Loop until USARTz DAT register is empty */
        while (USART_GetFlagStatus(USARTz, USART_FLAG_TXDE) == RESET)
        {
        }

        /* Loop until the USARTz Receive Data Register is not empty */
        while (USART_GetFlagStatus(USARTy, USART_FLAG_RXDNE) == RESET)
        {
        }
        /* Store the received byte in RxBuffer */
        RxBuffer1[RxCounter1++] = USART_ReceiveData(USARTy);
    }

    /* Check the received data with the send ones */
    TransferStatus1 = Buffercmp(TxBuffer1, RxBuffer2, TxBufferSize1);
    /* TransferStatus = PASSED, if the data transmitted from USARTy and
       received by USARTz are the same */
    /* TransferStatus = FAILED, if the data transmitted from USARTy and
       received by USARTz are different */
    TransferStatus2 = Buffercmp(TxBuffer2, RxBuffer1, TxBufferSize2);
    /* TransferStatus = PASSED, if the data transmitted from USARTz and
       received by USARTy are the same */
    /* TransferStatus = FAILED, if the data transmitted from USARTz and
       received by USARTy are different */

    while (1)
    {
    }
}


/**
*\*\name    RCC_Configuration.
*\*\fun     Configures the different system clocks.
*\*\param   none
*\*\return  none
**/
void RCC_Configuration(void)
{
    /* Enable GPIO clock */
    RCC_EnableAHB1PeriphClk(USARTy_GPIO_CLK | USARTz_GPIO_CLK,ENABLE);
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_AFIO,ENABLE);
    /* Enable USARTy and USARTz Clock */
    RCC_EnableAPB2PeriphClk(USARTy_CLK,ENABLE);
    RCC_EnableAPB1PeriphClk(USARTz_CLK,ENABLE);
}


/**
*\*\name    GPIO_Configuration.
*\*\fun     Configures the different GPIO ports.
*\*\param   none
*\*\return  none
**/
void GPIO_Configuration(void)
{
    GPIO_InitType GPIO_InitStructure;

    /* Initialize GPIO_InitStructure */
    GPIO_InitStruct(&GPIO_InitStructure);
    
    /* Configure USARTy Tx as alternate function push-pull */
    GPIO_InitStructure.Pin            = USARTy_TxPin;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Pull      = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Alternate = USARTy_Tx_GPIO_AF;
    GPIO_InitPeripheral(USARTy_GPIO, &GPIO_InitStructure);

    /* Configure USARTy RTS as alternate function push-pull */
    GPIO_InitStructure.Pin            = USARTy_RTSPin;
    GPIO_InitStructure.GPIO_Alternate = USARTy_RTS_GPIO_AF;
    GPIO_InitPeripheral(USARTy_GPIO, &GPIO_InitStructure);

    /* Configure USARTz Tx as alternate function push-pull */
    GPIO_InitStructure.Pin            = USARTz_TxPin;
    GPIO_InitStructure.GPIO_Alternate = USARTz_Tx_GPIO_AF;
    GPIO_InitPeripheral(USARTz_GPIO, &GPIO_InitStructure);

    /* Configure USARTz RTS as alternate function push-pull */
    GPIO_InitStructure.Pin            = USARTz_RTSPin;
    GPIO_InitStructure.GPIO_Alternate = USARTz_RTS_GPIO_AF;
    GPIO_InitPeripheral(USARTz_GPIO, &GPIO_InitStructure);

    /* Configure USARTy Rx as alternate function input and pull-up */
    GPIO_InitStructure.Pin            = USARTy_RxPin;
    GPIO_InitStructure.GPIO_Pull      = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Alternate = USARTy_Rx_GPIO_AF;
    GPIO_InitPeripheral(USARTy_GPIO, &GPIO_InitStructure);

    /* Configure USARTz Rx as alternate function input and pull-up */
    GPIO_InitStructure.Pin            = USARTz_RxPin;
    GPIO_InitStructure.GPIO_Alternate = USARTz_Rx_GPIO_AF;
    GPIO_InitPeripheral(USARTz_GPIO, &GPIO_InitStructure);
    
    /* Configure USARTy CTS as alternate function input and pull-up */
    GPIO_InitStructure.Pin            = USARTy_CTSPin;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
    GPIO_InitStructure.GPIO_Pull      = GPIO_PULL_UP;
    GPIO_InitStructure.GPIO_Alternate = USARTy_CTS_GPIO_AF;
    GPIO_InitPeripheral(USARTy_GPIO, &GPIO_InitStructure);

    /* Configure USARTz CTS as alternate function input and pull-up */
    GPIO_InitStructure.Pin            = USARTz_CTSPin;
    GPIO_InitStructure.GPIO_Alternate = USARTz_CTS_GPIO_AF;
    GPIO_InitPeripheral(USARTz_GPIO, &GPIO_InitStructure);    
}


/**
*\*\name    Buffercmp.
*\*\fun     Compares two buffers.
*\*\param   pBuffer1
*\*\param   pBuffer2
*\*\param   BufferLength
*\*\return  PASSED or FAILED
**/
TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
{
    while (BufferLength--)
    {
        if (*pBuffer1 != *pBuffer2)
        {
            return FAILED;
        }

        pBuffer1++;
        pBuffer2++;
    }

    return PASSED;
}

