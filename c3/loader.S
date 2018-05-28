%include "boot.inc"

section loader vstart=LOADER_BASE_ADDR
    mov ax, 0xb800
    mov gs, ax

    mov byte [gs:0x10], '2'
    mov byte [gs:0x11], 0xA4

    mov byte [gs:0x12], ' '
    mov byte [gs:0x13], 0xA4

    mov byte [gs:0x14], 'L'
    mov byte [gs:0x15], 0xA4

    mov byte [gs:0x16], 'O'
    mov byte [gs:0x17], 0xA4

    mov byte [gs:0x18], 'D'
    mov byte [gs:0x19], 0xA4

    jmp $
