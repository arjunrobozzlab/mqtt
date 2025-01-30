1������˵��
    1��ͨ���趨����ʱ�䴥���жϡ�
    2��ͨ�����ѱ�־λ������IO���

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
        1�������Ի���ʱ��Դ��RTCCLK��1HZ��
        2����������ڣ�PC13
        3���������ã�
        3���������ã�
                    - ����ΪUSART1��TX��PA9  RX��PA10��:
                    - ����λ��8
                    - ֹͣλ��1
                    - ��żУ�飺��
                    - �����ʣ� 115200 
    ʹ�÷�����
        1���������¼�������壬�ϵ�󣬴���ÿ��5s���ӡ����ʱ��
                
4��ע������
    ��


1. Function description

    1. Trigger interrupt by setting wake up time
    2. Configure IO output by wake up flag bit

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

        1. periodic wake up clock source: RTCCLK (1HZ)
        2. Wakeup IO output: PC13
        3. Serial port configuration:

                            - Serial port: USART1 (TX: PA9 RX: PA10) :
                            - Data bit: 8
                            - Stop bit: 1
                            - Parity check: None
                            - Baud rate: 115200

    Instructions:
        1. After compilation, it is burned to the evaluation board. After power-on, the serial port will print wakeup time every 5s

4. Matters needing attention
    None