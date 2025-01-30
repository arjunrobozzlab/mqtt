1������˵��

    /* ���������̹��� */
        ����������ò���ʾNVIC�ж��������ض�λ


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
            
    EXIT��PA4Ϊ��������ģʽ���ⲿ�ж��� - EXIT_LINE4�������ⲿ�жϣ����ȼ�Ϊ0

    /* ����Demo�Ĳ��Բ�������� */
        1.��������س���λ���У�
        2.һ��ʼ������λ��FLASH�����������º��������ض�λ��SRAM������ӡ�����Ϣ����������������


4��ע������


1. Function description
    /* A brief description of the engineering function */
    This routine configures and demonstrates NVIC interrupt directional table relocation

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
    EXIT: PA4 is floating input mode, external interrupt line -exit_line4, external interrupt is enabled, and the priority is 0
    /* Describes the test steps and symptoms of Demo */
    1. Reset and run the downloaded program after compilation;
    2. At the beginning, the directional table is located in FLASH. When the button is pressed, the backward table is repositioned to SRAM and relevant information is printed, and the program runs normally;

4. Precautions
    None