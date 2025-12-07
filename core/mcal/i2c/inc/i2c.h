#ifndef I2C_H
#define I2C_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void i2c_init(void);
void* i2c_open(uint8_t bus);
bool i2c_read(void* handle, uint8_t addr, uint16_t reg, uint8_t* buffer, size_t size);

#endif
