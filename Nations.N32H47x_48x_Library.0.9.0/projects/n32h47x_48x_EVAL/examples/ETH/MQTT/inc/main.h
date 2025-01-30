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

#include <stdio.h>
#include <string.h>

#include "n32h47x_48x.h"
#include "n32h47x_48x_eth.h"
#include "n32h47x_48x_rcc.h"
#include "n32h47x_48x_gpio.h"
#include "n32h47x_48x_exti.h"
#include "n32h47x_48x_it.h"
#include "log.h"
#include "delay.h"
#include "dht11.h"


/* Static IP ADDRESS: IP_ADDR0.IP_ADDR1.IP_ADDR2.IP_ADDR3 */
#define IP_ADDR0                    ((uint8_t)192U)
#define IP_ADDR1                    ((uint8_t)168U)
#define IP_ADDR2                    ((uint8_t)0U)
#define IP_ADDR3                    ((uint8_t)32U)

/* NETMASK: NETMASK_ADDR0.NETMASK_ADDR1.NETMASK_ADDR2.NETMASK_ADDR3 */
#define NETMASK_ADDR0               ((uint8_t)255U)
#define NETMASK_ADDR1               ((uint8_t)255U)
#define NETMASK_ADDR2               ((uint8_t)255U)
#define NETMASK_ADDR3               ((uint8_t)0U)

/* Gateway Address: GW_ADDR0.GW_ADDR1.GW_ADDR2.GW_ADDR3 */
#define GW_ADDR0                    ((uint8_t)192U)
#define GW_ADDR1                    ((uint8_t)168U)
#define GW_ADDR2                    ((uint8_t)0U)
#define GW_ADDR3                    ((uint8_t)1U)


#define NETWORK_APP_TASK_STACK_SIZE (512)
#define NETWORK_APP_TASK_PRIORITY   (1)


#define MESSAGE_QUEUE_LEN           (4)
#define MESSAGE_SIZE                (sizeof(DHT11DataType))


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */


