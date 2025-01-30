1. ����˵��
    USB ˫��ɫ MSC

2. ʹ�û���

    /* ���������������ǰ����ʹ�õ�����������Ƽ��汾�� */
    IDE���ߣ�KEIL MDK-ARM 5.34
      
    /* Ӳ�����������̶�Ӧ�Ŀ���Ӳ��ƽ̨ */
    N32H482ϵ�У�
    ����������N32H482ZEL7_STB V1.0����
    N32H487ϵ�У�
    ����������N32H487ZEL7_STB V1.0����


3. ʹ��˵��
    �������ģ�����÷���������:ʱ�ӣ�I/O�� 
    1. SystemClock��240MHz
    2. GPIO: ��-KEY1��PC13������-KEY2��PA15����ȷ��-WAKEUP��PA0����VBUS��������-PB3��
    3. SPI1���ã�NSS--PA4��SCK--PA5��MISO--PA6��MOSI--PA7 (����W25Q128)
    4. �������ã�
            - ����ΪUSART1��TX��PA9  RX��PA10��:
            - ����λ��8
            - ֹͣλ��1
            - ��żУ�飺��
            - �����ʣ� 115200 

    ����Demo�Ĳ��Բ�������� 
    1. ��������س���λ���У�
    2. �򿪴��ڵ������֣����ò�����Ϊ115200bps
    3. ���ݴ�ӡʹ�ð���KEY1,KEY2,WAKEUP��ѡ��ǰUSB��ɫ������ģʽ���豸ģʽ��
    4. �����ѡ���豸��ͨ�� USB ������ J62 USB �ڣ�USB ������ɺ�ʶ��� U ���豸
    5. ���ѡ��������ͨ��J62����OTGת���ߣ��ٽ���U�̣��ȴ�ö����ɣ����ݴ�ӡ��дU��

4. ע������
    ��

1. Function description
    USB Dual role MSC

2. Use environment
     /* Software development environment: the name and version number of the software tool used in the current project */
     IDE tool: KEIL MDK-ARM 5.34
      
     /* Hardware environment: development hardware platform corresponding to the project */
    N32H482 series:
    Developed based on the evaluation board N32H482ZEL7_STB V1.0
    N32H487 series:
    Developed based on the evaluation board N32H487ZEL7_STB V1.0

3. Instructions for use
    Describe the configuration method of related modules; for example: clock, I/O, etc. 
    1. SystemClock: 240MHz
    2. GPIO: UP-KEY1��PC13����DOWN-KEY2��PA15����SEL-WAKEUP��PA0����VBUS driver pin(PB3)��
    3. SPI1��NSS--PA4��SCK--PA5��MISO--PA6��MOSI--PA7 (connect W25Q128)
    4. Serial port configuration:
            - Serial port: USART1 (TX: PA9 RX: PA10) :
            - Data bit: 8
            - Stop bit: 1
            - Parity check: None
            - Baud rate: 115200
    
    Describe the testing steps and phenomena of the Demo
    1. Compile the program and download it for reset and execution.
    2. Open the serial port debugging Assistant and set the baud rate to 115200bps.
    3. Use KEY1,KEY2,WAKEUP to select the current USB role (host mode or device mode) according to the print.
    4. If device mode is selected, connect it to the J62 USB port using a USB cable. After the USB is mounted, the device is identified as a USB flash drive.
    5. If host mode is selected, connect the OTG conversion cable through J62, and then connect the USB flash drive. 
       Wait for the enumeration to complete, and read and write the USB flash drive according to the print
    
4. Matters needing attention
    None.