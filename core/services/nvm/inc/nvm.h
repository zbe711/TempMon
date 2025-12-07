#ifndef NVM_H
#define NVM_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "nvm_config.h"

void nvm_init(void);
bool nvm_read(nvm_block_id_t block_id, void* block, size_t size);

#endif
