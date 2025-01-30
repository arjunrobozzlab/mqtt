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
*\*\file hw_config.c
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved.
**/

#include "hw_config.h"
#include "usbfsd_lib.h"
#include "usbfsd_desc.h"
#include "usbfsd_pwr.h"
#include "n32h47x_48x_rcc.h"
#include "n32h47x_48x_gpio.h"
#include "n32h47x_48x_exti.h"
#include "misc.h"

extern __IO uint32_t packet_sent;
extern __IO uint8_t Send_Buffer[VIRTUAL_COM_PORT_DATA_SIZE];
extern __IO  uint32_t packet_receive;
extern __IO uint8_t Receive_length;

uint8_t Receive_Buffer[64];
uint32_t Send_length;

/**
*\*\name    USBFS_IO_Configure.
*\*\fun     Configures usb fs device gpio.
*\*\param   none
*\*\return  none 
**/
void USBFS_IO_Configure(void)
{
    GPIO_InitType GPIO_InitStructure;  
    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOA, ENABLE);
    
    GPIO_InitStruct(&GPIO_InitStructure);
  
    GPIO_InitStructure.Pin              = GPIO_PIN_11;
    GPIO_InitStructure.GPIO_Mode        = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate   = GPIO_AF10;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.Pin              = GPIO_PIN_12;
    GPIO_InitStructure.GPIO_Mode        = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate   = GPIO_AF10;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
}
 
/**
*\*\name    Set_System.
*\*\fun     Configures Main system clocks & power.
*\*\param   none
*\*\return  none 
**/
void Set_System(void)
{
    RCC_DeInit();

    /*Enable HSE*/
    RCC->CTRL |= RCC_CTRL_HSEEN;
    while((RCC->CTRL & RCC_CTRL_HSERDF) != RCC_CTRL_HSERDF);

#if defined (N32H473) || defined (N32H474)
    /*Set PLL MUL 192MHz */
    RCC_ConfigPll(RCC_PLL_SRC_HSE, RCC_PLL_PRE_1, RCC_PLL_MUL_24, RCC_PLLOUT_DIV_1);
#elif defined (N32H482) || defined (N32H487)
    /*Set PLL MUL 240MHz */
    RCC_ConfigPll(RCC_PLL_SRC_HSE, RCC_PLL_PRE_1, RCC_PLL_MUL_30, RCC_PLLOUT_DIV_1);
#endif
    /*Enable PLL*/
    RCC->CTRL |= RCC_CTRL_PLLEN;
    while((RCC->CTRL & RCC_CTRL_PLLRDF) != RCC_CTRL_PLLRDF); 

    /*Set AHB/APB1/APB2*/
    RCC->CFG |= RCC_CFG_AHBPRES_DIV1;
    RCC->CFG |= RCC_CFG_APB1PRES_DIV1;
    RCC->CFG |= RCC_CFG_APB2PRES_DIV1;

    FLASH->AC &= (uint32_t)((uint32_t)~FLASH_AC_LATENCY);
    FLASH->AC |= (uint32_t)(FLASH_AC_LATENCY_4);

    /* Select PLL as system clock source */
    RCC->CFG &= (uint32_t)((uint32_t) ~(RCC_CFG_SCLKSW));
    RCC->CFG |= (uint32_t)RCC_CFG_SCLKSW_PLL;
    while ((RCC->CFG & RCC_CFG_SCLKSTS) != RCC_CFG_SCLKSTS_PLL) 
    {
    }
}

/**
*\*\name    Set_USBClock.
*\*\fun     Configures USB Clock input (48MHz).
*\*\param   sysclk: system clock.
*\*\          - SYSCLK_VALUE_48MHz
*\*\          - SYSCLK_VALUE_72MHz
*\*\          - SYSCLK_VALUE_96MHz
*\*\          - SYSCLK_VALUE_144MHz
*\*\          - SYSCLK_VALUE_192MHz
*\*\          - SYSCLK_VALUE_240MHz
*\*\return  ErrorStatus 
*\*\          - SUCCESS
*\*\          - ERROR
**/
ErrorStatus Set_USBClock(uint32_t sysclk)
{
    ErrorStatus status = SUCCESS;

    switch(sysclk)
    {
    case SYSCLK_VALUE_48MHz: 
        RCC_ConfigUSBPLLPresClk(RCC_USBPLLCLK_SRC_PLL, RCC_USBPLLCLK_DIV1);
		RCC->CFG3 &= ~RCC_CFG3_USBFSTM;
        break;

    case SYSCLK_VALUE_96MHz: 
        RCC_ConfigUSBPLLPresClk(RCC_USBPLLCLK_SRC_PLL, RCC_USBPLLCLK_DIV2);
		RCC->CFG3 &= ~RCC_CFG3_USBFSTM;
        break;
    
    case SYSCLK_VALUE_144MHz: 
        RCC_ConfigUSBPLLPresClk(RCC_USBPLLCLK_SRC_PLL, RCC_USBPLLCLK_DIV3);
        RCC->CFG3 |= RCC_CFG3_USBFSTM;
        break;

    case SYSCLK_VALUE_192MHz: 
        RCC_ConfigUSBPLLPresClk(RCC_USBPLLCLK_SRC_PLL, RCC_USBPLLCLK_DIV4);
        RCC->CFG3 |= RCC_CFG3_USBFSTM;
        break;
    
    case SYSCLK_VALUE_240MHz: 
        RCC_ConfigUSBPLLPresClk(RCC_USBPLLCLK_SRC_PLL, RCC_USBPLLCLK_DIV5);
        RCC->CFG3 |= RCC_CFG3_USBFSTM;
        break;

    default:
        status = ERROR;
        break;
    }

    return status;
}

