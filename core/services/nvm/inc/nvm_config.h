#ifndef NVM_CONFIG_H
#define NVM_CONFIG_H

#include <stdint.h>
#include <stddef.h>

#define HW_SERIAL_NUMBER_SIZE    8U

typedef enum
{
    NVM_BLOCK_HW_CONFIG = 0,
    NVM_BLOCK_COUNT
} nvm_block_id_t;

typedef enum
{
    HW_REV_A = 0,
    HW_REV_B = 1
} hw_revision_t;

typedef struct
{
    char ascii[HW_SERIAL_NUMBER_SIZE];
} hw_serial_number_t;

#pragma pack(push, 1)

typedef struct
{
    hw_revision_t revision;
    hw_serial_number_t serial;
} hw_config_t;

#pragma pack(pop)

typedef union
{
    uint8_t raw[sizeof(hw_config_t)];
    hw_config_t cfg;
} hw_config_block_t;

#define NVM_I2C_BUS                     0U

#define EEPROM_HW_CONFIG_ADDRESS        0x0000
#define EEPROM_HW_CONFIG_SIZE           sizeof(hw_config_t)

_Static_assert(sizeof(hw_config_block_t) == sizeof(hw_config_t),
               "HW_CONFIG union size mismatch");

#endif

