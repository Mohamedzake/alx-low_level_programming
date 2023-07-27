; 101-hello_holberton.asm

section .data
    hello db "Hello, Holberton", 0

section .text
    global _start

_start:
    ; Call main function from the C standard library
    call main

    ; Exit the program
    mov     rax, 60                 ; syscall number for sys_exit
    xor     rdi, rdi                ; exit status 0
    syscall                         ; invoke the syscall

; Define the main function (empty for now)
section .bss
section .text
    extern main

