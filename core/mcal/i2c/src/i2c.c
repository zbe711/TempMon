#include "i2c.h"
#include "mock.h"
#include <stdbool.h>

void i2c_init(void)
{
}

void* i2c_open(uint8_t bus)
{
    void* handle = NULL;
    
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
    handle = mock_i2c_get_handle();
#endif
    
    return handle;
}

bool i2c_read(void* handle, uint8_t addr, uint16_t reg, uint8_t* buffer, size_t size)
{
    bool result = false;
    
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)
    result = mock_i2c_read_data(reg, buffer, size);
#endif
    
    return result;
}
