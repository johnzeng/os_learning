#ifndef IO_H_YLC8QFZ1
#define IO_H_YLC8QFZ1

#include "stdint.h"

static inline void outb(uint16_t port, uint8_t data)
{
    asm volatile ( "outb %b0, %w1" : : "a" (data), "Nd" (port));
}

static inline void outsw(uint16_t port, const void* addr, uint32_t word_cnt)
{
    asm volatile ( "cld; rep outsw " : "+S" (addr), "+c" (word_cnt): "d" (port));
}

static inline void inb(uint16_t port, uint8_t data)
{
    asm volatile ( "inb %b0, %wl" : "=a" (data): "Nd" (port));
}

static inline void insw(uint16_t port, const void* addr, uint32_t word_cnt)
{
    asm volatile ( "cld; rep insw" : "+D" (addr), "+c" (word_cnt): "d" (port): "memory");
}



#endif /* end of include guard: IO_H_YLC8QFZ1 */
