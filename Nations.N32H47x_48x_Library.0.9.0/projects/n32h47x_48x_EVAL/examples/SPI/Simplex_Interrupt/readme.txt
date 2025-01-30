1、功能说明

    1、SPI 单线中断发送和接收数据

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
    3、SPI主机配置：
	N32H475系列：
		SPI3配置：SCK--PC3、MOSI--PC1
	N32H473/474/482/487系列：
           		SPI5配置：SCK--PF7、MOSI--PF9
    4、SPI2配置（从）：
	N32H475系列：
		SCK--PC7、MISO--PC2
	N32H473/474/482/487系列：
           		SCK--PC7、MISO--PC2

   5、测试步骤与现象
    1.编译后下载程序复位运行；
    2.SPI主机 有数据需要发送时进入 SPI3/5_IRQHandler 中断函数发送，SPI2 有数据需要接收时进入 SPI2_IRQHandler 中断函数接收，
      数据传输完成后，查看 TransferStatus 状态为 PASSED；

4、注意事项
1、“单线”数据线在主设备端为MOSI引脚，在从设备端为MISO引脚
2、更改SPI重新编译时，建议清空之前的编译文件，如已编译过487，改为编译475时，需要先清空之前编译过的内容


1、Functional Description

    1, SPI single line interrupt send and receive data

2、Using environment

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

3、Use instructions

    1, clock source: HSI + PLL
    2、System clock frequency:
        N32H473/474 series:
        200MHz
        N32H475/482/487 series:
        240MHz
    3.SPI Master configuration:
	N32H475 series:
		SPI3 configuration: SCK--PC3, MOSI--PC1
	N32H473/474/482/487 series:
           		SPI5 configuration: SCK--PF7, MOSI--PF9
    4、SPI2 Configuration (Slave):
	N32H475 series:
		SCK--PC7, MISO--PC2
	N32H473/474/482/487 series:
           		SCK--PC7, MISO--PC2

   5. Test steps and phenomena
    1. Compile and download the program reset run;
    2. SPI Master has data to be sent into the SPI3/5_IRQHandler interrupt function to send, SPI2 has data to be received into the SPI2_IRQHandler interrupt function to receive.
      After the data transfer is completed, check the TransferStatus status is PASSED;

4. Notes
1，The "single wire" data line is MOSI pin on the master device side and MISO pin on the slave device side.
2, change the SPI recompile, it is recommended to clear the previous compilation file, such as has been compiled 487, to compile 475, you need to first clear the contents of the previous compilation!