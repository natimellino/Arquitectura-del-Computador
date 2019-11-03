.global fact2
# main:   
#    movq $5, %rdi # == x
#    call fact # == fact(%rdi) == fact(x)
movq $1, %rax # Valor de retorno.
fact2:
    cmpq $1, %rdi # Comparo rdi con 1
    jbe terminar # Si es menor o  igual termino
    mulq %rdi # Multiplico rax por rdi
    decq %rdi # Decremento rdi en uno (x = x - 1)
    call fact2 # Llamada recursiva == fact(x-1)
terminar:
    ret
