#ifndef PRINT_H_6ISUSVXC
#define PRINT_H_6ISUSVXC
#include "stdint.h"

void put_char(uint8_t char_ascii);
void put_str(const char * message);
void put_int(uint32_t x);
void set_cursor(uint32_t cursor_pos);

#endif /* end of include guard: PRINT_H_6ISUSVXC */
