1. ����˵��
    USB MSC + CDC ����豸

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
         3. SPI1���ã�NSS--PA4��SCK--PA5��MISO--PA6��MOSI--PA7 (����W25Q128)
         4. GPIO��USART1��TX--PA9��RX--PA10�������� 115200
         5. ���⴮�ڣ�
            - �����ʣ�115200
            - ����λ��8
            - ֹͣλ��1
            - ��żУ�飺��
            - �����ʣ� 115200 

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ͨ�� USB ������ J4 USB �ڣ�����ʶ������ں�U���豸;
         3. �ڵ����豸�����п��Կ��������Ĵ��ڣ��� USART1 �ӵ����ڹ����ϣ��� USB ���⴮�ڣ�
            USB ���⴮�ڷ������ݣ��ô��ڹ��߽������ݣ�Ȼ���ô��ڹ��߷������ݣ� USB ���⴮�ڽ������ݡ�

4. ע������
    �״ι��� U ����Ҫ��ʽ������ʽ����ɺ󼴿ɵ��� U ��ʹ�á���N32H487ZEL7_EVB V1.0�������ϣ�J29��J31������ñ����

1. Function description
    USB MSC + CDC composite device

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
        3. SPI1 configuration: NSS--PA4, SCK--PA5, MISO--PA6, MOSI--PA7 (connected to W25Q128)
        4. GPIO: USART1 (TX--PA9, RX--PA10) baud rate 115200
        5. Virtual serial port��
            - Baud rate: 115200
            - Data bits: 8
            - Stop position: 1
            - Parity check: none
            - Baud rate: 115200
    
    Describe the testing steps and phenomena of the Demo

        1. Download the program after compiling and reset it to run;
        2. Connect the J4 USB port via a USB cable, and the computer recognizes the HID device and U disk.
        3. The new serial port can be seen in the computer device management, connect USART1 to the serial port tool, open the USB virtual serial port;
           The USB virtual serial port sends data, the serial port tool receives data, and the serial port tool sends data, and the USB virtual serial port receives data.
 
4. Matters needing attention
    The first mount U disk needs to be formatted, and it can be used as a U disk after formatting. On N32H487ZEL7_EVB V1.0 board, J29 and J31 Connected with jumper cap