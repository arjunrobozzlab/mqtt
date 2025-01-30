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
#include "n32h47x_48x.h"
#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "log.h"
#include "n32h47x_48x_rcc.h"
#include "n32h47x_48x_rtc.h"
#include "n32h47x_48x_pwr.h"
#include "User_RTC_Config.h"

#define USER_WRITE_BKP_DAT1_DATA        0xA5A5

bool RTC_Time_Out_Flag=false;

/**
*\*\name    main.
*\*\fun     Main program.
*\*\
**/
int main(void)
{
    /*!< At this stage the microcontroller clock setting is already configured,
         this is done through SystemInit() function which is called from startup
         file (startup_n32h47x_48x_xx.s) before to branch to application main.
         To reconfigure the default setting of SystemInit() function, refer to
         system_n32h47x_48x.c file
       */
    /* Initialize USART */
    log_init();
    log_info("\r\n RTC Init \r\n ");
    /* RTC date time alarm default value*/
    RTC_DateAndTimeDefaultVale();
    /* Enable the PWR clock */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_PWR | RCC_APB1_PERIPH_BKP, ENABLE);
    /* Allow access to RTC */
    PWR_BackupAccessEnable(ENABLE);
    if (USER_WRITE_BKP_DAT1_DATA != RTC_BKUPRgRead(1))
    {
        /* RTC clock source select */
        if(SUCCESS==RTC_CLKSourceConfig(RTC_CLK_SRC_TYPE_LSE, true, false))
        {
           RTC_PrescalerConfig();
           /* ALRMASS Value(128) = 500ms / (1 / (32768/128)) */
           RTC_ConfigAlarmSubSecond(RTC_A_ALARM, 128, RTC_SUBS_MASK_SS14_7);
           /* RTC date time and alarm regulate*/
           RTC_DateRegulate();
           RTC_TimeRegulate();
           RTC_AlarmRegulate(RTC_A_ALARM);
           RTC_BKUPRgWrite(1, USER_WRITE_BKP_DAT1_DATA);
           log_info("\r\n RTC Init Success\r\n");
        }
        else
        {
           log_info("\r\n RTC Init Faile\r\n");
        }
    }
    /* Alarm output I/O config */
    RTC_ConfigOutputType(RTC_OUTPUT_PUSHPULL);
    /* Alarm output I/O polarity */
    RTC_ConfigOutput(RTC_OUTPUT_ALA, RTC_OUTPOL_HIGH);
    
    /* Alarm out select option*/
    RTC_ClrIntPendingBit(RTC_INT_ALRA);
    EXTI17_RTCAlarm_Configuration(ENABLE);

    while (1)
    {
        if(RTC_Time_Out_Flag)
        {
            RTC_Time_Out_Flag=false;
            log_info("\r\n 500ms Alarm Wakeup \r\n");
        }
    }
}

