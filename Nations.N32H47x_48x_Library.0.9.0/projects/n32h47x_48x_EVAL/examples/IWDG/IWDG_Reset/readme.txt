1������˵��
    IWDG��λ���ܡ�


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

    ϵͳ���ã�
        1��IWDGʱ��Դ��LSI/128
        2����ʱʱ��ֵ��250ms
        3��ָʾ�ƣ�LED1(PA4) LED2(PA5)
            

    ���Բ��輰����
        1���������¼�������壬�ϵ��ָʾ��LED2��ͣ����˸��˵��IWDG����ι���������������С�
        2����SysTick_Delay_Ms(249)���������ĳ�251���ϣ�����ϵͳ��һֱ���ڸ�λ״̬��LED1����


4��ע������
    ��

1. Function description

    IWDG reset function.
    

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

    System Configuration:
       1. IWDG clock source: LSI/128
       2. Timeout value: 250ms
       3. light Indicator: LED1(PA4) LED2(PA5)

    Test steps and phenomenon��
       1. Compile and download the code to reset and run.The indicator LED2 
          keeps flashing. It means that IWDG feeds the dog normally and the code runs normally.
       2. Change the parameter of the SysTick_Delay_Ms() function from 249 to 251 or more, the whole system
          will always be in the reset state, and LED1 will be on.

4. Matters needing attention
    None