1. ����˵��
    USBģ�⴮�ڻػ�����

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
         3. ���⴮�ڣ�
            - �����ʣ�115200
            - ����λ��8
            - ֹͣλ��1
            - ��żУ�飺��
            - �����ʣ� 115200 
         

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ͨ�� USB ������ J4 USB �ڣ�USB ������ɺ��ڵ����豸�����п��Կ��������Ĵ��ڣ��� USB ���⴮�ڣ�
            ʹ�ô��ڹ��߷������ݣ����ڹ��߻������յ��ոշ��͵����ݡ�

4. ע������
    ��

1. Function description
    USB virtual serial port loop back

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
        3. Virtual serial port��
            - Baud rate: 115200
            - Data bits: 8
            - Stop position: 1
            - Parity check: none
            - Baud rate: 115200
                  
    Describe the test steps and phenomena of Demo 
        1. After compiling, download the program to reset and run;
        2. Connect the J4 USB port via a USB cable. After the USB mount is complete, you can see the newly added serial port in the computer device management. 
            Open the USB virtual serial port, using the serial port tool to send data, the serial port tool will immediately receive the data just sent.
 
4. Matters needing attention
    None