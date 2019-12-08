# Division a0, a1 --> a0 / a1 
# devuelve la división entera.

.global dividir

dividir:
  li t2, 0
  li t3, 1
 # Casos especiales
  beq a1, t2, cero
  beq a1, t3, uno
  beq a0, t2, retcero

  li t0, 0 # contador (le vamos sumando a1 hasta que sea mayor que a0)
  li t1, 0 # resultado de la division se guarda en t1
  bucle:
    add t0, t0, a1
    bge t0, a0, fin # si t0 >= a0 terminamos 
    add t1, t1, 1
    j bucle
  fin:
    mv a0, t1 # resultado de la division
    ret
  cero:
    li a0, -1  
    ret
  uno:
    ret
  retcero:
    li a0, 0
    ret



