1. ����˵��
    USB HID �����豸

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
         3. GPIO��KEY1(PC13),KEY2(PA15),KEY3(PC8)��������
            ���̵ƿ��ƣ�D14(PA3),D6(PA8)�������

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ͨ�� USB ������ J4 USB �ڣ�����ʶ��������豸������KEY1,KEY2,KEY3������USB ���� "a","b","c"��
            ������һ�����̿���Capslock��Numlock�����Կ���D14��D6��Ӧ���̵�����

4. ע������
    ��

1. Function description
    USB HID keyboard device

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
        3. GPIO: KEY1(PC13),KEY2(PA15),KEY3(PC8)keyboard input 
           Keyboard light control: D14(PA3),D6(PA8)keyboard output
    
    Describe the testing steps and phenomena of the Demo

        1. Download the program after compiling and reset it to run;
        2. Connect the J4 USB port via a USB cable, and the computer recognizes the keyboard device. Press KEY1,KEY2,KEY3, and USB inputs "a", "b", and "c".
           Using another keyboard to toggle Capslock and Numlock, D14 and D6 output corresponding ON and OFF.
 
4. Matters needing attention
    None.