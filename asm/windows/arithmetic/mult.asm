.intel_syntax noprefix

.extern printf

.section .data
a:
    .asciz "rdx: %llx\n"

b:
    .asciz "rax: %llx\n"

c:
    .asciz "rbx: %llx\n"

d:
    .long 0xf

.section .text
.global  main

main:
    push rbp
    mov rbp, rsp
    sub rsp, 0x20   # shadow stack
    sub rsp, 0x10   # 2 local variable
    mov rax, 0x7fffffffffffffff
    mov rbx, 0xff
    # imul: rdx:rax, 
    # store the high bit in rdx
    # store the low bit in rax
    imul rbx

    mov [rbp + 0x08], rax
    mov [rbp + 0x10], rdx

    # call printf
    lea rcx,[rip + a]
    mov rdx, [rbp + 0x10]
    call printf

    lea rcx,[rip + b]
    mov rdx, [rbp + 0x8]
    call printf

    # imul with three parameter
    imul rbx, [rip + d], 0x7ff  # store the multiply of [d] and 0x7ff
                                # into rbx
    lea rcx, [rip + c]  
    mov rdx, rbx
    call printf

    xor rax, rax
    leave
    ret
