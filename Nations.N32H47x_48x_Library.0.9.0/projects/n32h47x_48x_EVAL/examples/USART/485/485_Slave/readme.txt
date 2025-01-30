1������˵��

    �ò�����ʾ�����鿪����USARTz��ͨ���ж�ʵ�ֵĻ���ͨ�š�
    Master����TxBuffer2������Slave��USARTz�������ݴ���RxBuffer2��
    �ȽϽ��������뷢�����ݣ��ȽϽ������TransferStatus������


2��ʹ�û���

    �������������KEIL MDK-ARM V5.34.0.0
                  IAR EWARM 8.50.1
    
    Ӳ������������    
        N32H487ϵ�У�
        ����������N32H487ZEL7_STB V1.0����
        

3��ʹ��˵��
	
	/* �������ģ�����÷���������:ʱ�ӣ�I/O�� */
    ϵͳʱ�����ã�
        N32H487:
            SystemClock��240MHz
    
    USART�������£�
    - ������ = 115200 baud
    - �ֳ� = 8����λ
    - 1ֹͣλ
    - У����ƽ���
    - Ӳ�������ƽ��ã�RTS��CTS�źţ�
    - �������ͷ�����ʹ��
    
    USART�����������£�   
    Master:
     - UART5_Rx.PG7
     - UART5_Tx.PG6 
     - UART5_DE.PG15 
     - 485ģ��
    Slave:
     - UART5_Rx.PG7
     - UART5_Tx.PG6 
     - UART5_DE.PG15
     - 485ģ��
     
     485���ӣ�
     A<--->A
     B<--->B

    
    ���Բ���������
    - Demo��KEIL�����±���󣬷ֱ�����Master��Slavedemo��Master��Slave������
    - ��λ���У��鿴���ڴ�ӡ��Ϣ��PASSEDΪ����ͨ����FAILEDΪ�����쳣


4��ע������

    ���Ƚ�������NS-LINK��MCU_TX��MCU_RX����ñ�Ͽ�
    Master�����������ϵ磬Slave���ϵ�




1. Function description

    This test case demonstrates basic communication between two development board USARTz via interrupts.
    The Master sends TxBuffer2 data to the Slave and the USARTz receives the data and stores it in RxBuffer2.
    The received data is compared with the sent data and the comparison is stored in the TransferStatus variable.

2. Use environment

    Software development environment: KEIL MDK-ARM V5.34.0.0
                                      IAR EWARM 8.50.1
    Hardware development environment:
        N32H487 series:
        Developed based on the evaluation board N32H487ZEL7_STB V1.0
        

3. Instructions for use

	/* Describe related module configuration methods; for example: clock, I/O, etc. */
    System Clock Configuration:
        N32H487:
            SystemClock��240MHz

    USART is configured as follows:
    - Baud rate = 115200 baud
    - Word length = 8 data bits
    - 1 stop bit
    - checksum control disabled
    - Hardware flow control disabled (RTS and CTS signals)
    - Receiver and transmitter enable
    - DMA transmit mode enabled, DMA receive mode disabled

    Master.
     - UART5_Rx.PG7
     - UART5_Tx.PG6 
     - UART5_DE.PG15 
     - 485 Module
    Slave: UART5_Rx.
     - UART5_Rx.PG7
     - UART5_Tx.PG6 
     - UART5_DE.PG15
     - 485 Module
     
     485 connection:
     A<--->A
     B<--->B

    Test steps and phenomena:
    - After the demo is compiled in KEIL environment, download Master and Slavedemo to Master and Slave development boards respectively.
    - Reset running, Viewing Serial Port Printing Information, PASSED for the test passed, FAILED for the test exception

4. Attention
    the MCU_TX and MCU_RX jumper cap of the development board NS-LINK needs to be disconnected first
    The Master board needs to be powered up first, then the Slave.