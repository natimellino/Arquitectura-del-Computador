# Buscar un caracter dentro de una cadena apuntada por rdi.

.data
cad: .asciz "hola"
# char: .asciz "l"

.text

.global findc
findc:
    cld # Iremos incrementando rdi (DF = 0)
    movq $100, %rcx # Iteramos 100 veces.
    movb %sil, %al # El caracter que queremos buscar está en rsi, 
                    # lo pasamos a rax para poder usar scasl 
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

.global main
main:
    movq $cad, %rdi
    movb $107, %sil # = "l"
    call findc
    ret 
