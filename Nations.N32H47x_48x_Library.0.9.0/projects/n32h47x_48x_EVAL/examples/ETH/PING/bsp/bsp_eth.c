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
*\*\file bsp_eth.c
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved.
**/ 

#include "bsp_eth.h"


/* Local MAC address */
uint8_t aMACAddr[6];

/* ETH DMA TX RX descriptor physical address */
ETH_DMADescType aDMARxDscrTab[ETH_RX_DESC_NUMBER];
ETH_DMADescType aDMATxDscrTab[ETH_TX_DESC_NUMBER];

/* ETH receive buffer physical address */
uint8_t aRxBuffer[ETH_RX_DESC_NUMBER][ETH_RX_BUFFER_SIZE];

/* Global ETH information structure variable */
ETH_InfoType sEthInfo;

/* Global ETH initialize structure variable */
ETH_InitType sETH_InitParam;

/* Global ETH TX packet structure variable */
ETH_TxPacketType sTxPacket;


/** ETH_BSP Private Defines **/


/** ETH_BSP Driving Functions Declaration **/

/**
*\*\name    ETH_BSP_GPIOInit.
*\*\fun     Initialization the GPIOs used by the ETH module.
*\*\param   pInfo :
*\*\          - Pointer to an ETH_InfoType structure parameter containing various
*\*\            information about the operation of the ETH module.
*\*\return  none
**/
void ETH_BSP_GPIOInit(ETH_InfoType* pInfo)
{
    GPIO_InitType GPIO_InitStructure;

    GPIO_InitStruct(&GPIO_InitStructure);
    /* MDC: PC1(AF11), Alternate Function Push Pull Mode */
    GPIO_InitStructure.Pin            = GPIO_PIN_1;
    GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF11;
    GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);
    /* MDIO: PA2(AF1), Alternate Function Push Pull Mode */
    GPIO_InitStructure.Pin            = GPIO_PIN_2;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF1;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    /* Check whether the media interface is MII or RMII */
    if (pInfo->MediaInterface == ETH_MII_MODE)
    {
        /* TX_D3: PB7(AF15)/PB8(AF13)/PE2(AF8), Alternate Function Push Pull Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_7;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF15;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
        /* TX_D2: PC2(AF11), Alternate Function Push Pull Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_2;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF11;
        GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);
        /* TX_CLK: PC3(AF11), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_3;
        GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF11;
        GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);
        /* CRS: PA0(AF1), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_0;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF1;
        GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
        /* RX_CLK: PA1(AF1), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_1;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF1;
        GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
        /* COL: PA3(AF1), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_3;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF1;
        GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
        /* RX_DV: PA7(AF10)/PD8(AF8), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_7;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF10;
        GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
        /* RX_D0: PC4(AF11)/PD9(AF8), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_4;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF11;
        GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);
        /* RX_D1: PC5(AF11)/PD10(AF8), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_5;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF11;
        GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);
        /* RX_D2: PB0(AF1)/PD11(AF8), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_0;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF1;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
        /* RX_D3: PB1(AF1)/PD12(AF8), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_1;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF1;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
        /* RX_ER: PB10(AF13), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_10;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF13;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
        /* TX_EN: PB11(AF1)/PG11(AF1), Alternate Function Push Pull Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_11;
        GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF1;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
        /* TX_D0: PB12(AF13)/PG13(AF1), Alternate Function Push Pull Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_12;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF13;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
        /* TX_D1: PB13(AF13)/PG14(AF1), Alternate Function Push Pull Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_13;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF13;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
    }
    else
    {
        /* REF_CLK: PA1(AF7), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_1;
        GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_INPUT;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF7;
        GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
        /* CRS_DV: PA7(AF11)/PD8(AF9), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_8;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF9;
        GPIO_InitPeripheral(GPIOD, &GPIO_InitStructure);
        /* RX_D0: PC4(AF10)/PD9(AF9), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_9;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF9;
        GPIO_InitPeripheral(GPIOD, &GPIO_InitStructure);
        /* RX_D1: PC5(AF10)/PD10(AF9), Input Floating Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_10;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF9;
        GPIO_InitPeripheral(GPIOD, &GPIO_InitStructure);
        /* TX_EN: PB11(AF2)/PG11(AF2), Alternate Function Push Pull Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_11;
        GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF2;
        GPIO_InitPeripheral(GPIOG, &GPIO_InitStructure);
        /* TX_D0: PB12(AF2)/PG13(AF2), Alternate Function Push Pull Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_13;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF2;
        GPIO_InitPeripheral(GPIOG, &GPIO_InitStructure);
        /* TX_D1: PB13(AF2)/PG14(AF2), Alternate Function Push Pull Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_14;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF2;
        GPIO_InitPeripheral(GPIOG, &GPIO_InitStructure);
    }

    /* Check whether to enable PPS output */
    if (pInfo->PPSOutCmd != DISABLE)
    {
        /* PPS_OUT: PB5(AF13)/PB6(AF13)/PG8(AF1), Alternate Function Push Pull Mode */
        GPIO_InitStructure.Pin            = GPIO_PIN_5;
        GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF13;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
    }
}

/**
*\*\name    ETH_BSP_NVICInit.
*\*\fun     Initialization Configuration NVIC.
*\*\param   pInfo :
*\*\          - Pointer to an ETH_InfoType structure parameter containing various
*\*\            information about the operation of the ETH module.
*\*\return  none
**/
void ETH_BSP_NVICInit(ETH_InfoType* pInfo)
{
    NVIC_InitType NVIC_InitStructure;
    EXTI_InitType EXTI_InitStructure;
    
    /* Configures the priority group */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    /* Configures the ETH_IRQn NVIC */
    NVIC_InitStructure.NVIC_IRQChannel                   = ETH_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = NVIC_PRE_PRIORITY_0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = NVIC_SUB_PRIORITY_0;
    NVIC_Init(&NVIC_InitStructure);

    /* Check whether to enable PMT */
    if (pInfo->PMTCmd != DISABLE)
    {
        /* Configures the PMT connected to EXTI Line 27 */
        EXTI_InitStruct(&EXTI_InitStructure);
        EXTI_InitStructure.EXTI_Line                     = EXTI_LINE27;
        EXTI_InitStructure.EXTI_LineCmd                  = ENABLE;
        EXTI_InitStructure.EXTI_Mode                     = EXTI_Mode_Interrupt;
        EXTI_InitStructure.EXTI_Trigger                  = EXTI_Trigger_Rising;
        EXTI_InitPeripheral(&EXTI_InitStructure);
        /* Configures the ETH_WKUP_IRQn NVIC */
        NVIC_InitStructure.NVIC_IRQChannel               = ETH_WKUP_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority    = NVIC_SUB_PRIORITY_1;
        NVIC_Init(&NVIC_InitStructure);
    }
}

/**
*\*\name    ETH_BSP_ClockCmd.
*\*\fun     Enables or disables the ETH, GPIO, AFIO, etc. clocks.
*\*\param   Cmd (The input parameters must be the following values):
*\*\          - ENABLE
*\*\          - DISABLE
*\*\return  none
**/
void ETH_BSP_ClockCmd(FunctionalStatus Cmd)
{
    /* Enable or disable GPIOx Clock */
    RCC_EnableAHB1PeriphClk((RCC_AHB_PERIPHEN_GPIOA | RCC_AHB_PERIPHEN_GPIOB
                           | RCC_AHB_PERIPHEN_GPIOC | RCC_AHB_PERIPHEN_GPIOD
                           | RCC_AHB_PERIPHEN_GPIOE | RCC_AHB_PERIPHEN_GPIOG),
                             Cmd);

    /* Enable or disable AFIO Clock */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_AFIO, Cmd);

    /* Enable or disable ETH Clock */
    RCC_EnableAHBPeriphClk(RCC_AHB_PERIPHEN_ETH, Cmd);
}

