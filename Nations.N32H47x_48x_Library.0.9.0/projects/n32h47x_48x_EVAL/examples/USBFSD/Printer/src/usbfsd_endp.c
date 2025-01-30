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
*\*\file usbfsd_endp.c
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved.
**/

#include "hw_config.h"
#include "usbfsd_lib.h"
#include "usbfsd_istr.h"


uint8_t Receive_Buffer[2];
extern __IO uint8_t PrevXferComplete;
extern u8* Ep1DataPtr;
extern u8 key_buffer[8];


extern uint8_t m_tx_len;
extern uint8_t m_tx_flag;
extern uint8_t m_tx_buf[];

extern uint8_t m_rx_len;
extern uint8_t m_rx_flag;
extern uint8_t m_rx_buf[];


/**
*\*\name    EP2_OUT_Callback.
*\*\fun     EP2 OUT Callback Routine.
*\*\param   none
*\*\return  none 
**/
void EP2_OUT_Callback(void)
{
    m_rx_flag = 1;
    m_rx_len = USB_GetEpRxCnt(ENDP2);
    USB_CopyPMAToUserBuf((unsigned char*)m_rx_buf, ENDP2_RXADDR, m_rx_len);
    SetEPRxStatus(ENDP2, EP_RX_VALID);
}

/**
*\*\name    EP2_IN_Callback.
*\*\fun     EP2 IN Callback Routine.
*\*\param   none
*\*\return  none 
**/
void EP2_IN_Callback(void)
{
    _SetEPTxStatus(ENDP2, EP_TX_NAK);

    if(m_tx_flag)
    {
        m_tx_flag = 0;
        USB_SilWrite(EP2_IN, m_tx_buf, m_tx_len);
        USB_SetEpTxCnt(ENDP2, m_tx_len);
    }
    else
    {
        USB_SetEpTxCnt(ENDP2, 0);
    }
    _SetEPTxStatus(ENDP2, EP_TX_VALID);
}

