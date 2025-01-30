1. ����˵��
    USB CDC + HID ����豸

2. ʹ�û���

    �������������KEIL MDK-ARM 5.34
                  IAR EWARM 8.50.1

    Ӳ������������
        N32H482ϵ�У�
        ����������N32H482ZEL7_STB V1.0����
        N32H487ϵ�У�
        ����������N32H487ZEL7_STB V1.0����


3. ʹ��˵��
    �������ģ�����÷���������:ʱ�ӣ�I/O�� 
         1. SystemClock��240MHz
         2. ���ڣ�USART1 TX -- PA9  RX -- PA10 �����ʣ�115200
		 3. GPIO��KEY2 -- PA15
                  LED1 -- PA3
                  LED2 -- PB4
                  LED3 -- PA8


    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ͨ�� USB ������ J62 USB �ڣ�����ʶ������⴮���豸��HID�豸
         3. �� USART1 �ӵ����ڹ����ϣ�Ȼ����PC�ϴ� USB ���⴮�ڣ�USB ���⴮�ڷ������ݣ�
            �ô��ڹ��߽������ݣ�Ȼ���ô��ڹ��߷������ݣ� USB ���⴮�ڽ�������
		 4. �������KEY2�� HID�豸��ͨ��IN�˵㷢��������Ϣ
         5. ��PC��ͨ��OUT�˵����豸�������ݿ��Կ���LED1~LED3��״̬
            ���� 0x01 0x00 LED1��
            ���� 0x01 0x01 LED1����
            ���� 0x02 0x00 LED2��
            ���� 0x02 0x01 LED2����
            ���� 0x03 0x00 LED3��
            ���� 0x03 0x01 LED3����


4. ע������
    ��

1. Function description
    USB CDC + HID composite device

2. Use environment
    Software development environment: KEIL MDK-ARM V5.34
                                      IAR EWARM 8.50.1

    Hardware development environment:
        N32H482 series:
        Developed based on the evaluation board N32H482ZEL7_STB V1.0
        N32H487 series:
        Developed based on the evaluation board N32H487ZEL7_STB V1.0

3. Instructions for use
    Describe the configuration method of related modules; for example: clock, I/O, etc. 
        1. SystemClock: 240MHz
        2. Serial port: USART1 TX -- PA9 RX -- PA10 Baud rate: 115200
		3. GPIO��KEY2 -- PA15
                 LED1 -- PA3
                 LED2 -- PB4
                 LED3 -- PA8

    Describe the testing steps and phenomena of the Demo
    1. After compiling, the downloaded program is reset and run;
    2. Connect a USB cable to the J62 USB port. The computer identifies the virtual serial port device and HID device
    3. Connect USART1 to the serial port tool, then open the USB virtual serial port on the PC, and send data through the USB virtual serial port.
       Use the serial port tool to receive data, and then use the serial port tool to send data, USB virtual serial port to receive data
    4. When click the button KEY2, the HID device will send a key message through the IN endpoint.
	5. Control the status of LED1 to LED3 by sending data to the device through the OUT endpoint on the PC
           Send 0x01 0x00 LED1 Off
           Send 0x01 0x01 LED1 Light
           Send 0x02 0x00 LED2 off
           Send 0x02 0x01 LED2 Light
           Send 0x03 0x00 LED3 off
           Send 0x03 0x01 LED3 to light up
        
4. Matters needing attention
    None.