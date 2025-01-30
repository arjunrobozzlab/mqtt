1、功能说明
       1、DVP接收OV5640传输的图像数据，通过FEMC显示在LCD上。
    
2、使用环境
    软件开发环境：KEIL MDK-ARM 5.34
                  IAR EWARM 8.50.1
    硬件开发环境：
        N32H487系列：
        基于评估板N32H487ZEL7_EVB V1.0开发
        基于摄像头（OV5640模组）
        基于TFT_LCD(320*240 驱动：ILI9341/800*480 驱动：ILI9806)
3、使用说明
    系统配置；
        1、时钟源：HSI+PLL
        2、时钟频率：
       	N32H4487系列：
                HSI=8M,SYS CLK=240M,FEMC CLK=240M
        3、端口配置：
		LCD端口:
                CS:PG12      RS:PD13      WR:PD5      RD:PD4      
                RST:PA1
                D0:PD14     D1:PD15     D2:PD0      D3:PD1      
                D4:PE7      D5:PE8      D6:PE9      D7:PE10     
                D8:PE11     D9:PE12     D10:PE13    D11:PE14    
                D12:PE15    D13:PD8     D14:PD9     D15:PD10
		LCD背光控制端口：PF7
		OV5640 模组端口:
				PCLK:PE4    HSYNC:PE2    VSYNC:PE3    D0:PE5
				D1:PE6      D2:PG10      D3:PG11      D4:PB10
				D5:PB11     D6:PB0      D7:PB1   RST:PB4
				PWDN:PB3    SCL:PB2        SDA:PB7
    使用方法：
	1、编译并下载代码运行，LCD上显示摄像头图像。
4、注意事项
	无


1. Function description
	1. The DVP receives the image data transmitted by the OV5640 and displays it on the LCD via the FEMC.

2. Use environment
    Software development environment: KEIL MDK-ARM 5.34
                                      IAR EWARM 8.50.1
    Hardware development environment:
        N32H487 series:
        Based on evaluation board N32H487ZEL7_EVB V1.0 development
		Based camera (OV5640 module)
		Based on TFT_LCD(320*240 Driver: ILI9341/800*480 驱动：ILI9806)

3. Instructions for use
    System Configuration;
        1. Clock source: HSI+PLL
        2. Clock frequency: 
            N32H4487 series:
                HSI=8M,SYS CLK=240M,FEMC CLK=240M
        2. Port Configuration:
		   LCD port:
                CS:PD7      RS:PG0      WR:PD5      RD:PD4      
                RST:PA1
                D0:PD14     D1:PD15     D2:PD0      D3:PD1      
                D4:PE7      D5:PE8      D6:PE9      D7:PE10     
                D8:PE11     D9:PE12     D10:PE13    D11:PE14    
                D12:PE15    D13:PD8     D14:PD9     D15:PD10
			LCD backlight control port：PA2
			OV5640 module port:
				PCLK:PE4    HSYNC:PE2    VSYNC:PE3    D0:PE5
				D1:PE6      D2:PG10      D3:PG11      D4:PB10
				D5:PB11     D6:PB0       D7:PB1       RST:PB4
				PWDN:PB3    SCL:PB2      SDA:PB7
    Instructions:
		1、Compile and download the code to run, and the camera image is displayed on the LCD.
4. Matters needing attention
    none