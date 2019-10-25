#include <stdio.h>
#include <math.h>

int obtenerFraccion(float n){
	int mascara = 0x7fffff;
	float* punteron = &n;
	int* numero = (int *)punteron;
	int fraccion = *numero & mascara;
	return fraccion;
}

int obtenerExponente(float n){
	int mascara = 255 << 23;
	float* punteron = &n;
	int* numero = (int *)punteron;
	int exponente = *numero & mascara;
	exponente = exponente  >> 23;	
	return exponente;
}

int main(){
float a = 1.1;
int f = obtenerFraccion(a);
int e = obtenerExponente(a);
printf("%d %d\n",f,e);
return 0;
}