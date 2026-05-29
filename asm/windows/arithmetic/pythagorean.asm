.intel_syntax noprefix

.section .data
a:
  .long  9

b:
  .long  12

c:
  .long  16


.section .text
.global   main

main:
  push rbp
  mov rbp, rsp
  sub rsp, 0x20
  mov rax, [rip + a]  # move the value in a into rax
  mov rbx, [rip + b]  # move the value in b into rbx
  mov rdx, [rip + c]  # move the value in c into rdx
  imul rax, rax # square the value in rax
  imul rbx, rbx # square the value in rbx
  imul rdx, rdx # square the value in rdx
  add rax, rbx  # add the a^2 and b^2, and store the result into rax
  xor rax, rdx  # verify a^2 + b^2 = c^2
  leave
  ret
