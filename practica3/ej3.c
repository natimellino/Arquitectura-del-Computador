#include <stdio.h>
#include <math.h>

int fraccionFloat(float n) {
  int mascara = (1 << 23) -1;
  float* puntero1 = &n;
  int* puntero2 = (int*)puntero1;
  int fraccion = *puntero2 & mascara;
  return fraccion;
}

int exponenteFloat(float n) {
  int mascara = (1 << 8) - 1;
  float* puntero1 = &n;
  int* puntero2 = (int*)puntero1;
  int exponente = (*puntero2 >> 23) & mascara;
  return exponente;
}

long long int fraccionDouble(double n) {
  long long int mascara = (1 << 52) - 1;
  double* puntero1 = &n;
  long long int* puntero2 = (long long int*)puntero1;
  long long int fraccion = *puntero2 & mascara;
  return fraccion;
}

long long int exponenteDouble(double n) {
  long long int mascara = (1 << 11) - 1;
  double* puntero1 = &n;
  long long int* puntero2 = (long long int*)puntero1;
  long long int exponente = (*puntero2 >> 52) & mascara;
  return exponente;
}

int main() {
  float AvoFloat = 6.02252 * pow(10, 23);
  double AvoDouble = 6.02252 * pow(10, 23);


  printf("Constante de Avogrado\n");
  printf("Exponente en float = %d, fraccion en float = %d\n", exponenteFloat(AvoFloat), fraccionFloat(AvoFloat));
  printf("Exponente en double = %lld\n, fraccion en double = %lld\n", exponenteDouble(AvoDouble), fraccionDouble(AvoDouble));

  return 0;
}