1. ����˵��
    USB ��Ƶ�������豸

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
         1. SystemClock��HSE_PLL 240MHz
         2. I2SClock:    SHRTPLL 241.664MHz(I2S ��ƵƵ��16KHz)
         3. WM8978: I2C SCL -- PB6
                        SDL -- PB7
                    I2S CK  -- PC7
                    I2S WS  -- PC6
                    I2S SD  -- PC2
                    I2S MCK -- PA8

    ����Demo�Ĳ��Բ�������� 
         1. ��������س���λ���У�
         2. ͨ�� USB ������J4 USB �ڣ�����ʶ�����Ƶ�豸���ö�������J21��
         3. ���Բ������֣�����������������

4. ע������
    ��

1. Function description
    USB Audio speaker device

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
        1. SystemClock��HSE_PLL 240MHz
        2. I2SClock: SHRTPLL 241.664(for I2S audio clock 16KHz)
        3. WM8978: I2C SCL -- PB6
                       SDL -- PB7
                   I2S CK  -- PC7
                   I2S WS  -- PC6
                   I2S SD  -- PC2
                   I2S MCK -- PA8
                  
    Describe the test steps and phenomena of Demo 
        1. After compiling, download the program to reset and run;
        2. Connect the USB port through the J4 USB cable, and the computer recognizes the Audio device, and connects to the J21 port with the headphone; 
        3. The computer plays music, and the headphones can hear the sound
 
4. Matters needing attention
    None