#include "time.h"
#include "gpt.h"
#include "adc.h"
#include <stdbool.h>
#include <stddef.h>

static bool g_timer_running = false;
static uint32_t g_tick_count = 0;
static time_isr_callback_t g_isr_callback = NULL;

static void adc_dma_complete_isr(void)
{
    if (g_isr_callback != NULL)
    {
        g_isr_callback();
    }
}

static void timer_callback(void)
{
    g_tick_count++;
    adc_start_conversion(ADC_CHANNEL_TEMP);
}

void time_init(void)
{
    gpt_init();
    adc_init();
    g_timer_running = false;
    g_tick_count = 0;
    g_isr_callback = NULL;
    adc_register_dma_callback(adc_dma_complete_isr);
}

int time_start_timer(uint32_t freq_hz)
{
    int retval = 0;

    if (gpt_configure(0, freq_hz, timer_callback) != 0)
    {
        retval = -1;
    }
    
    if (gpt_start(0) != 0)
    {
        retval = -1;
    }
    
    g_timer_running = true;
    
    return retval;
}

void time_stop_timer(void)
{
    gpt_stop(0);
    g_timer_running = false;
}

uint32_t time_get_tick_count(void)
{
    return g_tick_count;
}

bool time_is_timer_running(void)
{
    return g_timer_running;
}

void time_set_isr_callback(time_isr_callback_t callback)
{
    g_isr_callback = callback;
}
