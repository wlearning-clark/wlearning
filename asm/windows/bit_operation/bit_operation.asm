.intel_syntax noprefix

.extern printf

.section .bss

.section .data
a:
  .asciz "rax: 0x%016llx, not rax: 0x%llx\n"
b:
  .asciz "rax: 0x%016llx, and with 0xf: 0x%016llx\n"
c:
  .asciz "rax: 0x%016llx, or with 0xf: 0x%016llx\n"
d:
  .asciz "rax: 0x%016llx, xor with 0xf: 0x%016llx\n"
e:
  .asciz "rax: 0x%016llx, shift right: 0x%016llx\n"

f:
  .asciz "1: %lld, 2: %lld, 3: %lld, 4: %lld, 5: %lld, 6: %lld, 7: %lld\n"

g:
  .asciz "rax: 0x%016llx, bit set rax: 0x%016llx\n"

.section .text

.global main

main:
  push rbp
  mov rbp, rsp
  sub rsp, 0x20  # shadow space for next function

  mov rax, 1
  lea rcx, [rip + a]
  mov rdx, rax
  not rax
  mov r8, rax
  call printf
  
  mov rax, 32
  lea rcx, [rip + a]
  mov rdx, rax
  not rax             #not
  mov r8, rax
  call printf
  
  mov rax, 0x8eb
  lea rcx, [rip + b]
  mov rdx, rax
  and rax, 0xf        # and
  mov r8, rax
  call printf
  
  mov rax, 0x00f01
  lea rcx, [rip + c]
  mov rdx, rax
  or rax, 0xf        # or
  mov r8, rax
  call printf
  
  mov rax, 0x00f001
  lea rcx, [rip + d]
  mov rdx, rax
  xor rax, 0xf     # xor
  mov r8, rax
  call printf
  
  # shift
  
  mov rax, 0x0ff00ff0f
  lea rcx, [rip + e]
  mov rdx, rax
  shr rax, 2     # shift right 2 bit
  mov r8, rax
  call printf
  
  # parameter test
  lea rcx, [rip + f]
  mov rdx, 1
  mov r8, 2
  mov r9, 3
  sub rsp, 0x20
  mov qword ptr [rsp + 0x20], 4
  mov qword ptr [rsp + 0x28], 5
  mov qword ptr [rsp + 0x30], 6
  mov qword ptr [rsp + 0x38], 7
  call printf


  mov rax, 0x0ff00ff0f
  lea rcx, [rip + e]
  mov rdx, rax
  shr rax, 0x10     # shift right 2 byte
  mov r8, rax
  call printf

  mov rax, 0xffff
  lea rcx, [rip + g]
  mov rdx, rax
  btr rax, 4        # bit reset index from 0, 0x1111_1111_1110_1111
  mov r8, rax
  call printf

  mov rax, 0x0f0f
  lea rcx, [rip + g]
  mov rdx, rax
  bts rax, 4        # bit set index from 0: 0x0000_1111_0001_1111
  mov r8, rax
  call printf

  leave
  ret
