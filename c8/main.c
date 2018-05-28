#include "print.h"
#include "init.h"
#include "debug.h"

void main()
{
    put_str("kernel is loaded, runnig\n");
    init_all();
    asm volatile("sti");
    ASSERT(1 == 2);
    while(1){}
}
