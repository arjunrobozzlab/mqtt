1������˵��

    �ò�����ʾ��USARTy��USARTz��ʵ�ִ���IrDA�͹���ģʽ������빦�ܵĻ���ͨ�š�
    ���ȣ�USARTy����TxBuffer1������USARTz��USARTzͨ���жϽ������ݴ���RxBuffer1��
    ��󣬱ȽϽ��������뷢�����ݣ��ȽϽ������TransferStatus������


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

    IrDA��������������


3��ʹ��˵��

    ϵͳʱ���������£�
    - ʱ��Դ = HSE
    - ϵͳʱ�� = 60MHz
    
    USART�������£�
    - ������ = 1200 baud
    - �ֳ� = 8����λ
    - 1ֹͣλ
    - У����ƽ���
    - Ӳ�������ƽ��ã�RTS��CTS�źţ�
    - �������ͷ�����ʹ��
    - IrDAģʽʹ��
    
    USART�����������£�
    N32H475/N32H474/N32H473/N32H482:
    - USART3_Tx.PA9    <------->   IrDA Transmitter
    - UART5_Rx.PA3    <------->   IrDA Receiver   
    - GPIO.PD2         <------->   38kHz carrier
    
    N32H487:
    - USART3_Tx.PG6    <------->   IrDA Transmitter
    - UART5_Rx.PH3    <------->   IrDA Receiver   
    - GPIO.PA8         <------->   38kHz carrier

    
    ���Բ���������
    - ��λ����MCU���鿴����TransferStatus�����У�PASSEDΪ����ͨ����FAILEDΪ�����쳣


4��ע������

1. Function description

    This test example demonstrates the basic communication between USARTy and USARTz to realize the infrared 
    decoding function of serial IrDA low power consumption mode.
    First, USARTy sends TxBuffer1 data to USARTz, and USARTz receives data through interrupt and stores it in RxBuffer1.
    Subsequently, compare the received data with the sent data, and the result of the comparison is stored in the 
    TransferStatus variable.


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
    IrDA transmitter and receiver


3. Instructions for use

    The system clock configuration is as follows:
    -Clock source = HSE
    -System clock = 60MHz
    
    The USART configuration is as follows:
    -Baud rate = 1200 baud
    -Word length = 8 data bits
    -1 stop bit
    -Verification control disabled
    -Hardware flow control disabled (RTS and CTS signals)
    -Receiver and transmitter enable
    -IrDA mode enable
    
    The USART pin connections are as follows:
    - USART3_Tx.PA9    <------->   IrDA Transmitter
    - UART5_Rx.PA3    <------->   IrDA Receiver
    
    - GPIO.PD2         <------->   38kHz carrier

    
    Test steps and phenomena:
-Reset and run the MCU, check the variable TransferStatus, where PASSED means the test passed and FAILED means the test is abnormal


4. Matters needing attention