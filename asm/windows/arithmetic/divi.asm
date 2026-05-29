.intel_syntax noprefix

.extern printf
.section  .data
a:
  .asciz "rax: %lld\nrdx: %lld\n"

.section .text
.global main

main:
  push rbp
  mov rbp, rsp
  sub rsp, 0x20  # shadow space

  # idiv, rdx:rax stored the quotient in rax, the remainder in rdx
  # rax is the implicit dividend register, don't allow to change the register
  mov rax, -10 # dividend
  cqto  #  convert quadWord (4 word)  to octaWord (8 word)
        # extend rax from 64 to 128 bit(combind with using rdx)
  mov rsi, 3   # divisor
  idiv rsi
  
  # local variable
  sub rsp, 0x10
  mov [rbp - 0x28], rax  # quotient
  mov [rbp - 0x30], rdx  # remainder
  # printf
  lea rcx, [rip + a]
  mov rdx, [rbp - 0x28]
  mov r8 , [rbp - 0x30]
  call printf     # echo rax -3, rdx, -1

  xor rax, rax
  leave
  ret
