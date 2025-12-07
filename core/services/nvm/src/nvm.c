#include "nvm.h"
#include "nvm_config.h"
#include "i2c.h"
#include <stdbool.h>

#define NVM_EEPROM_I2C_ADDRESS  0x50

static const uint16_t g_block_address_map[NVM_BLOCK_COUNT] =
{
    [NVM_BLOCK_HW_CONFIG] = EEPROM_HW_CONFIG_ADDRESS
};

static void* g_i2c_handle = NULL;

void nvm_init(void)
{
    i2c_init();
    g_i2c_handle = i2c_open(NVM_I2C_BUS);
}

bool nvm_read(nvm_block_id_t block_id, void* block, size_t size)
{
    bool result = false;
    
    if (block != NULL && g_i2c_handle != NULL && block_id < NVM_BLOCK_COUNT)
    {
        uint16_t reg_addr = g_block_address_map[block_id];
        result = i2c_read(g_i2c_handle, NVM_EEPROM_I2C_ADDRESS, reg_addr, (uint8_t*)block, size);
    }
    
    return result;
}
