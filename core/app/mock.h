#ifndef MOCK_H
#define MOCK_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)

#include <pthread.h>

typedef struct
{
    pthread_t thread;
    bool running;
    uint32_t freq_hz;
    void (*callback)(void);
} mock_timer_t;

uint16_t mock_adc_get_value(void);
void* mock_i2c_get_handle(void);
bool mock_i2c_read_data(uint16_t reg, uint8_t* buffer, size_t size);
int mock_timer_start(mock_timer_t* timer, uint32_t freq_hz, void (*callback)(void));

static inline void __wfi(void)
{
}

#else

static inline void __wfi(void)
{
    __asm__ volatile("wfi" ::: "memory");
}

#endif

#endif

