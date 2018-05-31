#ifndef CONSOLE_H_QABFWH2M
#define CONSOLE_H_QABFWH2M

#include "stdint.h"
void console_init();
void console_put_str(char* srt);
void console_put_char(uint8_t char_ascii);
void console_put_int(uint32_t num);

#endif /* end of include guard: CONSOLE_H_QABFWH2M */
