#include "global.h"
#include "thread.h"
#include "print.h"
#include "string.h"
#include "memory.h"

static struct tss tss;
void update_tss_esp(struct task_struct* pthread)
{
    tss.esp0 = (uint32_t*)((uint32_t)pthread + PG_SIZE);
}

static struct gdt_desc make_gdt_desc(uint32_t* addr, uint32_t limit, uint8_t attr_low, uint8_t attr_high)
{
    uint32_t desc_base = (uint32_t) addr;
    struct gdt_desc desc;
    desc.limit_low_word = limit & 0xffff;
    desc.base_low_word = desc_base & 0xffff;
    desc.base_mid_byte = ((desc_base & 0x00ff0000) >> 16);
    desc.attr_low_byte = (uint8_t) attr_low;
    desc.limit_high_attr_high = (((limit & 0x000f0000) >> 16) + (uint8_t)(attr_high));
    desc.base_high_byte = desc_base >> 24;
    return desc;
}

void tss_init(){
    put_str("tss_init begin \n");
    uint32_t tss_size = sizeof(tss);
    memset(&tss, 0, sizeof(tss));
    tss.ss0 = SELECTOR_K_STACK;
    tss.io_base = tss_size;
    *((struct gdt_desc*)0xc0000920) = make_gdt_desc((uint32_t*)&tss, tss_size - 1, TSS_ATTR_LOW, TSS_ATTR_HIGH);

    *((struct gdt_desc*)0xc0000928) = make_gdt_desc((uint32_t*)0, 0xfffff, GDT_CODE_ATTR_LOW_DPL3, GDT_ATTR_HIGH);
    *((struct gdt_desc*)0xc0000930) = make_gdt_desc((uint32_t*)0, 0xfffff, GDT_DATA_ATTR_LOW_DPL3, GDT_ATTR_HIGH);

      /* gdt 16位的limit 32位的段基址 */
    uint64_t gdt_operand = ((8 * 7 - 1) | ((uint64_t)(uint32_t)0xc0000900 << 16));   // 7个描述符大小
    asm volatile ("lgdt %0" : : "m" (gdt_operand));
    asm volatile ("ltr %w0" : : "r" (SELECTOR_TSS));
    put_str("tss_init and ltr done\n");

}
