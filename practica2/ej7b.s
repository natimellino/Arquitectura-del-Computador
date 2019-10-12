.global main

main:
  movq $0xFFFFFFFFEEEEEEEE, %rax
  movq $64, %rcx
  xorq %rdx, %rdx
contar:
  rolq $1, %rax
  adcq $0, %rdx
  loop contar

  movq %rdx, %rax
  retq
