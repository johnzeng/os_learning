#include "print.h"
#include "init.h"
#include "debug.h"
#include "memory.h"

void main()
{
    put_str("kernel is loaded, runnig\n");
    init_all();
    void *addr = get_kernel_pages(3);
    put_str("\n get_kernel_pages start vaddr is ");
    put_int((uint32_t)addr);
    put_str("\n");
    //asm volatile("sti");
    while(1){}
}
