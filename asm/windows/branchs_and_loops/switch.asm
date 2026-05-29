.intel_syntax noprefix
.extern printf

.section .data
switch:
  .quad  main_case0
  .quad  main_case1
  .quad  main_case2
a: 
  .long 2
b: 
  .asciz "rax:%lld, rbx: %lld\n"

.section .text
.global main

main:
    push rbp
    mov rbp, rsp
    sub rsp, 0x20

    movsxd rax, [rip + a]
    lea rdi, [rip + switch]
    jmp qword ptr [rdi + rax * 8]

main_case0:
    mov rbx, 100
    jmp end

main_case1:
    mov rbx, 101
    jmp end

main_case2:
    mov rbx, 110
    jmp end

end:
    lea rcx, [rip + b]
    mov rdx, rax
    mov r8, rbx
    call printf
    xor rax, rax 
    leave
    ret
