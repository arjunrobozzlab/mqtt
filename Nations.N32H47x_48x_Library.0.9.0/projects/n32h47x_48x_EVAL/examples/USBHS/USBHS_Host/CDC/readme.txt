1. ����˵��
    USB ���� CDC

2. ʹ�û���

    �������������KEIL MDK-ARM 5.34
                  IAR EWARM 8.50.1

    Ӳ������������
        N32H482ϵ�У�
        ����������N32H482ZEL7_STB V1.0����
        N32H487ϵ�У�
        ����������N32H487ZEL7_EVB V1.0����


3. ʹ��˵��
    �������ģ�����÷���������:ʱ�ӣ�I/O�� 
    1. SystemClock��240MHz
    2. GPIO: ��-KEY1��PC13������-KEY2��PA15������PC6�����ң�PC7����ȷ��-WAKEUP��PA0����KEY3��PC8����VBUS��������-PB3��
    3. �������ã�
            - ����ΪUSART1��TX��PA9  RX��PA10��:
            - ����λ��8
            - ֹͣλ��1
            - ��żУ�飺��
            - �����ʣ� 115200 

    ����Demo�Ĳ��Բ�������� 
    1. ��������س���λ���У�
    2. �򿪴��ڵ������֣����ò�����Ϊ115200bps
    3. ����OTGת���ߣ��ٽ���CDC�豸���ȴ�ö�����
    4. ö����ɺ󣬰���KEY3��������ʼ��CDC�豸����ͨ�� 
    5. ���ݴ�ӡ��Ϣ����KEY1��KEY2����ѡ���ͻ�������ݻ򴮿����ã�WAKEUP����ȷ��ѡ�

4. ע������
    ��

1. Function description
    USB host CDC

2. Use environment
    Software development environment: KEIL MDK-ARM V5.34
                                      IAR EWARM 8.50.1

    Hardware development environment:
        N32H482 series:
        Developed based on the evaluation board N32H482ZEL7_STB V1.0
        N32H487 series:
        Developed based on the evaluation board N32H487ZEL7_EVB V1.0

3. Instructions for use
    Describe the configuration method of related modules; for example: clock, I/O, etc. 
    1. SystemClock: 240MHz
    2. GPIO: UP-KEY1(PC13), DOWN-KEY2(PA15), LEFT(PC6), RIGHT(PC7), ENTER-WAKEUP(PA0)��KEY3(PC8)��VBUS driver pin(PB3).
    3. Serial port configuration:
            - Serial port: USART1 (TX: PA9 RX: PA10) :
            - Data bit: 8
            - Stop bit: 1
            - Parity check: None
            - Baud rate: 115200
    
    Describe the testing steps and phenomena of the Demo
    1. Compile the program and download it for reset and execution.	
    2. Open the serial port debugging Assistant and set the baud rate to 115200bps.
    3. Connect the OTG adapter, then connect the CDC device and wait for enumeration to complete.
    4. After enumeration is completed, press the KEY3 button to start data communication with the CDC device.
    5. Based on the printed information, pressing KEY1 and KEY2 can select send or receive data or configurate USART, and pressing the WAKEUP KEY confirms the selection.    

4. Matters needing attention
    None.