/**
*\*\name    Enter_LowPowerMode.
*\*\fun     Power-off system clocks and power while entering suspend mode.
*\*\param   none
*\*\return  none 
**/
void Enter_LowPowerMode(void)
{
    /* Set the device state to suspend */
    bDeviceState = SUSPENDED;
}

/**
*\*\name    Leave_LowPowerMode.
*\*\fun     Restores system clocks and power while exiting suspend mode.
*\*\param   none
*\*\return  none 
**/
void Leave_LowPowerMode(void)
{
    USB_DeviceMess* pInfo = &Device_Info;

    /* Set the device state to the correct state */
    if (pInfo->CurrentConfiguration != 0)
    {
        /* Device configured */
        bDeviceState = CONFIGURED;
    }
    else
    {
        bDeviceState = ATTACHED;
    }
}

/**
*\*\name    USB_Interrupts_Config.
*\*\fun     Configures the USB interrupts.
*\*\param   none
*\*\return  none 
**/
void USB_Interrupts_Config(void)
{
    NVIC_InitType NVIC_InitStructure;
    EXTI_InitType EXTI_InitStructure;

    /* 2 bit for pre-emption priority, 2 bits for subpriority */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    /* Enable the USB interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                   = USB_FS_LP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* Enable the USB Wake-up interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                   = USB_FS_WKUP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* Configure the EXTI line 18 connected internally to the USB IP */
    EXTI_ClrITPendBit(EXTI_LINE18);
    EXTI_InitStructure.EXTI_Line = EXTI_LINE18; 
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_InitPeripheral(&EXTI_InitStructure);
}

/**
*\*\name    USB_Config.
*\*\fun     Configures USB Clock input (48MHz).
*\*\param   sysclk: system clock.
*\*\          - SYSCLK_VALUE_48MHz
*\*\          - SYSCLK_VALUE_72MHz
*\*\          - SYSCLK_VALUE_96MHz
*\*\          - SYSCLK_VALUE_144MHz
*\*\          - SYSCLK_VALUE_192MHz
*\*\          - SYSCLK_VALUE_240MHz
*\*\return  ErrorStatus 
*\*\          - SUCCESS
*\*\          - ERROR
**/
ErrorStatus USB_Config(uint32_t sysclk)
{
    ErrorStatus status = SUCCESS;
    
    RCC_ConfigUSBFSClk(RCC_USBFS_CLKSRC_PLLPRES);

    if(Set_USBClock(sysclk) == SUCCESS)
    {
        RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_USBFS, ENABLE);
        status = SUCCESS;
    }
    else
    {
        status = ERROR;
    }

    return status;
}

/**
*\*\name    CDC_Send_DATA.
*\*\fun     send the data received from the MCU to the PC through USB
*\*\param   ptrBuffer: send data pointer.
*\*\param   Send_length: send data length.
*\*\return  none
**/
void CDC_Send_DATA (uint8_t *ptrBuffer, uint8_t Send_length)
{
    /*if max buffer is Not reached*/
    if(Send_length < VIRTUAL_COM_PORT_DATA_SIZE)     
    {
        /*Sent flag*/
        packet_sent = 0;
        /* send  packet to PMA*/
        USB_CopyUserToPMABuf((unsigned char*)ptrBuffer, ENDP1_TXADDR, Send_length);
        USB_SetEpTxCnt(ENDP1, Send_length);
        USB_SetEpTxValid(ENDP1);
    }
}

/**
*\*\name    CDC_Receive_DATA.
*\*\fun     receive the data from the PC to MCU and send it through USB
*\*\param   none
*\*\return  none
**/
void CDC_Receive_DATA(void)
{ 
    /*Receive flag*/
    packet_receive = 0;
    USB_SetEpRxValid(ENDP3); 
}
