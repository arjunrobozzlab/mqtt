1������˵��

    �ò�����ʾ��USARTy��USARTz��ʹ��Ӳ�������ƵĻ���ͨ�š�
    ���ȣ�USARTy����CTS����TxBuffer1���ݣ�USARTz����RTS����
���ݣ�����RxBuffer2�����USARTz����CTS����TxBuffer2���ݣ�USARTy
����RTS�������ݣ�����RxBuffer1��
    ��󣬱ȽϽ��������뷢�����ݣ��ȽϽ���ֱ�������TransferStatus1
��TransferStatus2��

2��ʹ�û���

    �������������KEIL MDK-ARM V5.34.0.0
                  IAR EWARM 8.50.1
    
    Ӳ������������    
        N32H473ϵ�У�
        ����������N32H473VEL7_STB V1.0����
        N32H474ϵ�У�
        ����������N32H474VEL7_STB V1.0����
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
    
    USARTy�������£�
    - ������ = 115200 baud
    - �ֳ� = 8����λ
    - 1ֹͣλ
    - У����ƽ���
    - CTSӲ��������ʹ��
    - ������ʹ��   
    
    USARTz�������£�
    - ������ = 115200 baud
    - �ֳ� = 8����λ
    - 1ֹͣλ
    - У����ƽ���
    - RTSӲ��������ʹ��
    - ������ʹ��   
    
    
    USART�����������£�    
    - USART1_Tx.PA9 <-------> USART2_Rx.PA3
    - USART1_Rx.PA10 <-------> USART2_Tx.PA2
    - USART1_CTS.PA11 <-------> USART2_RTS.PA1
    - USART1_RTS.PA12 <-------> USART2_CTS.PA0

    
    ���Բ���������
    - Demo��KEIL�����±����������MCU
    - ��λ���У����β鿴����TransferStatus1��TransferStatus2�����У�
      PASSEDΪ����ͨ����FAILEDΪ�����쳣


4��ע������

    ���Ƚ�������NS-LINK��MCU_TX��MCU_RX����ñ�Ͽ�



1. Function description

    This test example demonstrates basic communication between USARTy and USARTz using hardware flow control.
    First, USARTy uses CTS to send TxBuffer1 data, USARTz uses RTS to receive.
    The data is stored in RxBuffer2; then, USARTz uses CTS to send TxBuffer2 data, USARTy use RTS to receive data and store it in RxBuffer1.
    Then, compare the received data with the sent data, and store the comparison results in the variable TransferStatus1 and TransferStatus2.

2. Use environment

    Software development environment: KEIL MDK-ARM V5.34.0.0
                                      IAR EWARM 8.50.1
    Hardware development environment:
        N32H473 series:
        Developed based on the evaluation board N32H473VEL7_STB V1.0
        N32H474 series:
        Developed based on the evaluation board N32H474VEL7_STB V1.0
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
    
    USARTy is configured as follows:
    - Baud rate = 115200 baud
    - Word length = 8 data bits
    - 1 stop bit
    - checksum control disabled
    - CTS hardware flow control enabled
    - Transmitter enable
    
    USARTz is configured as follows:
    - Baud rate = 115200 baud
    - Word length = 8 data bits
    - 1 stop bit
    - checksum control disabled
    - RTS hardware flow control enabled
    - Receiver enable
    
    
    The USART pins are connected as follows:
    - USART1_Tx.PA9 <-------> USART2_Rx.PA3
    - USART1_Rx.PA10 <-------> USART2_Tx.PA2
    - USART1_CTS.PA11 <-------> USART2_RTS.PA1
    - USART1_RTS.PA12 <-------> USART2_CTS.PA0

    
    Test steps and phenomena:
    - Demo is compiled in KEIL environment and downloaded to MCU
    - Reset operation, check the variables TransferStatus1 and TransferStatus2 in turn, where,
      PASSED is the test passed, FAILED is the test abnormal

4. Attention
    the MCU_TX and MCU_RX jumper cap of the development board NS-LINK needs to be disconnected first