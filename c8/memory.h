#ifndef MEMORY_H_8RPG2ZCP
#define MEMORY_H_8RPG2ZCP

#include "stdint.h"
#include "bitmap.h"

struct virtual_addr{
    struct bitmap vaddr_bitmap;
    uint32_t vaddr_start;
};
extern struct pool kernel_pool, user_pool;
void mem_init(void);

#endif /* end of include guard: MEMORY_H_8RPG2ZCP */
