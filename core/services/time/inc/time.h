#ifndef TIME_H
#define TIME_H

#include <stdint.h>
#include <stdbool.h>

typedef void (*time_isr_callback_t)(void);

void time_init(void);
int time_start_timer(uint32_t freq_hz);
void time_set_isr_callback(time_isr_callback_t callback);

#endif
