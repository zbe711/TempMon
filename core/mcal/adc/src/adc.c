#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "adc.h"
#include "mock.h"

static adc_dma_callback_t g_dma_callback = NULL;
static uint16_t g_adc_buffer = 0;
static bool g_conversion_in_progress = false;

static int adc_configure(adc_channel_t channel, uint8_t resolution);

static void simulate_dma_completion(void)
{
    if (g_dma_callback != NULL)
    {
        g_dma_callback();
    }
}

void adc_init(void)
{
    g_dma_callback = NULL;
    g_adc_buffer = 0;
    g_conversion_in_progress = false;
    
    (void)adc_configure(ADC_CHANNEL_TEMP, 12);
}

static int adc_configure(adc_channel_t channel, uint8_t resolution)
{
    return 0;
}

int adc_start_conversion(adc_channel_t channel)
{
    int retval = -1;
    
    if (!g_conversion_in_progress)
    {
        g_conversion_in_progress = true;
        
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
        g_adc_buffer = mock_adc_get_value();
#else
        g_adc_buffer = 2048;
#endif
        
        simulate_dma_completion();
        g_conversion_in_progress = false;
        retval = 0;
    }
    
    return retval;
}

uint16_t adc_read_raw(adc_channel_t channel)
{
    return g_adc_buffer;
}

void adc_register_dma_callback(adc_dma_callback_t callback)
{
    g_dma_callback = callback;
}
