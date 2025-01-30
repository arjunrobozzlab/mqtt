1������˵��
    1��ADC1�����������������½��в�����ת��PB11,PB1���ŵ�ģ���ѹ
    2������ADC1ת�����ͨ��DMA1_CH1ͨ����ȡ������ADCConvertedValue[10]
2��ʹ�û���
    �������������  
        IDE����:  KEIL MDK-ARM V5.34.0.0
                  IAR EWARM 8.50.1
    Ӳ��������      
        N32H473ϵ�У�
        ����������N32H473VEL7_STB V1.0����
        N32H474ϵ�У�
        ����������N32H474VEL7_STB V1.0����
        N32H475ϵ�У�
        ����������N32H475UEQ7_STB V1.0����
        N32H482ϵ�У�
        ����������N32H482ZEL7_STB V1.0����
        N32H487ϵ�У�
        ����������N32H487ZEL7_STB V1.0����

3��ʹ��˵��
    ϵͳ���ã�
        1��ʱ��Դ�� HSI+PLL
        2��ϵͳʱ��Ƶ�ʣ�
            N32H473/474ϵ�У�
            200MHz
            N32H475/482/487ϵ�У�
            240MHz
        3���˿����ã�
            PB11ѡ��Ϊģ�⹦��
            PB1ѡ��Ϊģ�⹦��
        4��DMA��
            DMA1_CH1ͨ���ػ�ģʽ����һ�����ֵ�ADC1ת�������ADCConvertedValue[10]����
        5��ADC��
        ADC1��������ģʽ������ת����ɨ��ģʽ�����������12λ�����Ҷ��룬ת��PB11,PB1��ģ���ѹ���� ,������ϵ��x2 ������,�ڹ���ͨ����ʹ�ù���������ģʽ.
    ʹ�÷�����
        1�������򿪵���ģʽ��������ADCConvertedValue[10]��ӵ�watch���ڹ۲�
        2��ͨ���ı�PB11,PB1���ŵĵ�ѹVoltage�����Կ���ת���������ͬ���ı䣬���ݼĴ����Ľ��Result = Voltage * 2* 4095/3.3. 
4��ע������
    ��ϵͳ����HSEʱ��ʱ��һ��HSIҲ�Ǵ򿪵ģ���RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)��������ΪHSE����HSI
    ��ϵͳ����HSIʱ��ʱ��һ��HSE�ǹرյģ���RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)ֻ������ΪHSI

1. Function description
    1. ADC1 performs sampling with gain compensation and offset compensation enabled ,converts the analog voltage of the PB11,PB1 pin
    2. The ADC1 conversion result is read to the variable ADCConvertedValue through the DMA1_CH1 channel
2. Use environment
    Software development environment: 
        IDE TOOLS:  KEIL MDK-ARM V5.34.0.0
                    IAR EWARM 8.50.1
    Hardware development environment:
        N32H473 series:
        Developed based on the evaluation board N32H473VEL7_STB V1.0
        N32H474 series:
        Developed based on the evaluation board N32H474VEL7_STB V1.0
        N32H475 series:
        Developed based on the evaluation board N32H475UEQ7_STB V1.0
        N32H482 series:
        Developed based on the evaluation board N32H482ZEL7_STB V1.0
        N32H487 series:
        Developed based on the evaluation board N32H487ZEL7_STB V1.0

3. Instructions for use
    System Configuration; 
        1. Clock source: HSI+PLL
        2. System Clock frequency: 
            N32H473/474 series:
            200MHz
            N32H475/482/487 series:
            240MHz
        3. Port configuration:
            PB11 selected as analog function
            PB1 selected as analog function
        4. DMA:
            DMA1_CH1 channel loopback mode transfers a halfword of ADC1 conversion result to ADCConvertedValue[10] variable
        5. ADC:
            ADC1 independent working mode, continuous conversion, scan mode, software trigger, 12-bit data is right-aligned,
            conversion the analog voltage data of PB11 PB1,The oversampling factor x2 , no right shift and the oversampling continuous mode on the regular channel .
    Instructions:
        1. After compiling, open the debug mode and add the variable ADCConvertedValue[10] to the watch window to observe
        2. By changing the voltage (Voltage) of the PB11,PB1 pin, you can see that the conversion result variable changes synchronously . the data register result = Voltage * 2 * 4095/3.3.
4. Matters needing attention
    When the system uses HSE clock (generally HSI is also turned on), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8) can be configured as HSE or HSI
    When the system uses HSI clock (generally HSE is turned off), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8) can only be configured as HSI