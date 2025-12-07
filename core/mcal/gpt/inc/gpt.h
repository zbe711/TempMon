#ifndef GPT_H
#define GPT_H

#include <stdint.h>

void gpt_init(void);
int gpt_configure(uint8_t channel, uint32_t freq_hz, void (*callback)(void));
int gpt_start(uint8_t channel);
void gpt_stop(uint8_t channel);
uint32_t gpt_get_counter(uint8_t channel);

#endif
