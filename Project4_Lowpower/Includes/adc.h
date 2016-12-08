#ifndef ADC_H_
#define ADC_H_



void ADC_Init10b(void);
void ADC_Init16b(void);
unsigned short ADC_read10b(uint8_t channelNumber);
unsigned short ADC_read16b(uint8_t channelNumber);
#endif /* ADC_H_ */
