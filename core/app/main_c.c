#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "nvm.h"
#include "time.h"
#include "mon.h"
#include "mock.h"

static volatile bool g_sample_ready = false;

static inline void app_init(void);
static void isr_temperature(void);

int main(void)
{
    app_init();
    
    time_set_isr_callback(isr_temperature);
    time_start_timer(10000);
    
    while (1)
    {
        if (g_sample_ready)
        {
            __disable_irq();
            g_sample_ready = false;
            __enable_irq();
            
            mon_process_sample();

            // printf("Hello, world from C99!\n\n");
        }
    }
    
    return 0;
}

static inline void app_init(void)
{
    nvm_init();
    time_init();
    mon_init();
}

static void isr_temperature(void)
{
    g_sample_ready = true;
}
