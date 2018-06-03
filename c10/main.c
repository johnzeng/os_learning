#include "print.h"
#include "init.h"
#include "debug.h"
#include "memory.h"
#include "thread.h"
#include "interrupt.h"
#include "console.h"
#include "ioqueue.h"
#include "keyboard.h"

extern struct ioqueue kbd_buf;	   // 定义键盘缓冲区
void k_thread_a(void* args);
void main()
{
    put_str("kernel is loaded, runnig\n");
    init_all();
    thread_start("kthread_a\0", 1, k_thread_a, "a_");
    thread_start("kthread_b\0", 1, k_thread_a, "b_");
    intr_enable();
    while(1){
    }
}

void k_thread_a(void* args)
{
    char *para = args;
    while(1)
    {
        enum intr_status old_status = intr_disable();
        if(!ioq_empty(&kbd_buf))
        {
            console_put_str(para);
            char byte = ioq_getchar(&kbd_buf);
            console_put_char(byte);
        }
        intr_set_status(old_status);
    }
}
