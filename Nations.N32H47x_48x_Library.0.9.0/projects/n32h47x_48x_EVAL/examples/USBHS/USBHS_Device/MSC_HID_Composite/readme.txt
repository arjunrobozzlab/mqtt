1. ����˵��
    USB MSC + HID����豸

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
         2. SPI1���ã�NSS--PA4��SCK--PA5��MISO--PA6��MOSI--PA7 (����W25Q128)
         3. GPIO��KEY2 -- PA15
                  LED1 -- PA3
                  LED2 -- PB4
                  LED3 -- PA8

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ͨ�� USB ������ J62 USB �ڣ�USB ������ɺ�ʶ��� U ���豸��HID�豸
         3. �������KEY2�� HID�豸��ͨ��IN�˵㷢��������Ϣ
         4. ��PC��ͨ��OUT�˵����豸�������ݿ��Կ���LED1~LED3��״̬
            ���� 0x01 0x00 LED1��
            ���� 0x01 0x01 LED1����
            ���� 0x02 0x00 LED2��
            ���� 0x02 0x01 LED2����
            ���� 0x03 0x00 LED3��
            ���� 0x03 0x01 LED3����


4. ע������
    �״ι��� U ����Ҫ��ʽ������ʽ����ɺ󼴿ɵ��� U ��ʹ�á���N32H487ZEL7_EVB V1.0�������ϣ�J29��J31������ñ����

1. Function description
    USB MSC + HID composite device

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
        1. SystemClock��240MHz
        2. SPI1 configuration: NSS--PA4, SCK--PA5, MISO--PA6, MOSI--PA7 (connected to W25Q128)
        3. GPIO��KEY2 -- PA15
                 LED1 -- PA3
                 LED2 -- PB4
                 LED3 -- PA8
    
    Describe the testing steps and phenomena of the Demo

        1. Download the program after compiling and reset it to run;
        2. Connect the J62 USB port via a USB cable, and after the USB is mounted, it will be recognized as a U disk device and a HID device.
        3. When click the button KEY2, the HID device will send a key message through the IN endpoint.
        4. Control the status of LED1 to LED3 by sending data to the device through the OUT endpoint on the PC
           Send 0x01 0x00 LED1 Off
           Send 0x01 0x01 LED1 Light
           Send 0x02 0x00 LED2 off
           Send 0x02 0x01 LED2 Light
           Send 0x03 0x00 LED3 off
           Send 0x03 0x01 LED3 to light up
        
4. Matters needing attention
     The first mount U disk needs to be formatted, and it can be used as a U disk after formatting. On N32H487ZEL7_EVB V1.0 board, J29 and J31 Connected with jumper cap.