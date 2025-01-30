1������˵��
    1��ADC1�������PA1���Զ�ע�����PB1���ŵ�ģ���ѹ����GTIM1 CC4�¼��´�������
    2�����й���ת�����ͨ��DMA1_CH1ͨ����ȡ������ADC_RegularConvertedValueTab[32]����
       ע��ת�����ͨ��ת�������ж϶�ȡ������ADC_InjectedConvertedValueTab[32]����
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
        3���жϣ�
            ADC1ע��ת���������жϴ򿪣��������ȼ�0�������ȼ�0
            �жϺ����н�ע������ȡ��ADC_InjectedConvertedValueTab[32]���飬����תPC6��ƽ
        4���˿����ã�
            PA1ѡ��Ϊģ�⹦��
            PB1ѡ��Ϊģ�⹦��
            PC6ѡ��Ϊͨ��IO���
            PB11ѡ��ΪTIM1 CH4 PWM���
        5��DMA��
            DMA1_CH1ͨ���ػ�ģʽ����32�����ֵ�ADC1ת�������ADC_RegularConvertedValueTab[32]����
        6��ADC��
            ADC1��������ģʽ��GTIM1 CC4������12λ�����Ҷ��룬����ת��ͨ��PA1���Զ�ע��ת��ͨ��PB1��ģ���ѹ����
        7��GTIM1��
            GTIM1����CH4�����CH4��������ADCת��        
    ʹ�÷�����
        1�������򿪵���ģʽ��������ADC_RegularConvertedValueTab[32],ADC_InjectedConvertedValueTab[32]��ӵ�watch���ڹ۲�
        2��ͨ���ı�PA1 PB1���ŵĵ�ѹ����ÿ��CC4�¼�����ʱת��һ�ι����ע��ͨ�������������ڶ�Ӧ�����С�ͬʱ��PB11���Կ���GTIM1 CH4�� PWM ����
4��ע������
    ��ϵͳ����HSEʱ��ʱ��һ��HSIҲ�Ǵ򿪵ģ���RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8)��������ΪHSE����HSI
    ��ϵͳ����HSIʱ��ʱ��һ��HSE�ǹرյģ���RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)ֻ������ΪHSI


1. Function description
    1. ADC1 regularly samples PA1, automatically injects and samples the analog voltage of the PB1 pin, and triggers sampling under the GTIM1 CC4 event
    2. The regular conversion result is read into the variable ADC_RegularConvertedValueTab[32] array through the DMA1_CH1 channel
       The injected conversion result is read into the variable ADC_InjectedConvertedValueTab[32] array through the conversion end interrupt
       
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
        3. Interrupt:
            ADC1 injects the conversion result to complete the interrupt open, steals priority 0, sub-priority 0
            In the interrupt function, the injection result is read into the ADC_InjectedConvertedValueTab[32] array, and the PC6 level is flipped
        4. Port configuration:
            PA1 is selected as the analog function
            PB1 is selected as the analog function
            PC6 is selected as general IO output
            PB11 is selected as TIM1 CH4 PWM output
        5. DMA:
            DMA1_CH1 channel loopback mode transfers ADC1 conversion result of 32 half words to ADC_RegularConvertedValueTab[32] array
        6. ADC:
            ADC1 independent working mode, GTIM1 CC4 trigger, 12-bit data right-aligned, regular conversion channel PA1, automatic injection of analog voltage data of conversion channel PB1.
        7. GTIM1:
            GTIM1 turns on CH4 output, CH4 is used to trigger ADC conversion
    Instructions:
        1. Open the debug mode after compiling, and add the variables ADC_RegularConvertedValueTab[32], ADC_InjectedConvertedValueTab[32] to the watch window for observation
        2. By changing the voltage of the PA1 and PB1 pins, the rules and injection channels are converted once every CC4 event occurs,
           and the variables are stored in the corresponding arrays. At the same time, you can see the PWM waveforms of GTIM1 CH4 in PB11
4. Matters needing attention
    When the system uses HSE clock (generally HSI is also turned on), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8) can be configured as HSE or HSI
    When the system uses HSI clock (generally HSE is turned off), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8) can only be configured as HSI