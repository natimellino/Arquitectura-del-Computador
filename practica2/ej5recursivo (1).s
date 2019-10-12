.global main
main:   
    movq $5, %rdi # == x
    call fact # == fact(%rdi) == fact(x)
fact:
    movq $1, %rax # Valor de retorno.
    call fact_
fact_:
    cmpq $1, %rdi # Comparo rdi con 1
    jbe terminar # Si es menoro  igual termino
    mulq %rdi # Multiplico rax por rdi
    decq %rdi # Decremento rdi en uno (x = x - 1)
    call fact_ # Llamada recursiva == fact(x-1)
terminar:
    retq 
