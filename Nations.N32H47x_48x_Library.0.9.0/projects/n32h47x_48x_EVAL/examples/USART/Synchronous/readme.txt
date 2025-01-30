1������˵��

    �ò�����ʾ��USARTy��ͬ��ģʽ����SPIy��ͨ����ѯ����ʶʵ�ֵĻ���ͨ�š�
    ���ȣ�ͨ��TXC����־��USARTy����TxBuffer1������SPIy����SPIy�������ݣ�
���ѯRNE����־�����յ����ݴ���RxBuffer1��
    ���SPIyͨ����ѯTE����־������TxBuffer2������USARTy��USARTy������
RXDNE����־�������ݣ��������RxBuffer2��
    ��󣬷ֱ�Ƚ������ա������ݣ��ȽϽ������TransferStatus1����
��TransferStatus2������


2��ʹ�û���

    �������������KEIL MDK-ARM V5.34.0.0
                  IAR EWARM 8.50.1
    
    Ӳ������������    
        N32H473ϵ�У�
        ����������N32H473VEL7_STB V1.0����
        N32H474ϵ�У�
        ����������N32H474VEL7_STB V1.0����
        N32H475ϵ�У�
        ����������N32H475UEQ7_STB V1.0����
        N32H482ϵ�У�
        ����������N32H482ZEL7_STB V1.0����
        N32H487ϵ�У�
        ����������N32H487ZEL7_EVB V1.0����

3��ʹ��˵��

    ϵͳʱ�����ã�
        N32H475/N32H482/N32H487:
            SystemClock��240MHz
        N32H474/N32H473:
            SystemClock��200MHz
    
    USART�������£�
    - ������ = 115200 baud
    - �ֳ� = 8����λ
    - 1ֹͣλ
    - У����ƽ���
    - Ӳ�������ƽ��ã�RTS��CTS�źţ�
    - �������ͷ�����ʹ��
    - ʱ��ʹ��
    - ʱ�Ӽ��ԣ������ⷢ��ʱ���ֵ͵�ƽ
    - ʱ����λ���ڵڶ���ʱ�ӱ��ز�����һ������
    - ���һλʱ�����壺���һλ���ݵ�ʱ�������CK���
    
    SPI�������£�
    - ���� = ��˫��˫��ģʽ
    - ģʽ = ��ģʽ
    - ���ݴ�С = 8λ����֡
    - CPOL = ����״̬ʱ��ʱ�ӱ��ֵ͵�ƽ
    - CPHA = ���ݲ����ӵڶ���ʱ�ӱ��ؿ�ʼ
    - NSS = ����������豸����
    - ��1λ = ��1λΪLSB
    
    
    USART�����������£�    
    - USART1_Tx.PA9 <-------> SPI1_MOSI.PA7
    - USART1_Rx.PA10 <-------> SPI1_MISO.PA6
    - USART1_Clk.PA8 <-------> SPI1_SCK.PA5
    
    ���Բ���������
    - Demo��KEIL�����±����������MCU
    - �����ڴ�ӡ��ñ�γ�
    - ��λ���У����β鿴����TransferStatus1��TransferStatus2�����У�
      PASSEDΪ����ͨ����FAILEDΪ�����쳣


4��ע������

    ���Ƚ�������NS-LINK��MCU_TX��MCU_RX����ñ�Ͽ�


1. Function description

    This test example demonstrates basic communication between USARTy (synchronous mode) and SPIy by querying the detection flag.
    USARTy and SPIy can be USART1 and SPI1, USART3 and SPI1, or USART2 and SPI2.
    First, through the TXC detection flag, USARTy sends TxBuffer1 data to SPIy, and SPIy receives data,then query the RNE detection flag, 
    and store the received data in RxBuffer1.Then, SPIy sends TxBuffer2 data to USARTy by querying the TE detection flag. USARTy uses
    the RXDNE detection flag receives data and stores it in RxBuffer2.
    Finally, compare the two groups of receiving and sending data respectively, and store the comparison results in the TransferStatus1 variable
    and the TransferStatus2 variable.

2. Use environment

    Software development environment: KEIL MDK-ARM V5.34.0.0
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

	/* Describe related module configuration methods; for example: clock, I/O, etc. */
    System Clock Configuration:
        N32H475/N32H482/N32H487:
            SystemClock��240MHz
        N32H474/N32H473:
            SystemClock��200MHz
    
    USART is configured as follows:
    - Baud rate = 115200 baud
    - Word length = 8 data bits
    - 1 stop bit
    - checksum control disabled
    - Hardware flow control disabled (RTS and CTS signals)
    - Receiver and transmitter enable
    - Clock enable
    - Clock polarity: keep low when not sending out
    - Clock Phase: The first data is sampled on the second clock edge
    - Last bit clock pulse: The clock pulse of the last bit of data is output from CK
    
    The SPI configuration is as follows:
    - Direction = "Two-Line Bidirectional" mode
    - mode = slave mode
    - data size = 8-bit data frame
    - CPOL = when idle, the clock remains low
    - CPHA = data sampling starts on second clock edge
    - NSS = Enable Software Slave Device Management
    - 1st bit = 1st bit is LSB
    
    
    The USART pins are connected as follows:
    - USART1_Tx.PA9 <-------> SPI1_MOSI.PA7
    - USART1_Rx.PA10 <-------> SPI1_MISO.PA6
    - USART1_Clk.PA8 <-------> SPI1_SCK.PA5
    
    Test steps and phenomena:
    - Demo is compiled in KEIL environment and downloaded to MCU
    - Remove the serial print jump cap
    - Reset operation, check the variables TransferStatus1 and TransferStatus2 in turn, where,
      PASSED is the test passed, FAILED is the test abnormal


4. Attention
    the MCU_TX and MCU_RX jumper cap of the development board NS-LINK needs to be disconnected first