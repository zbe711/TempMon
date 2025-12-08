#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "nvm.h"
#include "time.h"
#include "mon.h"
#include "mock.h"

static inline void app_init(void);

int main(void)
{
    app_init();
    
    time_set_isr_callback(mon_process_sample);
    time_start_timer(10000);
    
    while (1)
    {
        __wfi();
    }
}

static inline void app_init(void)
{
    nvm_init();
    time_init();
    mon_init();
}
