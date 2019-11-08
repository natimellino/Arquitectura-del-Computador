#include <stdio.h>
#include <string.h>

// IMPORTANTE: compilar como: gcc -no-pie ej8.c ej8a.s ej8b.s -g

// Desde acá llamamos a las funciones del ejercicio a) y b)

int findc(char *s, char c, int len);
int comparar(char *s1, char *s2, int len);

int main(){
    char s1[100], s2[100];
    char c;
    int len = strlen(s1);
    scanf("%s", s1);
    scanf("%s", s2);
    scanf(" %c", &c);
    printf("findc: %d\n", findc(s1, c, len));
    printf("comparar: %d\n", comparar(s1, s2, len));
    return 0;
}