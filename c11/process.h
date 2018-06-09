#ifndef PROCESS_H_4OI86BNF
#define PROCESS_H_4OI86BNF

#include "stdint.h"
#include "thread.h"

void process_execute(void* filename, char* name);
void start_process(void* filename_);
void process_activate(struct task_struct* p_thread);
void page_dir_activate(struct task_struct* p_thread);
uint32_t* create_page_dir(void);
void create_user_vaddr_bitmap(struct task_struct* user_prog);

#endif /* end of include guard: PROCESS_H_4OI86BNF */
