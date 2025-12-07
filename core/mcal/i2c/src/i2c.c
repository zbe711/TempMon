#include "i2c.h"
#include <stdbool.h>

void i2c_init(void)
{
    // Enable I2C peripheral clock
    // Configure SCL/SDA pins (alternate function, pull-ups)
    // Configure I2C speed and addressing mode
    // Enable I2C peripheral
}

void* i2c_open(uint8_t bus)
{
    return NULL;
}

bool i2c_read(void* handle, uint8_t addr, uint16_t reg, uint8_t* buffer, size_t size)
{
    return true;
}
