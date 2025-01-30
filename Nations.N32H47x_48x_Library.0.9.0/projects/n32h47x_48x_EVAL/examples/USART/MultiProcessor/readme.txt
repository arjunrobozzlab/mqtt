1������˵��

    �ò�����ʾ�����ʹ��USART�ദ����ģʽ�
    ���ȣ��ֱ�����USARTy��USARTz�ĵ�ַΪ0x1��0x2��USARTy������USARTz
�����ַ�0x33��USARTz�յ�0x33���㷭תLED1�����š�
    һ��KEY1_INT_EXTI_LINE�߼�⵽�����أ������EXTI0�жϣ���
EXTI0_IRQHandler�жϴ�������(the ControlFlag = 0)��USARTz���뾲Ĭ
ģʽ���ھ�Ĭģʽ�У�LED����ֹͣ��ת��ֱ��KEY1_INT_EXTI_LINE�߼�⵽
������(the ControlFlag = 1)����EXTI0_IRQHandler�жϴ������У�USARTy
���͵�ַ0x102����USARTz��LED��������������ת��


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
    
    USARTy�������£�
    - ������ = 115200 baud
    - �ֳ� = 9����λ
    - 1ֹͣλ
    - У����ƽ���
    - Ӳ�������ƽ��ã�RTS��CTS�źţ�
    - �������ͷ�����ʹ��  
    
    
    USART�����������£�    
     - USART3_Tx.PA9 <-------> UART5_Rx.PA3
     - USART3_Rx.PA15 <-------> UART5_Tx.PA2
    
    N32H487ϵ�У�
        EXIT��PC13Ϊ��������ģʽ���ⲿ�ж��� - EXIT_LINE13�������ⲿ�ж�
    N32H482/N32H475/N32H474/N32H473ϵ��:
        EXIT��PA4Ϊ��������ģʽ���ⲿ�ж��� - EXIT_LINE4�������ⲿ�ж�
        
    LED <-------> PA8

    
    ���Բ���������
    - Demo��KEIL�����±����������MCU
    - ��λ���У��۲�LED1�Ƿ�����˸״̬
    - ������KEY���۲�LED1�Ƿ�ֹͣ��˸
    - �ٴΰ�����KEY���۲�LED1�Ƿ�ָ���˸


4��ע������
   ���Ƚ�������NS-LINK��MCU_TX��MCU_RX����ñ�Ͽ�


1. Function description
    This test example demonstrates how to use the USART multiprocessor mode.
    First, set the addresses of USARTy and USARTz to 0x1 and 0x2, respectively. USARTy continuously gives USARTz send the character
    0x33. USARTz receives 0x33 and flips the pin of LED1.
    Once a rising edge is detected on the KEY1_INT_EXTI_LINE line, an EXTI0 interrupt will be generated.
    In the EXTI0_IRQHandler interrupt handler (the ControlFlag = 0), USARTz goes silent mode, in silent mode, the LED pin stops toggling.
    toggling until the KEY1_INT_EXTI_LINE line detects rising edge (the ControlFlag = 1). In the EXTI0_IRQHandler interrupt handler, 
    USARTysend address 0x102 to wake up USARTz. The LED pin restarts toggling.


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
    
    USARTy is configured as follows:
    - Baud rate = 115200 baud
    - Word length = 9 data bits
    - 1 stop bit
    - checksum control disabled
    - Hardware flow control disabled (RTS and CTS signals)
    - Receiver and transmitter enable
    
    
    The USART pins are connected as follows:
     - USART3_Tx.PA9 <-------> UART5_Rx.PA3
     - USART3_Rx.PA15 <-------> UART5_Tx.PA2
    
    N32H487��               
        EXIT: PC13 is in floating input mode, and external interrupt line -exit_line13 is used to enable external interrupt
    N32H482/N32H475/N32H474/N32H473��               
        EXIT: PA4 is in floating input mode, and external interrupt line -exit_line4 is used to enable external interrupt
        
    
    LED <-------> PA8

    
    Test steps and phenomena:
    - Demo is compiled in KEIL environment and downloaded to MCU
    - Reset operation and observe whether LED1 are blinking
    - Press the button KEY and observe whether LED1 stop flashing
    - Press the button KEY again and observe whether LED1 resume to flash


4. Attention
    the MCU_TX and MCU_RX jumper cap of the development board NS-LINK needs to be disconnected first