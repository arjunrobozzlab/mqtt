1������˵��

	/* ���������̹��� */
        ����������ò���ʾֱ�Ӷ�FLASH���ж�д����


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

	/* ����Demo�Ĳ��Բ�������� */
        1.��������س���λ���У�
        2.�鿴���ڴ�ӡ��Ϣ����д��FLASH���������ȡ���ݶԱȾ���ͬʱ����ӡ��ϢΪ���Խ�����


4��ע������


1. Function description

	/* Briefly describe the project function */
         This routine configures and demonstrates direct read and write operations to FLASH


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

	/* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. Check the printing information of the serial port. When the data written to FLASH is the same as the data read, the printing information is the end of the test;


4. Matters needing attention
