#ifndef DEBUG_H_C6HOYTTC
#define DEBUG_H_C6HOYTTC

void panic_spin(char * filename, int line, const char* func, const char * condition);

#define PANIC(...) panic_spin(__FILE__, __LINE__, __func__, __VA_ARGS__)

#ifdef NDEBUG
    #define ASSERT(CONDITION) ((void)0)
#else
    #define ASSERT(CONDITION) \
        {if(CONDITION){}else{PANIC(#CONDITION);}}
#endif

#endif /* end of include guard: DEBUG_H_C6HOYTTC */
