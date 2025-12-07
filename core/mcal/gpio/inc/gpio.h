#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

void gpio_init(void);
int gpio_configure(uint8_t pin, uint8_t mode);
void gpio_set(uint8_t pin, bool value);
bool gpio_get(uint8_t pin);
void gpio_toggle(uint8_t pin);

#endif
