#include "gpio.h"

void gpio_init(void)
{
    // Initialize GPIO peripheral
    // TODO: Initialize GPIO peripheral
}

int gpio_configure(uint8_t pin, uint8_t mode)
{
    // Configure pin mode
    // TODO: Configure GPIO input/output mode
    return 0;
}

void gpio_set(uint8_t pin, bool value)
{
    // Set pin high if value is true, low if false
    // TODO: Write to GPIO output register
}

bool gpio_get(uint8_t pin)
{
    // Read from GPIO input register
    // TODO: Read from GPIO input register
    return false;
}

void gpio_toggle(uint8_t pin)
{
    // Toggle pin state
    // TODO: Toggle GPIO output register
}
