1������˵��
    1��ͨ��EXTI��������������ӡ�����

2��ʹ�û���

    �������������KEIL MDK-ARM V5.34
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
    
    ϵͳ����:
        1��RTCʱ��Դ��LSE
        2���ж��ߣ�EXTI_LINE7
        3���������ã�
                            - ����ΪUSART1��TX��PA9  RX��PA10��:
                            - ����λ��8
                            - ֹͣλ��1
                            - ��żУ�飺��
                            - �����ʣ� 115200 
    ʹ�÷�����
        �������¼�������壬PC13���ӵ�PA7�ڣ��ϵ�󣬴���ÿ��1S���ӡһ�ζ�Ӧ����ʱ��

4��ע������
    ��


1. Function description

    1. Trigger calendar printout through EXTI line.

2. Use environment

    Software development environment: KEIL MDK-ARM V5.34
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

    System configuration:

        1. RTC clock source: LSE
        2. EXTI line: EXTI_LINE7
        3. Serial port configuration:

                            - Serial port: USART1 (TX: PA9 RX: PA10) :
                            - Data bit: 8
                            - Stop bit: 1
                            - Parity check: None
                            - Baud rate: 115200

    Instructions:
        After compilation, it is burned to the evaluation board. PC13 is connected to PA7 port. After power-on, the serial port prints the corresponding calendar time every 1S

4. Matters needing attention
    None