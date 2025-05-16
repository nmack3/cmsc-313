section .data
    ; Define input bytes and a hex lookup table 
inputBuf db 0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A
hex db '0123456789ABCDEF'

section .bss
    ; Reserve space for the output buffer 
outputBuf resb 80

section .text
global _start

_start:
    ; Set up registers and buffers for later
    mov esi, inputBuf
    mov edi, outputBuf
    mov ecx, 8

convert:
    ; Convert each byte to hex and put them into the output
    lodsb
    mov bl, al
    shr al, 4
    mov al, [hex + eax]
    stosb
    mov al, bl
    and al, 0x0F
    mov al, [hex + eax]
    stosb
    mov al, ' '
    stosb
    loop convert

    dec edi
    mov byte [edi], 10

    ; Writing to stdout
    mov eax, 4
    mov ebx, 1
    mov ecx, outputBuf
    mov edx, edi
    sub edx, outputBuf
    inc edx
    int 0x80

	; exiting program successfully(hopefully)
    mov eax, 1
    xor ebx, ebx
    int 0x80
