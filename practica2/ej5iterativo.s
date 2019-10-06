.global main

# Comentar alguna de las dos implementaciones antes de ejecutar.
# Separar en archivos cada función una vez finalizado.
# Falta implementar junto con la parte de C.

main:
     movq $7, %rcx
     movq $1, %rax
     # movq $5, %rdx
fact:
    mulq %rcx # Multiplico %rcx con %rax, aprovechando que rcx se decrementa solo por la instrucción loop.
    loop fact

    retq