segment .data
a   dd    4
b   dd    2.2
c   times 10 dd 0
d   dw    1, 2
e   db    0xff
f   db    "hello world", 0

segment .bss
g resd  1
h resd  10
i resd  100

segment .text
global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 0x20

  xor eax, eax

  add rsp, 0x20
  mov rsp, rbp
  pop rbp
  ret

