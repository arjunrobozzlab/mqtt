1、功能说明
    1、通过设定闹钟时间亚秒匹配来触发闹钟中断。
    2、通过闹钟标志位来配置IO输出

2、使用环境

    软件开发环境：KEIL MDK-ARM V5.34
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
        基于评估板N32H487ZEL7_EVB V1.0开发


3、使用说明
    
    系统配置:
        1、RTC时钟源：LSE
        2、闹钟IO输出：PC13
        3、串口配置：
                    - 串口为USART1（TX：PA9  RX：PA10）:
                    - 数据位：8
                    - 停止位：1
                    - 奇偶校验：无
                    - 波特率： 115200 


    使用方法：
    编译后烧录到评估板，上电后，RTC闹钟每隔1s产生闹钟中断
    串口会打印:1s Alarm Wakeup  并且LED1 闪烁。


4、注意事项
    无

1. Function description

    1. Trigger the alarm interrupt by setting the alarm subsecond .
    2. Configure I/O output through the alarm flag

2. Use environment

    Software development environment: KEIL MDK-ARM V5.34
                                      IAR EWARM 8.50.1
									  
    Hardware development environment:
        N32H473 series:
        Developed based on the evaluation board N32H473VEL7_STB V1.0
        N32H474 series:
        Developed based on the evaluation board N32H474VEL7_STB V1.0
        N32H475 series:
        Developed based on the evaluation board N32H475UEQ7_STB V1.0
        N32H482 series:
        Developed based on the evaluation board N32H482ZEL7_STB V1.0
        N32H487 series:
        Developed based on the evaluation board N32H487ZEL7_EVB V1.0

3. Instructions for use

    System configuration:

        1. RTC clock source: LSE
        2. alarm IO output: PC13
        3. Serial port configuration:

                            - Serial port: USART1 (TX: PA9 RX: PA10) :
                            - Data bit: 8
                            - Stop bit: 1
                            - Parity check: None
                            - Baud rate: 115200

    Instructions:
        After compiling, it is burned to the evaluation board. After powering on, the RTC alarm clock generates alarm interruption every 1s.
        The serial port will print: 1s Alarm Wakeup, and LED1 blinking.

4. Matters needing attention
    None
