#include <stdio.h>
#include <gmp.h>
#include "ej7.c"

nro copia_nro(nro n) {
  nro copia;

  for (int i = 0; i < 16; i++) {
    copia.N[i] = n.N[i];
  }

  return copia;
}

nro mult_nro(nro a, nro b) {
  if (es_cero(b)) {
    return b;
  } else if (es_uno(b)) {
    return a;
  } else if (es_par(b)) {
    return mult_nro(correr_uno_izq(a), correr_uno_der(b));
  } else {
    nro copia = copia_nro(a);
    return sumar_nro(copia, mult_nro(correr_uno_izq(a), correr_uno_der(b)));
  }
}

int main() {

  nro n1, n2;

  for (int i = 0; i < 16; i++) {
    n1.N[i] = 0;
  }

  for (int i = 0; i < 16; i++) {
    n2.N[i] = 2;
  }

  // n1.N[0] = 2;
  // n2.N[0] = 5;


  print(n1);
  print(n2);

  nro resultado = mult_nro(n1, n2);

  print(resultado);

  return 0;
}
