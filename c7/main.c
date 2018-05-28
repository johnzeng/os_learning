#include "print.h"
#include "init.h"

void main()
{
    put_str("kernel is loaded, runnig\n");
    init_all();
    asm volatile("sti");
    while(1){}
}
