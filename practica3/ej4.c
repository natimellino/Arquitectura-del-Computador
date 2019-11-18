#include <stdio.h>
#include <math.h>

typedef struct nro
{
  int signo : 1;
  int exponente : 16;
  unsigned int fraccion : 18;
} nro;

int myisnan(nro n)
{
  return n.exponente == (1 << 15) - 1 && n.fraccion != 0;
}

int myisinf(nro n)
{
  return n.exponente == (1 << 15) - 1 && n.fraccion == 0;
}

int myiszero(nro n)
{
  return n.exponente == 0 && n.fraccion == 0;
}

nro nronan()
{
  nro nan;
  nan.signo = 0;
  nan.exponente = (1 << 15) - 1;
  nan.fraccion = 1;
  return nan;
}

nro nroinf()
{
  nro inf;
  inf.signo = 0;
  inf.exponente = (1 << 15) - 1;
  inf.fraccion = 0;
  return inf;
}

nro suma(nro n1, nro n2)
{
  nro resultado;
  // Chequeamos que no sea infinito ni NaN.
  if (myisnan(n1) || myisnan(n2))
    return nronan();

  if (myisinf(n1) || myisinf(n2))
    return nroinf();

  if (myiszero(n1))
    return n2;

  if (myiszero(n2))
    return n1;

  nro nuevaFraccion;
  // Igualamos exponentes.
  if (n1.exponente < n2.exponente)
  {
    n1.fraccion = n1.fraccion >> (n2.exponente - n1.exponente);
    n1.exponente = n2.exponente;
  }
  else if (n2.exponente < n1.exponente)
  {
    n2.fraccion = n2.fraccion >> (n1.exponente - n2.exponente);
    n2.exponente = n1.exponente;
  }
  nuevaFraccion.exponente = n1.exponente; // Ahora los exponentes están igualados.
  // Sumamos las mantisas teniendo en cuenta el signo.
  if (n1.signo == n2.signo)
  {
    nuevaFraccion.signo = n1.signo;
    nuevaFraccion.fraccion = n1.fraccion + n2.fraccion;
  }
  else if (n1.signo != n2.signo)
  {
    if (n1.fraccion > n2.fraccion)
    {
      nuevaFraccion.signo = n1.signo;
      nuevaFraccion.fraccion = n1.fraccion - n2.fraccion;
    }
    else
    {
      nuevaFraccion.signo = n2.signo;
      nuevaFraccion.fraccion = n2.fraccion - n1.fraccion;
    }
  }
  // Normalizamos el resultado según IEEE 754. (corregir esta parte.)
  while ((nuevaFraccion.fraccion & (1 << 17)) == 0)
  // Mientras el primer bit sea cero, desplazamos la mantisa y
  // corregimos el exponente.
  {
    nuevaFraccion.fraccion = nuevaFraccion.fraccion << 1;
    nuevaFraccion.exponente = nuevaFraccion.exponente - 1;
  }
  // Preguntar si hay que sumarle el exceso 30000 al exponente.
  return nuevaFraccion;
}

int main()
{

  nro n1;
  nro n2;

  n1.signo = 0;
  n1.exponente = 10;
  n1.fraccion = 52;

  n2.signo = 0;
  n2.exponente = 11;
  n2.fraccion = 12;

  nro resultado = suma(n1, n2);

  printf("%d %d %d\n", resultado.signo, resultado.exponente, resultado.fraccion);

  return 0;
}