#include "init.h"
#include "print.h"
#include "interrupt.h"
#include "memory.h"
#include "timer.h"
#include "thread.h"
#include "keyboard.h"
#include "console.h"

void init_all()
{
    put_str("init_all \n");
    idt_init();
    timer_init();
    mem_init();
    thread_init();
    keyboard_init();
    console_init();
    tss_init();
}

