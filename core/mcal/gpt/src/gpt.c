#include "gpt.h"
#include "mock.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#define GPT_MAX_CHANNELS 4

typedef struct
{
    bool configured;
    uint32_t freq_hz;
    void (*callback)(void);
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
    mock_timer_t timer;
#endif
} gpt_channel_t;

static gpt_channel_t g_channels[GPT_MAX_CHANNELS] = {0};

void gpt_init(void)
{
    for (int i = 0; i < GPT_MAX_CHANNELS; i++)
    {
        g_channels[i].configured = false;
        g_channels[i].callback = NULL;
    }
}

int gpt_configure(uint8_t channel, uint32_t freq_hz, void (*callback)(void))
{
    int retval = -1;
    
    if (channel < GPT_MAX_CHANNELS)
    {
        g_channels[channel].freq_hz = freq_hz;
        g_channels[channel].callback = callback;
        g_channels[channel].configured = true;
        retval = 0;
    }
    
    return retval;
}

int gpt_start(uint8_t channel)
{
    int retval = -1;
    
    if (channel < GPT_MAX_CHANNELS && g_channels[channel].configured)
    {
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
        retval = mock_timer_start(&g_channels[channel].timer, 
                                   g_channels[channel].freq_hz, 
                                   g_channels[channel].callback);
#else
        retval = 0;
#endif
    }
    
    return retval;
}
