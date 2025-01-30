1������˵��

    �ò�����ʾ��USARTy��USARTz��ͨ����ѯ����ʶ��ʵ�ְ�˫��ģʽ��
����ͨ�š�
    ���ȣ�USARTy����TxBuffer1������USARTz��USARTz�������ݴ���RxBuffer2��
    ���USARTz����TxBuffer2������USARTy��USARTy�������ݴ���RxBuffer1��
    ��󣬷ֱ�Ƚ�������������뷢�����ݣ��ȽϽ������TransferStatus1����
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
	
	/* �������ģ�����÷���������:ʱ�ӣ�I/O�� */
    ϵͳʱ�����ã�
        N32H475/N32H482/N32H487:
            SystemClock��240MHz
        N32H474/N32H473:
            SystemClock��200MHz
    
    USART�������£�
    - ������ = 9600 baud
    - �ֳ� = 8����λ
    - 1ֹͣλ
    - У����ƽ���
    - Ӳ�������ƽ��ã�RTS��CTS�źţ�
    - �������ͷ�����ʹ��
    - ��˫��ģʽʹ��
    
    USART�����������£�
    - USART3_Tx.PA9    <------->   UART5_Tx.PA7

    
    ���Բ���������
    - Demo��KEIL�����±����������MCU
    - ��λ���к����β鿴����TransferStatus1��TransferStatus2�����У�
      PASSEDΪ����ͨ����FAILEDΪ�����쳣


4��ע������


1. Function description

    This test example demonstrates the identification of USARTy and USARTz through query detection to realize the half-duplex communication.
    First, USARTy sends TxBuffer1 data to USARTz, and USARTz receives data and stores it in RxBuffer2.
    Then, USARTz sends TxBuffer2 data to USARTy, and USARTy receives data and stores it in RxBuffer1.
    Finally, compare the two groups of received data and sent data, respectively, and store the comparison results in the TransferStatus1 variable and the TransferStatus2 variable.


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
            
    Print Serial Port Configuration:
        N32H474/N32H473/N32H482/N32H487:
            USART��TX - PA9��RX - PA10, baud rate 115200
        N32H475��
            USART��TX - PA9��RX - PA15, baud rate 115200
    
    USART is configured as follows:
    - Baud rate = 9600 baud
    - Word length = 8 data bits
    - 1 stop bit
    - checksum control disabled
    - Hardware flow control disabled (RTS and CTS signals)
    - Receiver and transmitter enable
    - Half-duplex mode enabled
    
    The USART pins are connected as follows:
    - USART3_Tx.PA9    <------->   UART5_Tx.PA7

    
    Test steps and phenomena:
    - Demo is compiled in KEIL environment and downloaded to MCU
    - After the reset operation, check the variables TransferStatus1 and TransferStatus2 in turn, among which,
      PASSED is the test passed, FAILED is the test abnormal

4. Attention
    the MCU_TX and MCU_RX jumper cap of the development board NS-LINK needs to be disconnected first