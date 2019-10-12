# Ejercicio 7)a..

.global main

main:
    movq $0, %rax
    movq $0xFFFFFFFFEEEEEEEE, %rax
    rolq $32, %rax

    retq
