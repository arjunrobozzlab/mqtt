1������˵��

    �������ṩ��һ��DMA MemtoMemģʽ�÷���������FLASH��RAM֮�䴫�����ݡ�

2��ʹ�û���

    �������������
        IDE���ߣ�KEIL MDK-ARM 5.34
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
        ����ȫ���ܰ�N32H487ZEL7_EVB V1.0����


3��ʹ��˵��

    1��ʱ��Դ��HSE+PLL
    2��ʱ��Ƶ�ʣ�
        N32H473/474ϵ�У�200MHz
        N32H475/482/487ϵ�У�240MHz
    3��DMAͨ����DMA1_CH1
    4��LED1��PA3
    5�����Բ���������
        a���������ش��븴λ����
        b��DMA������ɣ�LED1��˸

4��ע������
    ��


1. Function Description

    This routine provides a DMA MemtoMem mode usage for transferring data between FLASH and RAM.

2. Usage Environment

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
        Developed based on the full-featured board N32H487ZEL7_EVB V1.0


3. Use instructions

    1. Clock source: HSI+PLL
    2. Clock frequency:
        N32H473/474 series: 200MHz
        N32H475/482/487 series: 240MHz
    3. DMA channel: DMA1_CH1
    4. LED1: PA3
    5. Test steps and phenomena
        a, Compile and download the code reset run
        b, DMA transmission is completed, LED1 blinking

4. Matters needing attention
    None


