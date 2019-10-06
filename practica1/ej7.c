#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "ej2.c"

typedef struct{
  unsigned short N[16];
}nro;

void print(nro n) {
    short sign[16], num[16];
    mpz_t n1, n2;
    for (unsigned i = 0; i < 15; i++) {
        num[i] = n.N[i];
        sign[i] = 0;
    }
    num[15] = n.N[15] & 0x7FFF;
    sign[15] = n.N[15] & 0x8000;

    mpz_init(n1);
    mpz_init(n2);
    mpz_import(n1, 16, -1, 2, 0, 0, num);
    mpz_import(n2, 16, -1, 2, 0, 0, sign);
    mpz_neg(n2, n2);
    mpz_add(n2, n1, n2);

    char str[1024];
    mpz_get_str(str, 10, n2);
    printf("Número: %s\n", str);

    mpz_clear(n1);
    mpz_clear(n2);
}

// Apartado a)

int es_par(nro n){
  return !isOne(n.N[0], 0);
}

void _and(nro n1, nro n2){
  nro n;
  for (int i = 0; i < 16; i++){
    n.N[i] = n1.N[i] & n2.N[i];
  }
}

void _or(nro n1, nro n2){
  nro n;
  for (int i = 0; i < 16; i++){
    n.N[i] = n1.N[i] | n2.N[i];
  }
}

void _xor(nro n1, nro n2){
  nro n;
  for (int i = 0; i < 16; i++){
    n.N[i] = n1.N[i] ^ n2.N[i];
  }
}

int es_cero(nro n){
  int flag = 1;
  for(int i = 0; i < 16 && flag == 1; i++){
    if (n.N[i]) {
      flag = 0;
    }
  }

  return flag;
}

int es_uno(nro n) {
  int flag = 1;

  for(int i = 1; i < 16 && flag == 1; i++){
    if (n.N[i]) {
      flag = 0;
    }
  }

  if (flag && n.N[0] == 1) {
    return 1;
  } else {
    return 0;
  }
}

nro correr_uno_der(nro n) {
  for (int i = 0; i < 15; i++) {
    n.N[i] = n.N[i] >> 1;

    if (n.N[i + 1] & 1) {
      n.N[i] = n.N[i] | 32768; // Mascara con el 16ª prendido
    } else {
      n.N[i] = n.N[i] & 32767; // Mascara con todos los bits prendidos menos el 16ª
    }
  }

  n.N[15] = n.N[15] >> 1;

  return n;
}

nro correr_uno_izq(nro n){
  for(int i = 15; i > 0; i--){
    n.N[i] = n.N[i] << 1;

    if(isOne(n.N[i-1], 15)){
      n.N[i] = n.N[i] | 1;
    } else{
      n.N[i] = n.N[i] & 65534;
    }
  }
  
  n.N[0] = n.N[0] << 1;

  return n;
}

nro correr_der(nro n, int b){
  for (int i = 0; i < b; i++){
    n = correr_uno_der(n);
  }

  return n;
}

nro correr_izq(nro n, int b){
  for (int i = 0; i < b; i++){
    n = correr_uno_izq(n);
  }

  return n;
}

nro sumar_nro(nro n1, nro n2) {
  nro resultado;
  int acarreo = 0, bit1, bit2;

  for (int i = 0; i < 16; i++) {
    resultado.N[i] = 0; 
  }

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {

      bit1 = isOne(n1.N[i], j);
      bit2 = isOne(n2.N[i], j);

      if (bit1 && bit2) {
        if (acarreo) {
          resultado.N[i] = resultado.N[i] | (1 << j);
        }
        acarreo = 1;
      } else if (bit1 || bit2) {
        if (!acarreo) {
          resultado.N[i] = resultado.N[i] | (1 << j);
        }
      } else {
        if (acarreo) {
          resultado.N[i] = resultado.N[i] | (1 << j);
        }
        acarreo = 0;
      }

    }
  }

  if (acarreo) {
    printf("Aviso: Carry flag encendida\n");
  }

  return resultado;
}

void printbin_nro(nro n) {
  for (int i = 15; i >= 0; i--) {
    for (int j = 15; j >= 0; j--) {
      printf("%d", isOne(n.N[i],j));
    }
    printf(" ");
  }
  printf("\n");
  printf("\n");
  printf("\n");
}

// int main(int argc, char* argv[]){

//   nro n1, n2;

//   for (int i = 0; i < 16; i++) {
//     n1.N[i] = 3123;
//   }

//   for (int i = 0; i < 16; i++) {
//     n2.N[i] = 413;
//   }

//   printbin_nro(n1);
//   printbin_nro(n2);

//   nro resultado = sumar_nro(n1, n2);

//   printbin_nro(resultado);

//   return 0;

// }