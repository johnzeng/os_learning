#include "interrupt.h"
#include "thread.h"
#include "print.h"
#include "string.h"
#include "debug.h"
#include "global.h"
#include "memory.h"
#include "stdint.h"

struct task_struct* main_thread;
struct list thread_ready_list;
struct list thread_all_list;
static struct list_elem* thread_tag;
extern void switch_to(struct task_struct* cur, struct task_struct* next);

struct task_struct * running_thread()
{
    uint32_t esp;
    asm("mov %%esp, %0": "=g"(esp));
    return (struct task_struct*)(esp & 0xfffff000);
}

static void kernel_thread(thread_func* function, void* args)
{
    intr_enable();
    function(args);
}

void thread_create(struct task_struct* pthread, thread_func function, void* func_args)
{
    pthread->self_kstack -= sizeof(struct intr_stack);
    pthread->self_kstack -= sizeof(struct thread_stack);
    struct thread_stack* kthread_stack = (struct thread_stack*)pthread->self_kstack;
    kthread_stack->eip = kernel_thread;
    kthread_stack->function = function;
    kthread_stack->func_args = func_args;
    kthread_stack->ebp = kthread_stack->ebx = kthread_stack->esi = kthread_stack->edi = 0;
}
void init_thread(struct task_struct* pthread, char* name, int prio)
{
    memset(pthread, 0, sizeof(*pthread));
    strcpy(pthread->name, name);
    if(pthread == main_thread)
    {
        pthread->status = TASK_RUNNING;
    }else{
        pthread->status = TASK_READY;
    }
    pthread->priority = prio;
    pthread->ticks = prio;
    pthread->elapsed_ticks = 0;
    pthread->pgdir = NULL;
    pthread->self_kstack = (uint32_t*)((uint32_t)pthread + PG_SIZE);
    pthread->stack_magic = THREAD_STACK_MAGIC;
}

struct task_struct* thread_start(char* name, int prio, thread_func function, void* func_args)
{
    struct task_struct* thread = get_kernel_pages(1);
    init_thread(thread, name, prio);
    thread_create(thread, function, func_args);

    ASSERT(!elem_find(&thread_ready_list, &thread->general_tag));
    list_append(&thread_ready_list, &thread->general_tag);

    ASSERT(!elem_find(&thread_all_list, &thread->all_list_tag));
    list_append(&thread_all_list, &thread->all_list_tag);
    return thread;
}

static void make_main_thread(void)
{
    main_thread = running_thread();
    init_thread(main_thread, "main", 31);

    ASSERT(!elem_find(&thread_all_list, &main_thread->all_list_tag));

    list_append(&thread_all_list, &main_thread->all_list_tag);
}

void schedule()
{
    ASSERT(intr_get_status() == INTR_OFF);
    struct task_struct *cur = running_thread();
    if(cur->status == TASK_RUNNING)
    {
        ASSERT(!elem_find(&thread_ready_list, &cur->general_tag));
        list_append(&thread_ready_list, &cur->general_tag);
        cur->ticks = cur->priority;
        cur->status = TASK_READY;
    }else{
        //do nothing
    }
    ASSERT(!list_empty(&thread_ready_list));
    thread_tag = NULL;
    thread_tag = list_pop(&thread_ready_list);
    struct task_struct* next = elem2entry(struct task_struct, general_tag, thread_tag);
    next->status = TASK_RUNNING;
    switch_to(cur,next);
}

void thread_init(void)
{
    put_str("thread_init start\n");
    list_init(&thread_all_list);
    list_init(&thread_ready_list);
    make_main_thread();
    put_str("thread_init_done \n");
}
