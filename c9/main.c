#include "print.h"
#include "init.h"
#include "debug.h"
#include "memory.h"
#include "thread.h"
#include "interrupt.h"

void k_thread_a(void* args);
void main()
{
    put_str("kernel is loaded, runnig\n");
    init_all();
    thread_start("kthread_a\0", 8, k_thread_a, "argsA \0");
    thread_start("kthread_b\0", 1, k_thread_a, "thread b\0");
    intr_enable();
    while(1){
        put_str("Main");
    }
}

void k_thread_a(void* args)
{
    char *para = args;
    while(1)
    {
        put_str(para);
    }
}
