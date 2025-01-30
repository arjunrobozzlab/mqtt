1������˵��
    1��WWDG��λ���ܡ�


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
        1��WWDGʱ��Դ��PCLK1
        2��ϵͳʱ��Ƶ�ʣ�
            N32H473/474ϵ�У�
            200MHz�� PCLK1 = 100MHz 
            N32H475/482/487ϵ�У�
            240MHz,  PCLK1 = 120MHz 
        3��ָʾ�ƣ�PA3(LED1)   PA8(LED3)
             
    ���Բ���������
        1����KEIL�±������¼�������壬�ϵ��ָʾ��LED3��ͣ����˸��˵������ֵˢ�������������������С�
        2������Delay()���������ĳ�С�ڻ��ߴ��ڴ���ֵʱ������ϵͳ��һֱ���ڸ�λ״̬��LED1����


4��ע������
    1��������ֵ��Сʱ��ϵͳ����Ƶ���ĸ�λ״̬����ʱ��������������޷��������ء����������ڿ���WWDGǰ����1����ʱ������������󡣵�ȻҲ���Բ�����ʱ��ֱ�ӽ�BOOT0�������߼����������ء� 



1. Function description

    WWDG reset function.
    

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
       1. IWDG clock source: PCLK1
       2��system clock��
            N32H473/474 series��
            200MHz�� PCLK1 = 100MHz 
            N32H475/482/487 series����
            240MHz,  PCLK1 = 120MHz 
       3. light Indicator: PA3(LED1)   PA8(LED2)

    Test steps and phenomenon��
       1. Compile and download the code to reset and run, the indicator LED3 keeps flashing.
          It means that the window value is refreshed normally and the code is running normally.
       2. When the parameter of the Delay() function is changed less than or greater than window value, 
          the entire system will always be in the reset state. LED1 is on.

4. Matters needing attention
    1. When the window value is very small, the system is in a frequent reset state, and at this time, it is easy to 
       cause the program to fail to download normally. In this routine, 1s delay is added before WWDG is 
       turned on to avoid this phenomenon. Of course, without delay, you can directly pull up the BOOT0 pin to download normally.