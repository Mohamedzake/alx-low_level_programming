; 101-hello_holberton.asm

section .data
    hello db "Hello, Holberton", 0

section .text
    global _start

_start:
    mov     rax, 1                  ; syscall number for sys_write
    mov     rdi, 1                  ; file descriptor for stdout
    mov     rsi, hello              ; pointer to the string to be printed
    mov     rdx, 16                 ; length of the string
    syscall                         ; invoke the syscall
    mov     rax, 60                 ; syscall number for sys_exit
    xor     rdi, rdi                ; exit status 0
    syscall                         ; invoke the syscall

