1������˵��
    1��ADC1������ת��PB1���ŵ�ģ���ѹ��ʹ��ADC FIFOģʽ��
    2������ADC1ת�����ͨ��DMA1_CH1ͨ����ȡ������ADCConvertedValue[60]
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
            PB1ѡ��Ϊģ�⹦��
        4��DMA��
            ͻ������ = 6, ����ģʽ, ʹ��DMAͻ���� DMA1_CH1ͨ���ػ�ģʽ����8�����ֵ�ADC1ת�������ADCConvertedValue[60]����
        5��ADC��
            ADC1��������ģʽ������ת������ͨ��ģʽ�����������12λ�����Ҷ��룬FIFO����Ϊ6,ת���������PB1��ģ���ѹ����.
    ʹ�÷�����
        1�������򿪵���ģʽ��������ADCConvertedValue[60]��ӵ�watch���ڹ۲�
        2������ģʽ�£�����ģʽ�£�ÿ�������6�Σ�ADCConvertedValue[60]�л�����6��PB1������ת���ĵ�ѹֵ. 
4��ע������
    1.��ϵͳ����HSEʱ��ʱ��һ��HSIҲ�Ǵ򿪵ģ���RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)��������ΪHSE����HSI
    2.��ϵͳ����HSIʱ��ʱ��һ��HSE�ǹرյģ���RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)ֻ������ΪHSI
    3.��Ҫ�����Դ��ڵ�ADC�������������ADCx->DAT�Ĵ�����ӵ�watch���ڣ������ַ�ʽ���ᶨ�ڶ�ȡADC�����ݣ�Ӱ��ADC_FIFO�Ĺ��ܲ���

1. Function description
    1. ADC1 samples ,converts the analog voltage of the PB1 pin (using ADC FIFO mode)
    2. The ADC1 conversion result is read to the variable ADCConvertedValue[60] through the DMA1_CH1 channel
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
            PB1 selected as analog function 
        4. DMA:
            burstlen = 6, Normal mode, Enable DMA_BURST. DMA1_CH1 channel loopback mode to transfer 8 half-word ADC1 conversion results to the ADCConvertedValue[60] variable
        5. ADC:
            ADC1 independent working mode, one-shot conversion, single-channel mode, software trigger, 12-bit data is right-aligned, FIFO length is 6 .
            conversion result is the analog voltage data of PB1.
    Instructions:
        1. After compiling, open the debug mode and add the variable ADCConvertedValue[60] to the watch window to observe
        2. In debug mode, when the software is triggered 6 times in single step mode, 6 converted voltage values from the PB1 pin will be added to ADCConvertedValue[60]..
4. Matters needing attention
    1.When the system uses HSE clock (generally HSI is also turned on), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8) can be configured as HSE or HSI
    2.When the system uses HSI clock (generally HSE is turned off), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8) can only be configured as HSI
    3.Do not call out the ADC peripheral of the debug window or add the ADCx->DAT register to the watch window. Both of these methods will regularly read the ADC data, affecting the functional testing of ADC_FIFO.