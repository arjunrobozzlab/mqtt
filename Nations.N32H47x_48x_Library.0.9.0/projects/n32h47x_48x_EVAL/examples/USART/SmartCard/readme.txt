1������˵��

    �ò�����ʾ��USART2�����ܿ������ͨ�ţ���ѯ���ܿ������


2��ʹ�û���

    �������������KEIL MDK-ARM V5.34.0.0
                  IAR EWARM 8.50.1
    
    Ӳ������������    
        N32H473ϵ�У�
        ����������N32H473VEL7_STB V1.0����
        N32H474ϵ�У�
        ����������N32H474VEL7_STB V1.0����
        N32H482ϵ�У�
        ����������N32H482ZEL7_STB V1.0����
        N32H487ϵ�У�
        ����������N32H487ZEL7_EVB V1.0����
    ���ܿ������ܿ���


3��ʹ��˵��
    
    ϵͳʱ���������£�
    - ʱ��Դ = HSE + PLL
    - ϵͳʱ��
        N32H482/N32H487:
            SystemClock��240MHz
            ���ܿ�����ʱ�� = 3MHz
        N32H474/N32H473:
            SystemClock��200MHz
            ���ܿ�����ʱ�� = 2.5MHz
    
    USART2�������£�
    - ������ =  (�������õ����ܿ�����ʱ������)
    - �ֳ� = 8����λ
    - 1.5ֹͣλ
    - У����� even
    - Ӳ�������ƽ��ã�RTS��CTS�źţ�
    - �������ͷ�����ʹ��
    
    USART2�����������£�

    N32H475��
    - USART2_Tx.PB3    <-------> SMART_CARD I/O
    - USART2_CLK.PB5   <-------> SMART_CARD CLK
    - SC_PIN_RESET.PB7 <-------> SMART_CARD RST
    - 3V3              <-------> SMART_CARD Vcc
    - GND              <-------> SMART_CARD GND
    N32H473/N32H474/N32H482/N32H487��
    - USART2_Tx.PF11    <-------> SMART_CARD I/O
    - USART2_CLK.PC12   <-------> SMART_CARD CLK
    - SC_PIN_RESET.PB3  <-------> SMART_CARD RST
    - 3V3               <-------> SMART_CARD Vcc
    - GND               <-------> SMART_CARD GND
    
    ��ӡ��ϢUSART1�������£�
    - ������ = 115200 baud
    - �ֳ� = 8����λ
    - 1ֹͣλ
    - У����ƽ���
    - Ӳ�������ƽ��ã�RTS��CTS�źţ�
    - �������ͷ�����ʹ��    
    - TX - PA9
    
    ���Բ���������
    - Demo��KEIL�����±����������MCU
    - ��λ���У��鿴���ڴ�ӡ��Ϣ


4��ע������
��

1. Function description

The test example demonstrates the basic communication between USART2 and smart card to query the random number of smart card


2. Use environment

    Software development environment: KEIL MDK-ARM V5.34.0.0
                                      IAR EWARM 8.50.1
    Hardware development environment:
        N32H473 series:
        Developed based on the evaluation board N32H473VEL7_STB V1.0
        N32H474 series:
        Developed based on the evaluation board N32H474VEL7_STB V1.0
        N32H482 series:
        Developed based on the evaluation board N32H482ZEL7_STB V1.0
        N32H487 series:
        Developed based on the evaluation board N32H487ZEL7_EVB V1.0
    Smart Card, Smart Card Holder


3. Instructions for use

The system clock configuration is as follows:
    System Clock Configuration:
        N32H475/N32H482/N32H487:
            SystemClock��240MHz
            Smartcard clock = 3MHz
        N32H474/N32H473:
            SystemClock��200MHz
            Smartcard clock = 2.5MHz

USART2 configuration is as follows:
- Baud rate = (based on the set smart card working clock)
- Word length = 8 data bits
- 1.5 Stop bit
- Check control even
- Hardware flow control disabled (RTS and CTS signals)
- Enable receiver and transmitter

The USART pins are connected as follows:

    N32H475��
    - USART2_Tx.PB3    <-------> SMART_CARD I/O
    - USART2_CLK.PB5   <-------> SMART_CARD CLK
    - SC_PIN_RESET.PB7 <-------> SMART_CARD RST
    - 3V3              <-------> SMART_CARD Vcc
    - GND              <-------> SMART_CARD GND
    N32H473/N32H474/N32H482/N32H487��
    - USART2_Tx.PF11    <-------> SMART_CARD I/O
    - USART2_CLK.PC12   <-------> SMART_CARD CLK
    - SC_PIN_RESET.PB3  <-------> SMART_CARD RST
    - 3V3               <-------> SMART_CARD Vcc
    - GND               <-------> SMART_CARD GND

USART1 is configured as follows:
- baud rate = 115200 baud
- Word length = 8 data bits
-1 Stop bit
- Check control is disabled
- Hardware flow control disabled (RTS and CTS signals)
- Enable receiver and transmitter
- TX - PA9

Test procedure and phenomenon:
- Demo is compiled in KEIL environment and downloaded to MCU
- Reset and run. View the serial port information


4. Precautions
None
