#ifndef STRING_H_TSI6CWLW
#define STRING_H_TSI6CWLW
#include "stdint.h"
void memset(void* dst_, uint8_t value, uint32_t size);
void memcpy(void* dst_, const void* str_, uint32_t size);
int memcmp(const void* a, const void* b, uint32_t size);
char* strcpy(char* dst_, const char* src);

#endif /* end of include guard: STRING_H_TSI6CWLW */
