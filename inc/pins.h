// Define microcontroller type (assuming PIC24 family based on the configuration)

// I2C configuration (using default I2C1)

// LoRa E5 communication pins
#define TRIS_LoRa_E5_TX	                _TRISB14
#define PORT_LoRa_E5_TX 	                _RB14
#define LAT_LoRa_E5_TX 	                _LATB14
#define ODC_LoRa_E5_TX	                _ODB14
#define PIN_LoRa_E5_TX 	                _RB14
#define RPOUT_LoRa_E5_TX	                RPOR7bits.RP14R
#define RPIN_LoRa_E5_TX	                14
#define CN_LoRa_E5_TX		                12
#define ADC_value_LoRa_E5_TX              Buffer_entradas[10] 
#define HAL_SetAnalog_LoRa_E5_TX()        {_PCFG10=0;\
                                        adc_addAnalogChannel(10);}

#define TRIS_LoRa_E5_RX	                _TRISB12
#define PORT_LoRa_E5_RX 	                _RB12
#define LAT_LoRa_E5_RX 	                _LATB12
#define ODC_LoRa_E5_RX	                _ODB12
#define PIN_LoRa_E5_RX 	                _RB12
#define RPOUT_LoRa_E5_RX		            RPOR6bits.RP12R
#define RPIN_LoRa_E5_RX		            12
#define CN_LoRa_E5_RX		                14
#define ADC_value_LoRa_E5_RX              Buffer_entradas[12]
#define HAL_SetAnalog_LoRa_E5_RX()        {_PCFG12=0;\
                                        adc_addAnalogChannel(12);}


// GPS communication pins
//EMIC:setInput(DEV:_hal/pins/setPin.emic,pin=B4,name=GPS_TX)
//EMIC:setInput(DEV:_hal/pins/setPin.emic,pin=B5,name=GPS_RX)
//EMIC:setInput(DEV:_hal/pins/setPin.emic,pin=A4,name=GPS_POWER)

// Reset
#define TRIS_LoRa_RESET	                _TRISB11
#define PORT_LoRa_RESET 	                _RB11
#define LAT_LoRa_RESET 	                _LATB11
#define ODC_LoRa_RESET	                _ODB11
#define PIN_LoRa_RESET 	                _RB11
#define RPOUT_LoRa_RESET		            RPOR5bits.RP11R
#define RPIN_LoRa_RESET		            11
#define CN_LoRa_RESET		                15

// LEDs
#define TRIS_Led1	                _TRISA0
#define PORT_Led1 	                _A0
#define LAT_Led1 	                _LATA0
#define ODC_Led1	                _ODA0
#define PIN_Led1 	                _RA0
#define CN_Led1		                2
#define ADC_value_Led1              Buffer_entradas[0] 
#define HAL_SetAnalog_Led1()        {_PCFG0=0;\
                                        adc_addAnalogChannel(0);}


#define TRIS_Led2	_TRISA1
#define LAT_Led2 	_LATA1
#define ODC_Led2	_ODA1
#define PIN_Led2 	_RA1
#define CN_Led2		3
#define ADC_value_Led2              Buffer_entradas[1] 
#define HAL_SetAnalog_Led2()        {_PCFG1=0;\
                                        adc_addAnalogChannel(1);}

#define TRIS_Led3	_TRISA2
#define LAT_Led3 	_LATA2
#define ODC_Led3	_ODA2
#define PIN_Led3 	_RA2
#define CN_Led3		30

// Digital inputs
#define TRIS_DigIn1	                _TRISB7
#define PORT_DigIn1 	                _RB7
#define PIN_DigIn1 	                _RB7
#define LAT_DigIn1 	                _LATB7
#define ODC_DigIn1	                _ODB7
#define RPOUT_DigIn1		            RPOR3bits.RP7R
#define RPIN_DigIn1		            7
#define CN_DigIn1		                23
#define TRIS_DigIn2	                _TRISB15
#define PORT_DigIn2 	                _RB15
#define LAT_DigIn2 	                _LATB15
#define ODC_DigIn2	                _ODB15
#define PIN_DigIn2 	                _RB15
#define RPOUT_DigIn2	                RPOR7bits.RP15R
#define RPIN_DigIn2	                15
#define CN_DigIn2		                11
#define ADC_value_DigIn2              Buffer_entradas[9] 
#define HAL_SetAnalog_DigIn2()        {_PCFG9=0;\
                                        adc_addAnalogChannel(9);}

// Board name definition
