#include <stdio.h>
#include <math.h>

typedef struct nro {
  int signo:1;
  int exponente:16;
  unsigned int fraccion:18;
} nro;

int myisnan(nro n) {
  return n.exponente == (1 << 15) - 1 && n.fraccion != 0;
}

int myisinf(nro n) {
  return n.exponente == (1 << 15) - 1 && n.fraccion == 0;
}

int myiszero(nro n) {
  return n.exponente == 0 && n.fraccion == 0;
}

nro nronan() {
  nro nan;
  nan.signo = 0;
  nan.exponente = (1 << 15) - 1;
  nan.fraccion = 1;
  return nan;
}

nro nroinf() {
  nro inf;
  inf.signo = 0;
  inf.exponente = (1 << 15) - 1;
  inf.fraccion = 0;
  return inf;
}

nro suma(nro n1, nro n2) {
  nro resultado;
  // Chequeamos que no sea infinito ni NaN.
  if (myisnan(n1) || myisnan(n2)) {
    return nronan();
  }

  if (myisinf(n1) || myisinf(n2)) {
    return nroinf();
  }

  if (myiszero(n1)) {
    return n2;
  } else if (myiszero(n2)) {
    return n1;
  }

  int nuevaFraccion; 
  // Igualamos exponentes.
  if (n1.exponente > n2.exponente) {
    resultado.exponente = n1.exponente;
    nuevaFraccion = (n2.fraccion << (n1.exponente - n2.exponente));
    resultado.fraccion = n1.signo * n1.fraccion + n2.signo * nuevaFraccion;
    // Chequeamos que signo corresponde en el resultado.
    if (n1.fraccion > nuevaFraccion) {
      resultado.signo = n1.signo;
    } else {
      resultado.signo = n2.signo;
    }

  } else {
    nuevaFraccion = (n1.fraccion << (n2.exponente - n1.exponente));
    resultado.exponente = n2.exponente;
    resultado.fraccion = n2.signo * n2.fraccion + n1.signo * nuevaFraccion;

    if (n2.fraccion > nuevaFraccion) {
      resultado.signo = n2.signo;
    } else {
      resultado.signo = n1.signo;
    }

  }

  if 

  return resultado;
}


int main() {

  nro n1;
  nro n2;

  n1.signo = 0;
  n1.exponente = 53;
  n1.fraccion = 520;

  n2.signo = 0;
  n2.exponente = 123;
  n2.fraccion = 1231;

  nro resultado = suma(n1, n2);

  printf("%d %d %d\n", resultado.signo, resultado.exponente, resultado.fraccion);

  return 0;
}