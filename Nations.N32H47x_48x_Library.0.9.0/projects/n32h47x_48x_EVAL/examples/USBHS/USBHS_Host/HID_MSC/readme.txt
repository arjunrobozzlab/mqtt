1. ����˵��
    USB ���� HID mouse & HID keyboard & MSC

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
    3. ����OTGת���ߣ��ٽ���������̻���U���豸���ȴ�ö�����
    4. ö����ɺ󣬰���KEY2��������ʼ������̻�U������ͨ�� 
    5. ���ڵ������ֽ����ӡ��Ӧ����������̼�ֵ��Ϣ��U�̶�д��Ϣ��

4. ע������
    ��

1. Function description
    USB host HID mouse & HID keyboard & MSC

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
    3. Connect the OTG adapter cable, then connect the mouse or keyboard or USB flash disk device, and wait for the enumeration to complete
    4. After the enumeration is complete, press KEY2 to start data communication with the mouse or keyboard or USB flash disk
    5. The interface of the serial debugging assistant displays the corresponding mouse coordinates or keyboard key values, or USB flash disk read and write information.    

4. Matters needing attention
    None