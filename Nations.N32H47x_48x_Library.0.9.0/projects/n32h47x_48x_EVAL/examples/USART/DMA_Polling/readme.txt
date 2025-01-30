1������˵��

    �ò�����ʾ��USARTy��USARTz��ͨ��DMA����ѯ��ʵ�ֵĻ���ͨ�š�
    ���ȣ�DMA����TxBuffer1������USARTy�������ݼĴ�����������ݷ�����
USARTz��USARTz�������ݣ�DMA��USARTz�������ݼĴ�������������RxBuffer2��
�Ƚ��ա������ݣ��ȽϽ������TransferStatus2������
    ͬʱ��DMA����TxBuffer2������USARTz�������ݼĴ�����������ݷ�����
USARTy��USARTy�������ݣ�DMA��LPUART�������ݼĴ�������������RxBuffer1��
�Ƚ��ա������ݣ��ȽϽ������TransferStatus1������   


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
	
	/* �������ģ�����÷���������:ʱ�ӣ�I/O�� */
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
    - DMA����ģʽ��DMA����ģʽʹ��
    
    USART�����������£�
     - USART3_Tx.PA9 <-------> UART5_Rx.PA3
     - USART3_Rx.PA15 <-------> UART5_Tx.PA2 

    
    ���Բ���������
    - Demo��KEIL�����±����������MCU
    - ��λ���У����β鿴����TransferStatus1��TransferStatus2�����У�
      PASSEDΪ����ͨ����FAILEDΪ�����쳣


4��ע������

    ���Ƚ�������NS-LINK��MCU_TX��MCU_RX����ñ�Ͽ�



1. Function description

     This test example demonstrates basic communication between USARTy and USARTz through DMA. 
     First, the DMA transfers the TxBuffer1 data to the USARTy transmit data register, and then the data is sent to the 
     USARTz. USARTz uses the interrupt to receive data and store it in RxBuffer2. 
     At the same time, the DMA transfers the TxBuffer2 data to the USARTz transmit data register, and then the data is 
     sent to the USARTy. USARTy receives data by querying the check flag and stores it in RxBuffer1. 
     Finally, the two groups of receiving and sending data are compared respectively, and the comparison results are 
     stored in the TransferStatus1 variable and the TransferStatus2 variable. 


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
     - DMA transmit mode enabled, DMA receive mode disabled
    
     The USART pins are connected as follows:
     - USART3_Tx.PA9 <-------> UART5_Rx.PA3
     - USART3_Rx.PA15 <-------> UART5_Tx.PA2 

    
     Test steps and phenomena:
     - Demo is compiled in KEIL environment and downloaded to MCU
     - Reset operation, check the variables TransferStatus1 and TransferStatus2 in turn, where,
       PASSED is the test passed, FAILED is the test abnormal


4. Attention
    the MCU_TX and MCU_RX jumper cap of the development board NS-LINK needs to be disconnected first