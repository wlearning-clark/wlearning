.intel_syntax noprefix

.extern printf

.section .data
a:
  .asciz "rbx: %lld\n"

.section .text
.global main

main:
  push rbp
  mov rbp, rsp
  sub rsp, 0x20 # shadow stack

  mov rax, 3 
  mov rbx, 10
  test rax, rax 
# cmovz rbx, rax # move if compare result is zero
# cmovge rbx, rax
  cmovl rbx, rax
  
  lea rcx, [rip + a]
  mov rdx, rbx 
  call printf

  xor rax,rax
  leave
  ret


