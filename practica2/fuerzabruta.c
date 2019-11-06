#include <stdio.h>

int findc(const char* s1, const char c, int lens1);
int comparar(const char* s1, const char* s2, int len);

int fuerza_bruta(const char *S, const char *s, unsigned lS, unsigned ls){
    unsigned i, j;
    for (i = 0; i < lS - ls + 1; i++){
        if (!comparar(S[i], s[0], 1)){
            for (j = 0; j < ls && !comparar(S[i+j], s[j], 1); j++){}
            if (j == ls){
                return i;
            }
        }
    }
    return -1;
}

int main(){
    return 0;
}