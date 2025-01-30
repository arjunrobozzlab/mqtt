1������˵��

    /* ���������̹��� */
        ����������ò���ʾʹ��EXIT�ⲿ�жϼ�TIM��ʱ���ж�


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
    
    TIM��Ԥ��Ƶϵ�� - ��SystemClock/50000-1�������� - ��50000-1����������ʱ���ж�

    /* ����Demo�Ĳ��Բ�������� */
        1.��������س���λ���У�
        2.�鿴���ڴ�ӡ��Ϣ����ʱ���ж���Ϣÿ1S��ӡһ�Σ����°�����ӡֹͣ���ٴΰ����������ӡ��������������������


4��ע������



1. Function description
    /* A brief description of the engineering function */
    This routine configures and demonstrates the use of EXIT external interrupts and TIM timer interrupts

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
        
    TIM: Pre-dividing frequency coefficient - (SystemClock/1200-1), period - (1200-1), start timer interrupt
    /* Describes the test steps and symptoms of Demo */
    1. Reset and run the downloaded program after compilation;
    2. Check the serial port printing information. The timer interrupt information is printed every 1S.
       Press the button to stop printing, and press it again to continue printing, indicating that the program is running normally.

4. Precautions
    None
