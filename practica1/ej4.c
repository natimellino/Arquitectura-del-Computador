#include <stdio.h>

void rotar_valores(int a, int b, int c){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    a = a ^ c;
    c = a ^ c;
    a = a ^ c;

    printf("%d %d %d\n", a, b, c);
}