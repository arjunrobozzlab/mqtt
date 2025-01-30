1、功能说明

   1、SPI 全双工软件 NSS 模式发送接收数据

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
		SPI3配置：SCK--PC3、MISO--PD11、MOSI--PC1
	N32H473/474/482/487系列：
           		SPI5配置：SCK--PF7、MISO--PF8、MOSI--PF9
    4、SPI2配置（从）：
	N32H475系列：
		SCK--PC7、MISO--PC2、MOSI--PD2
	N32H473/474/482/487系列：
           		SCK--PC7、MISO--PC2、MOSI--PD2

   5、测试步骤与现象
    1、编译后下载程序复位运行；
    2、SPI主机 初始化位主机，发送数据，SPI2 初始化位丛机，接收数据 ，传输完成后，检查数据，查看 TransferStatus1 和 TransferStatus2 状态为 PASSED，
	SPI2 初始化位主机，发送数据，SPI主机 初始化位丛机，接收数据 ，传输完成后，检查数据，查看 TransferStatus3 和 TransferStatus4 状态为 PASSED；

4、注意事项
无


1. Function description

     1. SPI full-duplex software NSS mode to send and receive data

2. Usage environment

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
    3.SPI Master configuration:
	N32H475 series:
		SPI3 configuration: SCK--PC3, MISO--PD11, MOSI--PC1
	N32H473/474/482/487 series:
           		SPI5 configuration: SCK--PF7, MISO--PF8, MOSI--PF9
    4、SPI2 Configuration (Slave):
	N32H475 series:
		SCK--PC7, MISO--PC2, MOSI--PD2
	N32H473/474/482/487 series:
           		SCK--PC7, MISO--PC2, MOSI--PD2

   5, test steps and phenomena
     1. After compilation, the download program is reset and run;
     2. SPI Master initializes the bit host, sends data, SPI2 initializes the bit cluster machine, receives data, and after the transmission is completed, check the data, check that the status of TransferStatus1 and TransferStatus2 is PASSED,
         SPI2 initializes the bit host, sends data, SPI Master initializes the bit cluster machine, receives data, and after the transfer is completed, check the data, and check that the status of TransferStatus3 and TransferStatus4 is PASSED;

4. Matters needing attention
NO