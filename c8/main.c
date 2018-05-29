#include "print.h"
#include "init.h"
#include "debug.h"

void main()
{
    put_str("kernel is loaded, runnig\n");
    init_all();
    ASSERT(1 == 2);
    asm volatile("sti");
    while(1){}
}
