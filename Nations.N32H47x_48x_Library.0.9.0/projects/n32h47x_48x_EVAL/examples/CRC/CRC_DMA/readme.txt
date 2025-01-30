﻿1、功能说明

    1、此例程展示了通过DMA传输数据计算CRC值。
    
    其中有16bit校验、LRC校验与32bit校验。
    

2、使用环境

      软件开发环境：
        IDE工具：KEIL MDK-ARM 5.34
	       IAR EWARM 8.50.1
    
    硬件开发环境：
        N32H473系列：
        基于评估板N32H473VEL7_STB V1.0开发
        N32H474系列：
        基于评估板N32H474VEL7_STB V1.0开发
        N32H475系列：
        基于评估板N32H475UEQ7_STB V1.0开发
        N32H482系列：
        基于评估板N32H482ZEL7_STB V1.0开发
        N32H487系列：
        基于全功能板N32H487ZEL7_EVB V1.0开发


3、使用说明

    1、时钟源：HSI+PLL
    2、系统时钟频率：
        N32H473/474系列：
        200MHz
        N32H475/482/487系列：
        240MHz
   3、打印：PA9 - baud rate 115200

   4、测试步骤与现象：
        1、在KEIL下编译后烧录到开发板，通电
        2、通过串口输出运行信息

4、注意事项
    无
    
    
1. Function description
    1. This routine demonstrates the calculation of CRC value via DMA transfer of data.  
     There are 16bit checksum, LRC checksum and 32bit checksum.
    

2. Use environment

    Software development environment:
        IDE tool: KEIL MDK-ARM 5.34
	       IAR EWARM 8.50.1
    
    Hardware development environment:
        N32H473 series:
        Based on evaluation board N32H473VEL7_STB V1.0 development
        N32H474 series:
        Based on evaluation board N32H474VEL7_STB V1.0 development
        N32H475 Series:
        Based on evaluation board N32H475UEQ7_STB V1.0 development
        N32H482 Series:
        Based on evaluation board N32H482ZEL7_STB V1.0 development
        N32H487 Series:
        Based on the full-featured board N32H487ZEL7_EVB V1.0 development

3. Instructions for use

     1. Clock source: HSI+PLL
     2. System clock frequency:
         N32H473/474 series:
         200MHz
         N32H475/482/487 series:
         240MHz
     3. printf: PA9 - baud rate 115200

     4. test steps and phenomena
         1. Compile under KEIL and burn to the development board, then power on
         2. Output running information through serial port

4. Matters needing attention
     None