/**
*\*\name    ETH_BSP_Init.
*\*\fun     ETH initialization function, called in the low_level_init() function.
*\*\param   none
*\*\return  SUCCESS or ERROR.
**/
ErrorStatus ETH_BSP_Init(void)
{
    uint32_t TempIndex;
    
    /* Set the local MAC address */
    aMACAddr[0] = MAC_ADDR0;
    aMACAddr[1] = MAC_ADDR1;
    aMACAddr[2] = MAC_ADDR2;
    aMACAddr[3] = MAC_ADDR3;
    aMACAddr[4] = MAC_ADDR4;
    aMACAddr[5] = MAC_ADDR5;

    /* Clear the sEthInfo structure variable */
    memset(&sEthInfo, 0, sizeof(ETH_InfoType));
    /* Set ETH operation-related information via sEthInfo */
    sEthInfo.AutoNegCmd     = ENABLE;
    sEthInfo.MDCClockMode   = ETH_MDCCLK_NORMAL;
    sEthInfo.MediaInterface = ETH_RMII_MODE;
    sEthInfo.pMACAddr       = &aMACAddr[0];
    sEthInfo.PMTCmd         = DISABLE;
    sEthInfo.PPSOutCmd      = DISABLE;
    sEthInfo.pRxDesc        = aDMARxDscrTab;
    sEthInfo.pTxDesc        = aDMATxDscrTab;
    sEthInfo.RxBuffLen      = ETH_RX_BUFFER_SIZE;
    sEthInfo.PHYInfo.phyAddr       = PHY_ADDR;
    sEthInfo.PHYInfo.bcRegAddr     = PHY_BCR;
    sEthInfo.PHYInfo.bsRegAddr     = PHY_BSR;
    sEthInfo.PHYInfo.sdRegAddr     = PHY_SDSR;
    sEthInfo.PHYInfo.phyReset      = PHY_RESET;
    sEthInfo.PHYInfo.phyAutoNeg    = PHY_AUTONEGOTIATION;
    sEthInfo.PHYInfo.phyAutoNegOK  = PHY_AUTONEGO_COMPLETE;
    sEthInfo.PHYInfo.phyLinkOK     = PHY_LINKED_STATUS;
    sEthInfo.PHYInfo.phyDuplexMask = PHY_DUPLEX_MASK;
    sEthInfo.PHYInfo.phySpeedMask  = PHY_SPEED_MASK;

    /* Enable related clocks */
    ETH_BSP_ClockCmd(ENABLE);
    /* Configuring GPIOs */
    ETH_BSP_GPIOInit(&sEthInfo);
    /* Configuring NVIC */
    ETH_BSP_NVICInit(&sEthInfo);

    /* DeInitializes the ETH peripheral */
    ETH_DeInit(ETH);
    /* Set ETH initialization parameters by default */
    ETH_StructInit(&sETH_InitParam);
    /* Modify ETH initialization parameters */
    sETH_InitParam.Duplex               = ETH_FULL_DUPLEX_MODE;
    sETH_InitParam.SpeedSelect          = ETH_SPEED_100M;
    sETH_InitParam.AutoPadCRCStrip      = (uint32_t)(ENABLE << 20);
    sETH_InitParam.CRCStripTypePacket   = (uint32_t)(ENABLE << 21);
    sETH_InitParam.ChecksumOffload      = (uint32_t)(ENABLE << 27);
    sETH_InitParam.GiantPacketSizeLimit = (0x618U);

    sETH_InitParam.ProgramWatchdog    = (uint32_t)(ENABLE << 8);
    sETH_InitParam.TxQueueOperateMode = ETH_TXQUEUE_OPERATE_THRESHOLD_64;
    sETH_InitParam.RxQueueOperateMode = ETH_RXQUEUE_OPERATE_THRESHOLD_64;

    sETH_InitParam.BurstMode         = ETH_BURST_MODE_FIXED;
    sETH_InitParam.AddrAlignedBeats  = (uint32_t)(ENABLE << 12);
    sETH_InitParam.DescriptorSkipLen = ETH_DESC_SKIP_LEN_64BIT;
    sETH_InitParam.TxBurstLength     = ETH_TX_PROGRAM_BURST_LEN_32;
    sETH_InitParam.RxBurstLength     = ETH_RX_PROGRAM_BURST_LEN_32;

    /* Check whether to enable AutoNegotiation */
    if (sEthInfo.AutoNegCmd == DISABLE)
    {
        /* Auto-negotiation is not turned on before you need to set the duplex
        and speed of the PHY based on the configuration of the MAC */
        if ((sETH_InitParam.Duplex == ETH_FULL_DUPLEX_MODE)
            && (sETH_InitParam.SpeedSelect == ETH_SPEED_100M))
        {
            /* Set the full-duplex mode at 100 Mb/s to PHY */
            sEthInfo.PHYInfo.phyMode = PHY_FULLDUPLEX_100M;
        }
        else if ((sETH_InitParam.Duplex == ETH_FULL_DUPLEX_MODE)
                && (sETH_InitParam.SpeedSelect == ETH_SPEED_10M))
        {
            /* Set the full-duplex mode at 10 Mb/s to PHY */
            sEthInfo.PHYInfo.phyMode = PHY_FULLDUPLEX_10M;
        }
        else if ((sETH_InitParam.Duplex == ETH_HALF_DUPLEX_MODE)
                && (sETH_InitParam.SpeedSelect == ETH_SPEED_100M))
        {
            /* Set the half-duplex mode at 100 Mb/s to PHY */
            sEthInfo.PHYInfo.phyMode = PHY_HALFDUPLEX_100M;
        }
        else if ((sETH_InitParam.Duplex == ETH_HALF_DUPLEX_MODE)
                && (sETH_InitParam.SpeedSelect == ETH_SPEED_10M))
        {
            /* Set the half-duplex mode at 10 Mb/s to PHY */
            sEthInfo.PHYInfo.phyMode = PHY_HALFDUPLEX_10M;
        }
        else
        {
            /* Do nothing */
        }
    }

    /* Checks whether initializing the ETH was successful */
    if (ETH_Init(ETH, &sEthInfo, &sETH_InitParam) != ETH_SUCCESS)
    {
        /* ETH initialization failed */
        return ERROR;
    }

    /* Assign memory for each RX descriptor */
    for (TempIndex = 0; TempIndex < ETH_RX_DESC_NUMBER; TempIndex++)
    {
        /* Checks whether the assign of memory was successful */
        if (ETH_RxDescAssignMemory(&sEthInfo, TempIndex, aRxBuffer[TempIndex], NULL) != ETH_SUCCESS)
        {
            /* Assign memory failed for descriptor */
            return ERROR;
        }
    }

    /* Clear the sTxPacket structure variable */
    memset(&sTxPacket, 0, sizeof(ETH_TxPacketType));
    /* Set TxPacket-related config via sTxPacket */
    sTxPacket.Attributes   = (ETH_TX_PACKETS_FEATURES_CSUM | ETH_TX_PACKETS_FEATURES_CRCPAD);
    sTxPacket.CRCPadCtrl   = ETH_CRC_PAD_INSERT;
    sTxPacket.ChecksumCtrl = ETH_CHECKSUM_INSERT_IPHDR_PAYLOAD_PHDR_CALC;

    return SUCCESS;
}

/**
*\*\name    ETH_BSP_DeInit.
*\*\fun     ETH DeInitializes function.
*\*\param   none
*\*\return  none.
**/
void ETH_BSP_DeInit(void)
{
    /* Clear the sEthInfo structure variable */
    memset(&sEthInfo, 0, sizeof(ETH_InfoType));
    /* Clear the sETH_InitParam structure variable */
    memset(&sETH_InitParam, 0, sizeof(ETH_InitType));
    /* Clear the sTxPacket structure variable */
    memset(&sTxPacket, 0, sizeof(ETH_TxPacketType));
    /* DISABLE related clocks */
    ETH_BSP_ClockCmd(DISABLE);
}


