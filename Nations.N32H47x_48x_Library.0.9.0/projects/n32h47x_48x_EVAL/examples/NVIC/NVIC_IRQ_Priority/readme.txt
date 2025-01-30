1������˵��

    /* ���������̹��� */
        ����������ò���ʾNVIC���ȼ�����


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
            
    ��ӡ�������ã�
        N32H474/N32H473/N32H482/N32H487:
            USART��TX - PA9��RX - PA10��������115200
        N32H475��
            USART��TX - PA9��RX - PA15��������115200
            
    N32H487ϵ�У�
        EXIT��PA15Ϊ��������ģʽ���ⲿ�ж��� - EXIT_LINE15�������ⲿ�ж�
    N32H482/N32H475/N32H474/N32H473ϵ��:
        EXIT��PA4Ϊ��������ģʽ���ⲿ�ж��� - EXIT_LINE4�������ⲿ�ж�
        
        SysTick���ж����ȼ�����Ϊ0

    /* ����Demo�Ĳ��Բ�������� */
        1.��������س���λ���У�
        2.��������´�ӡSysTick�ж���Ϣ���������ⲿ�жϺ�SysTick�ж�ͬʱ����ʱ���޸�SysTick�ж����ȼ�Ϊ2������ӡ�����Ϣ����������������


4��ע������


1. Function description
    /* A brief description of the engineering function */
    This routine configures and demonstrates NVIC priority Settings

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
            
    N32H487��               
        EXIT: PA15 is in floating input mode, and external interrupt line -exit_line15 is used to enable external interrupt
    N32H482/N32H475/N32H474/N32H473��               
        EXIT: PA4 is in floating input mode, and external interrupt line -exit_line4 is used to enable external interrupt
        
    SysTick: Set the interrupt priority to 0
    
    /* Describes the test steps and symptoms of Demo */
    1. Reset and run the downloaded program after compilation;
    2. In normal cases, SysTick interrupt information is displayed. If both the external interrupt and SysTick interrupt are triggered at the same time, change the SysTick interrupt priority to 2 and print related information.

4. Precautions
    None