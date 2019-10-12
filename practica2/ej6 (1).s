.data
format: .asciz "%ld\n"
format_: .asciz "%hx\n"
i: .quad 0xDEADBEEF
    .text
    .global main
main:
    movq $format, %rdi
    movq $1234, %rsi
    xorq %rax, %rax
    call printf

    # Parte a)
    movq $format, %rdi
    movq (%rsp), %rsi
    xorq %rax, %rax 
    call printf
    
    # Parte b)
    movq $format, %rdi
    movq (%rdi), %rsi
    xorq %rax, %rax 
    call printf

    # Parte c)
    movq $format_, %rdi
    movq (%rdi), %rsi
    xorq %rax, %rax 
    call printf

    # Parte d)
    movq $format, %rdi
    movq (%rsp), %rsi
    xorq %rax, %rax 
    call printf

    # Parte e)
    movq $format, %rdi
    movq (%rsp), %rsi
    xorq %rax, %rax 
    call printf

    # Parte f)
    movq $format, %rdi
    movq (%rsp), %rsi
    xorq %rax, %rax 
    call printf

    # Parte g)
    movq $format, %rdi
    movq (%rsp), %rsi
    xorq %rax, %rax 
    call printf

    ret
