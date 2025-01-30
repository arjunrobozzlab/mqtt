1������˵��

    �������ṩ��һ��DMA�÷���������������RAM֮�䴫�����ݡ�

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
    3��DMAͨ����DMA1_CH2��DMA1_CH4
    4��I2C1 ���ã�
        SCL   -->  PB6
        SDA   -->  PB7
        ADDR��0x30(7bit)
        CLOCK��100K
    5��I2C2 ���ã�
        SCL   -->  PB10
        SDA   -->  PB11
        ADDR��0xA0(7bit)
        CLOCK��100K
    6��LED1��PA3
    7�����Բ���������
        a������PB6��PB10������PB7��PB11
        b���������ش��븴λ����
        c��DMA������ɣ�LED1��˸

4��ע������
    ��SDA��SCL����Ҫ���������衣


1. Function Description

    This routine provides a DMA usage for transferring data between a peripheral and RAM.

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
    3. DMA channel: DMA1_CH2, DMA1_CH4
    4. I2C1 Configuration:
        SCL --> PB6
        SDA --> PB7
        ADDR: 0x30(7bit)
        CLOCK: 100K
    5. I2C2 Configuration:
        SCL --> PB10
        SDA --> PB11
        ADDR: 0xA0(7bit)
        CLOCK: 100K
    6. LED1: PA3
    7. Test steps and phenomena
        a, Connect PB6 to PB10, connect PB7 to PB11
        b, Compile and download the code reset run
        c, DMA transmission is completed, LED1 flashes.

4. Matters needing attention
    Pull resistors are required on SDA, SCL.
