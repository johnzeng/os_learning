#include "print.h"
#include "init.h"
#include "debug.h"
#include "memory.h"
#include "thread.h"
#include "interrupt.h"
#include "console.h"
#include "process.h"

void k_thread_a(void* args);
void k_thread_b(void* args);
void u_thread_a(void* args);
void u_thread_b(void* args);
int test_var_a = 0;
int test_var_b = 0;
void main()
{
    put_str("kernel is loaded, runnig\n");
    init_all();
    thread_start("kthread_a\0", 1, k_thread_a, "a_");
    thread_start("kthread_b\0", 1, k_thread_b, "b_");
    process_execute(u_thread_a, "user_prog_a");
    process_execute(u_thread_b, "user_prog_b");
    intr_enable();
    while(1){
    }
}

void k_thread_b(void* args)
{
    char *para = args;
    while(1)
    {
        console_put_str(" v_b:0x");
        console_put_int(test_var_b);
    }
}

void k_thread_a(void* args)
{
    char *para = args;
    while(1)
    {
        console_put_str(" v_a:0x");
        console_put_int(test_var_a);
    }
}

void u_thread_a(void* args)
{
    char *para = args;
    while(1)
    {
        test_var_a++;
    }
}

void u_thread_b(void* args)
{
    char *para = args;
    while(1)
    {
        test_var_b++;
    }
}
