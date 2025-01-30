1������˵��

    /* ���������̹��� */
        ����������ò���ʾ��FPU�ĸ������㵥Ԫ


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
        ����������N32H487ZEL7_EVB V1.0�����


3��ʹ��˵��

    /* �������ģ�����÷���������:ʱ�ӣ�I/O�� */
    N32H475/N32H482/N32H487:
        SystemClock��240MHz
        USART��TX - PA9��������115200
    N32H474/N32H473:
        SystemClock��200MHz
        USART��TX - PA9��������115200

    /* ����Demo�Ĳ��Բ�������� */
        1.��������س���λ���У�
        2.ʹ��Julia��װ����FPU���鿴��ӡ����Ϣ�����Ƚϴ򿪻�ر�FPU��Ԫ�ļ���ʱ�䡣


4��ע������
    ��



1. Function description
    /* A brief description of the engineering function */
    This routine configures and demonstrates the FPU floating point arithmetic unit

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
    /* Describe the related module configuration method; For example: clock, I/O, etc. */
    N32H475/N32H482/N32H487:
        SystemClock: 240MHZ
        USART: TX-PA9, baud rate 115200
    N32H474/N32H473:
        SystemClock: 200MHZ
        USART: TX-PA9, baud rate 115200
    /* Describes the test steps and symptoms of Demo */
    1. Reset and run the downloaded program after compilation;
    2. Use the Julia set to test the FPU, view the printed information, and compare the calculation time of opening or closing the FPU unit.

4. Precautions
    None