1. ����˵��
    USB Mouse�豸

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
         2. GPIO����KEY1��PC13������KEY2��PA15������KEY3��PC8������KEY4��PA0����

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ͨ�� USB ������ J3 USB �ڣ�����ʶ��������豸
         3. ���°���KEY1��KEY2��KEY3��KEY4���������������ƶ���

4. ע������
    ��

1. Function description
    USB Mouse device

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
        2. GPIO: left KEY1 (PA4), right KEY2 (PA5), up KEY3 (PA6), down KEY4 (PA0)
    
    Describe the testing steps and phenomena of the Demo

        1. Download the program after compiling and reset it to run;
        2. Connect the J3 USB port via a USB cable, and the computer recognizes the mouse device; 
        3. When press KEY1, KEY2, KEY3, KEY4, the mouse will move up, down, left and right.
        
4. Matters needing attention
    None.