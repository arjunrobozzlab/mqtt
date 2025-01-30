1. ����˵��
    USB ���� MSC

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
    2. GPIO: KEY2--PA15��VBUS��������-PB3
    3. �������ã�
            - ����ΪUSART1��TX��PA9  RX��PA10��:
            - ����λ��8
            - ֹͣλ��1
            - ��żУ�飺��
            - �����ʣ� 115200 

    ����Demo�Ĳ��Բ�������� 
    1. ��������س���λ���У�
    2. �򿪴��ڵ������֣����ò�����Ϊ115200bps
    3. ����OTGת���ߣ��ٽ���U�̣��ȴ�ö�����
    4. ö����ɺ󣬰���KEY2��������ʼ��U�̽����ļ���д����

4. ע������
    ��

1. Function description
    USB host MSC

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
    2. GPIO: KEY2--PA15��VBUS driver pin(PB3)
    3. Serial port configuration:
            - Serial port: USART1 (TX: PA9 RX: PA10) :
            - Data bit: 8
            - Stop bit: 1
            - Parity check: None
            - Baud rate: 115200
    
    Describe the testing steps and phenomena of the Demo
    1. Compile the program and download it for reset and execution.
    2. Open the serial port debugging Assistant and set the baud rate to 115200bps.
    3. Connect the OTG adapter, followed by USB flash disk, and wait for enumeration to complete.
    4. After enumeration is complete, press the KEY2 button to start read and write files on the USB flash disk.
    
4. Matters needing attention
    None