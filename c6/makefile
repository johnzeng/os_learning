kernel: main.o print.o
	ld -melf_i386 main.o print.o -Ttext 0xc0001500 -e main -o kernel.bin 
	dd if=kernel.bin of=hd60M.img bs=512 count=200 seek=9 conv=notrunc

main.o: main.c print.h
	gcc -m32 -I. -c -o main.o main.c

print.o: print.S print.h
	nasm -f elf -o print.o print.S

loader: loader.S include/boot.inc
	nasm -Iinclude/ -o loader.bin loader.S
	dd if=loader.bin of=hd60M.img bs=512 count=4 seek=2 conv=notrunc

mbr: mbr.S include/boot.inc
	nasm -Iinclude/ -o mbr.bin mbr.S 
	dd if=mbr.bin of=hd60M.img bs=512 count=1 conv=notrunc
	
