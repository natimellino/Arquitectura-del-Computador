.data
s1: .asciz "hola"
s2: .asciz "hola"

.text

.global comparar
cld # Vamos incrementando ambos registros
movq $4, %rcx

comparar:
  cmpsb
  jb lower
  ja greater
  loop comparar
  jmp fin

greater:
  movq $1, %rax # s1 es mayor
  ret

lower:
  movq $-1, %rax # s1 es menor
  ret

fin:
  movq $0, %rax # Si son iguales devolvemos 0
  ret

.global main
main:
  movq $s1, %rdi
  movq $s2, %rsi
  # movq $4, %rdx # Longitud de la cadena
  call comparar
  ret
