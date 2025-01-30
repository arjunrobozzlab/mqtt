1������˵��
    1��ͨ��EXTI��������ʱ�����

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
        1��ʱ��Դ��LSE
        2��EXTI�ж�IO��PB8
        3���������ã�
                    - ����ΪUSART1��TX��PA9  RX��PA10��:
                    - ����λ��8
                    - ֹͣλ��1
                    - ��żУ�飺��
                    - �����ʣ� 115200 
    ʹ�÷�����
        �������¼�������壬��PC13���ӵ�PB8���ϵ�󣬴���ÿ��1S���ӡʱ��������

4��ע������
    ��


1. Function description

    1. The timestamp is triggered by the EXTI line.

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

        1. Clock source: LSE
        2. EXTI interrupt IO: PB8
        3. Serial port configuration:

                            - Serial port: USART1 (TX: PA9 RX: PA10) :
                            - Data bit: 8
                            - Stop bit: 1
                            - Parity check: None
                            - Baud rate: 115200

    Instructions:
        After compiling, it is burned to the evaluation board. After connecting PC13 to PB8, the serial port will print timestamp output every 1S after power-on.

4. Matters needing attention
    None