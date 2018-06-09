#include "debug.h"
#include "print.h"
#include "interrupt.h"

void panic_spin(char * filename, int line, const char* func, const char * condition)
{
    intr_disable();
    put_str("\n\n\n\n\n PANIC!!!\n\n\n");
    put_str("file name:");put_str(filename);put_char('\n');
    put_str("line number:");put_int(line);put_char('\n');
    put_str("func name:");put_str(func);put_char('\n');
    put_str("condition:");put_str(condition);put_char('\n');
    while(1){};
}
