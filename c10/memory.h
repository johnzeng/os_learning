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
void* get_kernel_pages(uint32_t cnt);

enum pool_flags{
    PF_KERNEL = 1,
    PF_USER = 2
};

#define PG_P_1 1
#define PG_P_0 0
#define PG_RW_R 0
#define PG_RW_W 2
#define PG_US_S 0
#define PG_US_U 4

#define PG_SIZE 4096

#endif /* end of include guard: MEMORY_H_8RPG2ZCP */
