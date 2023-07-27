section .data
    hello db "Hello, Holberton", 10, 0    ; 10 is the ASCII code for newline (\n)

section .text
    extern printf

global main

main:
    push rbp
    mov rdi, hello
    call printf
    pop rbp

    ; Exit the program
    mov rax, 60                 ; syscall number for sys_exit
    xor rdi, rdi                ; exit status 0
    syscall                     ; invoke the syscall

