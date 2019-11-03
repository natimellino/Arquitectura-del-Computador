.global fact1

# Falta implementar junto con la parte de C.

# main:
#     movq $7, %rcx
#     movq $1, %rax
     # movq $5, %rdx

movq %rdi, %rcx
movq $1, %rax
fact1:
    mulq %rcx # Multiplico %rcx con %rax, aprovechando que rcx se decrementa solo por la instrucción loop.
    loop fact1

    ret
