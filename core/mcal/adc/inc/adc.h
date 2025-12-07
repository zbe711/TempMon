#ifndef ADC_H
#define ADC_H

#include <stdint.h>

typedef enum
{
    ADC_CHANNEL_TEMP = 0
} adc_channel_t;

typedef void (*adc_dma_callback_t)(void);

void adc_init(void);
int adc_configure(adc_channel_t channel, uint8_t resolution);
int adc_start_conversion(adc_channel_t channel);
uint16_t adc_read_raw(adc_channel_t channel);
void adc_register_dma_callback(adc_dma_callback_t callback);

#endif
