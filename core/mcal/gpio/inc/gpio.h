#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

void gpio_init(void);
void gpio_set(uint8_t pin, bool value);

#endif
