#include "mock.h"

#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

uint16_t mock_adc_get_value(void)
{
    return (uint16_t)(rand() % 4096);
}

void* mock_i2c_get_handle(void)
{
    return (void*)0xDEADBEEF;
}

bool mock_i2c_read_data(uint16_t reg, uint8_t* buffer, size_t size)
{
    bool result = false;
    
    if (buffer != NULL && size > 0)
    {
        if (reg == 0x0000U && size >= 9U)
        {
            buffer[0] = 1U;
            (void)strncpy((char*)&buffer[1], "ABC1234", 7U);
            buffer[8] = '\0';
        }
        else
        {
            (void)memset(buffer, 0x00, size);
        }
        result = true;
    }
    
    return result;
}

static void* timer_thread(void* arg)
{
    mock_timer_t* timer = (mock_timer_t*)arg;
    uint32_t period_us = 1000000 / timer->freq_hz;
    
    while (timer->running)
    {
        if (timer->callback != NULL)
        {
            timer->callback();
        }
        usleep(period_us);
    }
    return NULL;
}

int mock_timer_start(mock_timer_t* timer, uint32_t freq_hz, void (*callback)(void))
{
    int retval = -1;
    
    if (timer != NULL && callback != NULL)
    {
        timer->freq_hz = freq_hz;
        timer->callback = callback;
        timer->running = true;
        
        if (pthread_create(&timer->thread, NULL, timer_thread, timer) == 0)
        {
            retval = 0;
        }
        else
        {
            timer->running = false;
        }
    }
    
    return retval;
}

void mock_timer_stop(mock_timer_t* timer)
{
    if (timer != NULL && timer->running)
    {
        timer->running = false;
        if (timer->thread != 0)
        {
            pthread_join(timer->thread, NULL);
        }
    }
}

#endif