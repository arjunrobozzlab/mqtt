1������˵��

    �������ṩ��һ��DMA�÷������������赽RAM֮�䴫�����ݡ�
    
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
    2����ʱ�ӣ�200MHz
    3��DMAͨ����DMA1_CH2��DMA1_CH3��DMA1_CH4��DMA1_CH5
    4����SPI ���ã�
        ���裺
            N32H475ϵ�У�SPI3
            ����ϵ�У�SPI1
        Ӳ�����ӣ�
            N32H475ϵ�У�SCK   -->  PD9��MISO  -->  PD11��MOSI  -->  PD6
            ����ϵ�У�SCK   -->  PA5��MISO  -->  PA6��MOSI  -->  PA7
        ȫ˫��
        ��ģʽ
        8bit����
        ���ԣ���ʼΪ��/�ڶ�������
        ���Ƭѡ
        �����ǰMSB
    
    5����SPI ���ã�
        ���裺
            SPI2
        Ӳ�����ӣ�
            N32H475ϵ�У�SCK   -->  PC7��MISO  -->  PC2��MOSI  -->  PC3
            ����ϵ�У�SCK   -->  PC7��MISO  -->  PC8��MOSI  -->  PC9
        ȫ˫��
        ��ģʽ
        8bit����
        ���ԣ���ʼΪ��/�ڶ�������
        ���Ƭѡ
        �����ǰMSB

    6�����Բ���������
        a���öŰ��߷ֱ���SPI��SCK/MISO/MOSI���ӵ���SPI��SCK/MISO/MOSI
        b���������ش��븴λ����
        c��DMA������ɣ�LED PA3 PA8��˸
        
4��ע������
    ��


1. Function Description

    This routine provides a DMA usage for transferring data from peripheral to RAM.  

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
    3. DMA channel: DMA1_CH2, DMA1_CH3, DMA1_CH4, DMA1_CH5
    4. Master SPI Configuration:
        Peripheral:
            N32H475 series: SPI3
            Other series: SPI1
        Hardware Connections:
            N32H475 series: SCK --> PD9, MISO --> PD11, MOSI --> PD6
            Other series: SCK --> PA5, MISO --> PA6, MOSI --> PA7
        Full duplex
        Master Mode
        8bit transmission
        Polarity: start low/second edge
        Software chip select
        Big end in front MSB
    5. Slave SPI Configuration:
        Peripheral:
            SPI2
        Hardware Connections:
            N32H475 series: SCK --> PC7, MISO --> PC2, MOSI --> PC3
            Other series: SCK --> PC7, MISO --> PC8, MOSI --> PC9
        Full duplex
        Slave Mode
        8bit transmission
        Polarity: start low/second edge
        Software chip select
        Big end in front MSB
    6. Test steps and phenomena
        a, Connect the SCK/MISO/MOSI of the master SPI to the SCK/MISO/MOSI of the slave SPI with DuPont cables, respectively
        b, Compile and download the code to reset and run
        c, DMA transmission is completed, LED PA3 PA8 blinking

4. Matters needing attention
    None
