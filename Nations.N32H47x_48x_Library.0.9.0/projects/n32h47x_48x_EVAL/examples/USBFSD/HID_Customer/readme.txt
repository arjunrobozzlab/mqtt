1. ����˵��
    USB HID �豸

2. ʹ�û���

    �������������KEIL MDK-ARM V5.34
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


3. ʹ��˵��
    �������ģ�����÷���������:ʱ�ӣ�I/O�� 
         1. SystemClock��192MHz(N32H473��N32H474ϵ��)��240MHz(N32H482��N32H487ϵ��)
         2. USBClock: 48MHz
         3. GPIO:KEY2 -- PA15
                 LED1 -- PA3
                 LED2 -- PB4
                 LED3 -- PA8

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ͨ�� USB ������ J4 USB �ڣ�����ʶ���HID�豸;
         3. �������KEY2�� HID�豸��ͨ��IN�˵㷢��������Ϣ
         4. ��PC��ͨ��OUT�˵����豸�������ݿ��Կ���LED1~LED3��״̬
            ���� 0x01 0x00 LED1��
            ���� 0x01 0x01 LED1����
            ���� 0x02 0x00 LED2��
            ���� 0x02 0x01 LED2����
            ���� 0x03 0x00 LED3��
            ���� 0x03 0x01 LED3����

4. ע������
    ��

1. Function description
    USB HID device

2. Use environment

    Software development environment: KEIL MDK-ARM V5.34
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

3. Instructions for use
    Describe the configuration method of related modules; for example: clock, I/O, etc. 
        1. SystemClock: 192MHz(N32H473 and N32H474 series)��240MHz(N32H482 and N32H487 series)
        2. USBClock: 48MHz
        3. GPIO��KEY2 -- PA15
                 LED1 -- PA3
                 LED2 -- PB4
                 LED3 -- PA8
    
    Describe the testing steps and phenomena of the Demo

        1. Download the program after compiling and reset it to run;
        2. Connect the J4 USB port via a USB cable, and the computer recognizes the HID device.
        3. When click the button KEY2, the HID device will send a key message through the IN endpoint.
        4. Control the status of LED1 to LED3 by sending data to the device through the OUT endpoint on the PC
           Send 0x01 0x00 LED1 Off
           Send 0x01 0x01 LED1 Light
           Send 0x02 0x00 LED2 off
           Send 0x02 0x01 LED2 Light
           Send 0x03 0x00 LED3 off
           Send 0x03 0x01 LED3 to light up
 
4. Matters needing attention
    None.