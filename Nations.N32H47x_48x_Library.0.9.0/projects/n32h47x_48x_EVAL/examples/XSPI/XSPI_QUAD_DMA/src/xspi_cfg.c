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
*\*\file      qspi_cfg.c
*\*\author    Nations
*\*\version   v1.0.0
*\*\copyright Copyright (c) 2023, Nations Technologies Inc. All rights reserved. 
*/
#include "n32h47x_48x_xspi.h" 
#include "n32h47x_48x_dma.h" 
#include "xspi_cfg.h"

/**
*\*\name    RCC_Configuration.
*\*\fun     Configures the different system clocks.
*\*\param   none
*\*\return  none
**/
void RCC_Configuration(void)
{
    /* GPIOA, GPIOC, GPIOD clock enable */
    RCC_EnableAHB1PeriphClk(RCC_AHB_PERIPHEN_GPIOA|RCC_AHB_PERIPHEN_GPIOC|RCC_AHB_PERIPHEN_GPIOD ,ENABLE);
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_AFIO,ENABLE);
    
    /* XSPI clock enable */
    RCC_EnableAHBPeriphClk(RCC_AHB_PERIPHEN_XSPI|RCC_AHB_PERIPHEN_DMA1, ENABLE);
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
  		
    /* Confugure NSS0 pins */   
    GPIO_InitStructure.Pin       = GPIO_PIN_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Slew_Rate = GPIO_SR_SLOW_SLEW;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF9;
    GPIO_InitStructure.GPIO_Current = GPIO_DC_12mA;
    GPIO_InitPeripheral(GPIOD, &GPIO_InitStructure);
			
    /* Confugure SCK pin  */
    GPIO_InitStructure.Pin       = GPIO_PIN_5;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF9;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
    
    /* Confugure IO0\IO1 pin  */
    GPIO_InitStructure.Pin       = GPIO_PIN_6| GPIO_PIN_7;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF15;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
    
    /* Confugure IO2\IO3 pin  */
    GPIO_InitStructure.Pin       = GPIO_PIN_4 | GPIO_PIN_5;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF9;
    GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);	
	
}

/**
*\*\name    XSPI_Configuration.
*\*\fun     Configures the xspi register.
*\*\param  frame_format:
*\*\        -STANDRD_SPI_FORMAT
*\*\        -DUAL_SPI_FORMAT
*\*\        -QUAD_SPI_FORMAT
*\*\        -OCTAL_SPI_FORMAT
*\*\param  transfer_mode:
*\*\        -TX_AND_RX
*\*\        -TX_ONLY
*\*\        -RX_ONLY
*\*\        -EEPROM_READ
*\*\param  data_frame_size:
*\*\        -DFS_04_BIT
*\*\        -DFS_08_BIT
*\*\        -DFS_16_BIT
*\*\        -DFS_24_BIT
*\*\        -DFS_32_BIT
*\*\param  number_data_frame:
*\*\        -0-0xffff
*\*\param  baudr:
*\*\        -0-0x7fff
*\*\return  none
*\*\note default:INST_8BIT,ADDR_24BIT,waitcycle_8
**/
void XSPI_Configuration(uint32_t frame_format,uint32_t transfer_mode,uint32_t data_frame_size,uint16_t number_data_frame,uint16_t baudr)
{
    XSPI_DeInit();
    RCC_EnableAHBPeriphClk(RCC_AHB_PERIPHEN_XSPI, ENABLE);
	/*disable XSPI*/
    XSPI->SLAVE_EN = (0x0);
	XSPI_Cmd(DISABLE);
	
	/*set MST, SPI_FRF, TMOD ,SCPOL, SCPH, DFS, SSTE*/
	XSPI->CTRL0 = (XSPI_Mode_Master|frame_format|transfer_mode|SCPOL_LOW|START_BIT|data_frame_size|SSTE_BIT0);
	/*set NDF*/
	XSPI->CTRL1 = (number_data_frame);
	/*set CLKDIV */
	XSPI->BAUD = ((uint32_t)baudr<<1);
    
	/*set TRANSTYPE, ADDRLEN, INSTL, WAITCYCLES*/
	XSPI->ENH_CTRL0 = (TRANS_TYPE_STANDRD|ENSPI_ADDR_24BIT|ENSPI_INST_L_08BIT|ENSPI_WAIT_8CYCLES);
	if(transfer_mode == TX_ONLY || transfer_mode == RX_ONLY)
	{
        XSPI->RX_DELAY = (XSPI->BAUD)/2;
		XSPI->ENH_CTRL0 |=CLK_STRETCH_EN;
	}
	/*set TXFTTEI*/
	XSPI->TXFT = ((0x00<<16)|0x00)&0x1f001f;/* level = 0*/
    /*set TXFTTEI*/
	XSPI->RXFT = (0x08&0x1f);/* level = 8*/
	
	/*enable XSPI*/
    XSPI->SLAVE_EN = (0x1);
	XSPI_Cmd(ENABLE);
}

/**
*\*\name    DMA_Configuration.
*\*\fun     Configures the dma register.
*\*\param  PeripheralAddr:
*\*\        -(uint32_t)&XSPI->DAT0
*\*\param  MemoryAddr:
*\*\param  Len:
*\*\        -0~65535
*\*\param  TxRx:
*\*\        - DMA_TX
*\*\        - DMA_RX 
*\*\param  NewState:
*\*\        - ENABLE
*\*\        - DISABLE 
*\*\return  none
*\*\note none
**/
void DMA_Configuration(uint32_t PeripheralAddr, uint32_t MemoryAddr, uint16_t Len, uint8_t TxRx, FunctionalState NewState)
{
    
	DMA_InitType  DMA_InitStructure;
    DMA_ChannelType* DMAy_Channelx;
    uint32_t DMA_Direction;
    uint32_t DMA_RemapNum = 0;
    
    if (TxRx == DMA_TX)/*DMA tx*/
    {
        DMAy_Channelx  = DMA1_CH1;
        DMA_Direction = DMA_DIR_PERIPH_DST;
        DMA_RemapNum = DMA_REMAP_XSPI_TX;/*DMA remap*/
    }
    else if (TxRx == DMA_RX)/*DMA rx*/
    {
        DMAy_Channelx = DMA1_CH2;
        DMA_Direction = DMA_DIR_PERIPH_SRC;
        DMA_RemapNum = DMA_REMAP_XSPI_RX;/*DMA remap*/
    }
    
    DMA_DeInit(DMAy_Channelx);
    DMA_StructInit(&DMA_InitStructure);
    /* config DMA channel*/
    DMA_InitStructure.PeriphAddr = PeripheralAddr;
    DMA_InitStructure.MemAddr = MemoryAddr;
    DMA_InitStructure.Direction = DMA_Direction;
    DMA_InitStructure.BufSize = Len;
    DMA_InitStructure.PeriphInc = DMA_PERIPH_INC_DISABLE;
    DMA_InitStructure.MemoryInc = DMA_MEM_INC_ENABLE;
    DMA_InitStructure.PeriphDataSize = DMA_PERIPH_DATA_WIDTH_WORD;
    DMA_InitStructure.MemDataSize = DMA_MEM_DATA_WIDTH_WORD;
    DMA_InitStructure.CircularMode = DMA_MODE_NORMAL;
    DMA_InitStructure.Priority = DMA_PRIORITY_HIGH;
    DMA_InitStructure.Mem2Mem = DMA_M2M_DISABLE;
    DMA_InitStructure.BURST_BYPASS = DMA_BURST_BYPASS_ENABLE;
    DMA_InitStructure.BURST_MODE = DMA_BURST_MODE_ALMOST;    
    DMA_InitStructure.BURST_LEN = DMA_BURST_LEN_8;   
    DMA_Init(DMAy_Channelx, &DMA_InitStructure);
    
    DMA_RequestRemap(DMA_RemapNum, DMAy_Channelx, NewState);		

    /* enable DMA channel*/
    DMA_EnableChannel(DMAy_Channelx, NewState);
}


