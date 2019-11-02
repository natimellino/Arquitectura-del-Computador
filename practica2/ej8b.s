# Compara dos string: si s1 es mayor que s2 devuelve -1, si es menor devuelve 1
# y si son iguales devuelve 0.

# Arreglar para que devuelva 0 si los string son iguales,
# Los otros casos andan bien.

.data
s1: .asciz "hola"
s2: .asciz "hola"

.text

.global comparar
cld # Vamos incrementando ambos registros
movq $4, %rcx

comparar:
  repe cmpsb # Repetimos cmpsb rcx veces
  jrcxz equal  # Si rcx es 0 los string son iguales.
  jb lower
  ja greater

equal: 
  movq $0, %rax
  ret

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
