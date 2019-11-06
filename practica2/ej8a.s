# Buscar un caracter dentro de una cadena apuntada por rdi.

# .data
# cad: .asciz "hola"
# char: .asciz "l"

# .text

.global findc

findc:
    movq %rdx, %rcx # La longitud de la cadena viene en el 3er argumento.
    cld # Iremos incrementando rdi (DF = 0)
    movb %sil, %al # El caracter que queremos buscar está en rsi, 
                   # lo pasamos a rax para poder usar scasl 
    jmp encontrar

encontrar:
    sigue:
        scasb # Comparamos lo apuntado en rdi con rax
        je found # Si la ZF se activó lo encontramos.
        loop sigue # Caso contrario seguimos iterando.
        movq $0, %rax # No lo encontramos retornamos 0.
        jmp fin
    found:
        movq $1, %rax # Lo encontramos, retornamos 1.
    fin:
        ret

