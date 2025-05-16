This is a sumer simple asseembly program that takes in some bytes of data and outputs those as hex in the terminal.


BUILDING & RUNNING:
nasm -f elf32 translate2ASCII.asm -o translate2ASCII.o
ld -m elf_i386 -o translate2ASCII translate2ASCII.o
./translate2ASCII
