#include "string.h"
#include "global.h"
#include "debug.h"

void memset(void* dst_, uint8_t value, uint32_t size)
{
    ASSERT(null != dst_);
    uint8_t* dst = (uint8_t*)dst_;
    while(size-- > 0){
        *dst++ = value;
    }
}

void memcpy(void* dst_, const void* src_, uint32_t size)
{
    ASSERT(null != dst_ && null != src_);
    uint8_t* dst = dst_;
    const uint8_t* src = src_;
    while(size-- > 0) *dst++ = *src++;
}

int memcmp(const void* a_, const void* b_, uint32_t size)
{
    ASSERT(null != a_ && null != b_);
    const char* a = a_;
    const char* b = b_;
    while(size -- > 0)
    {
        if(*a != *b)
        {
            return *a > *b ? 1: -1;
        }
        a++;
        b++;
    }
}

char* strcpy(char* dst_, const char* src)
{
    ASSERT(null != dst_ && null != src);
    char * r = dst_;
    while((*dst_++ = *src++));
    return r;
}

uint32_t strlen(const char* str)
{
    ASSERT(null != str);
    const char* p = str;
    while(*p++);
    return p - str - 1;
}

int8_t strcmp(const char* a, const char* b)
{
    ASSERT(null != a);
    while(*a != 0 && *a == *b)
    {
        a++;b++;
    }
    return *a < *b ? -1: *a > *b;
}

char* strchr(const char* str, const uint8_t ch)
{
    ASSERT(str != null);
    while(*str != 0)
    {
        if(*str == ch)
        {
            return (char*)str;
        }
        str++;
    }
    return null;
}

char* strrchr(const char* str, const uint8_t ch)
{
    ASSERT(null != str);
    const char* last_char = null;
    while(*str != 0)
    {
        if(*str == ch)
        {
            last_char = str;
        }
        str++;
    }
    return (char*)last_char;
}

char* strcat(char* dst_, const char* src_)
{
    ASSERT(null != dst_ && null != src_);
    char* str = dst_;
    while(* str ++);
    --str;
    while((*str++ = *src_ ++));
    return dst_;
}

uint32_t strchrs(const char* str, uint8_t ch)
{
    ASSERT(null != str);
    uint32_t ch_cnt = 0;
    const char* p = str;
    while(*p != 0)
    {
        if(*p == ch){
            ch_cnt ++;
        }
        p++;
    }
    return ch_cnt;
}

