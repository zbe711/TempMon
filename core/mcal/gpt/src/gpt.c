#include "gpt.h"
#include <stddef.h>
#include <stdbool.h>

#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
#include <pthread.h>
#include <unistd.h>
#else
#include <stdint.h>
#endif

#define GPT_MAX_CHANNELS 4

typedef struct
{
    bool configured;
    uint32_t freq_hz;
    void (*callback)(void);
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
    pthread_t thread;
    bool running;
#endif
} gpt_channel_t;

static gpt_channel_t g_channels[GPT_MAX_CHANNELS] = {0};

#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
static void* timer_thread(void* arg)
{
    gpt_channel_t* channel = (gpt_channel_t*)arg;
    uint32_t period_us = 1000000 / channel->freq_hz;
    
    while (channel->running)
    {
        if (channel->callback != NULL)
        {
            channel->callback();
        }
        usleep(period_us);
    }
    return NULL;
}
#endif

void gpt_init(void)
{
    for (int i = 0; i < GPT_MAX_CHANNELS; i++)
    {
        g_channels[i].configured = false;
        g_channels[i].callback = NULL;
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
        g_channels[i].running = false;
#endif
    }
}

int gpt_configure(uint8_t channel, uint32_t freq_hz, void (*callback)(void))
{
    if (channel >= GPT_MAX_CHANNELS)
    {
        return -1;
    }
    
    g_channels[channel].freq_hz = freq_hz;
    g_channels[channel].callback = callback;
    g_channels[channel].configured = true;
    
    return 0;
}

int gpt_start(uint8_t channel)
{
    if (channel >= GPT_MAX_CHANNELS || !g_channels[channel].configured)
    {
        return -1;
    }
    
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
    g_channels[channel].running = true;
    if (pthread_create(&g_channels[channel].thread, NULL, timer_thread, &g_channels[channel]) != 0)
    {
        g_channels[channel].running = false;
        return -1;
    }
#endif
    
    return 0;
}

void gpt_stop(uint8_t channel)
{
    if (channel >= GPT_MAX_CHANNELS)
    {
        return;
    }
    
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
    g_channels[channel].running = false;
    if (g_channels[channel].thread != 0)
    {
        pthread_join(g_channels[channel].thread, NULL);
    }
#endif
}

uint32_t gpt_get_counter(uint8_t channel)
{
    if (channel >= GPT_MAX_CHANNELS)
    {
        return 0;
    }
    return 0;
}
