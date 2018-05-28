kernel: main.o print.o init.o kernel.o interrupt.o timer.o debug.o string.o bitmap.o
	ld -melf_i386 main.o print.o init.o interrupt.o kernel.o timer.o string.o bitmap.o debug.o -Ttext 0xc0001500 -e main -o kernel.bin 
	dd if=kernel.bin of=hd60M.img bs=512 count=200 seek=9 conv=notrunc

main.o: main.c print.h
	gcc -m32 -I. -c -fno-stack-protector -fno-builtin -o main.o main.c

bitmap.o: bitmap.c bitmap.h
	gcc -m32 -I. -c -fno-stack-protector -fno-builtin -o bitmap.o bitmap.c

string.o: string.c string.h
	gcc -m32 -I. -c -fno-stack-protector -fno-builtin -o string.o string.c

debug.o: debug.c debug.h
	gcc -m32 -I. -c -fno-stack-protector -fno-builtin -o debug.o debug.c

init.o: init.c init.h
	gcc -m32 -I. -c -fno-stack-protector -fno-builtin -o init.o init.c
	
timer.o: timer.c timer.h
	gcc -m32 -I. -c -fno-stack-protector -fno-builtin -o timer.o timer.c

interrupt.o: interrupt.c interrupt.h
	gcc -m32 -I. -c -fno-stack-protector -fno-builtin -o interrupt.o interrupt.c

print.o: print.S print.h
	nasm -f elf -o print.o print.S

kernel.o: kernel.S
	nasm -f elf -o kernel.o kernel.S

loader: loader.S include/boot.inc
	nasm -Iinclude/ -o loader.bin loader.S
	dd if=loader.bin of=hd60M.img bs=512 count=4 seek=2 conv=notrunc

mbr: mbr.S include/boot.inc
	nasm -Iinclude/ -o mbr.bin mbr.S 
	dd if=mbr.bin of=hd60M.img bs=512 count=1 conv=notrunc
	
