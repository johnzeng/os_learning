#ifndef THREAD_H_0DJGHGEC
#define THREAD_H_0DJGHGEC

#include "stdint.h"
#include "memory.h"
#include "list.h"

typedef void thread_func(void*);
enum task_status{
    TASK_RUNNING,
    TASK_READY,
    TASK_BLOCKED,
    TASK_WAITING,
    TASK_HANGING,
    TASK_DIED
};

struct intr_stack{
    uint32_t vec_no;
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp_dummy;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
    uint32_t gs;
    uint32_t fs;
    uint32_t es;
    uint32_t ds;

    uint32_t error_code;
    void (*eip)(void);
    uint32_t cs;
    uint32_t eflags;
    void* esp;
    uint32_t ss;
};

struct thread_stack{
    uint32_t ebp;
    uint32_t ebx;
    uint32_t edi;
    uint32_t esi;
    void (*eip)(thread_func* func, void * func_args);
    void (*unused_retaddr);
    thread_func* function;
    void* func_args;
};

struct task_struct{
    uint32_t* self_kstack;
    enum task_status status;
    uint8_t priority;
    uint8_t ticks;
    char name[16];
    uint32_t elapsed_ticks;

    struct list_elem general_tag;
    struct list_elem all_list_tag;
    uint32_t *pgdir;
    struct virtual_addr userprog_vaddr;
    uint32_t stack_magic;
};

void thread_create(struct task_struct* pthread, thread_func function, void* func_args);
void init_thread(struct task_struct* pthread, char* name, int prio);
struct task_struct* thread_start(char* name, int prio, thread_func function, void* func_args);
struct task_struct* running_thread();
void schedule();
void thread_init();
void thread_block(enum task_status stat);
void thread_unblock(struct task_struct* pthread);
void update_tss_esp(struct task_struct* pthread);

#define THREAD_STACK_MAGIC 0x19870916


#endif /* end of include guard: THREAD_H_0DJGHGEC */
