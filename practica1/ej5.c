#include <stdio.h>
#include <stdlib.h>

void codificar_mensaje(int clave){
  char c;
  int i;

  while((i = getc(stdin)) != EOF){
    c = i;
    c = c ^ clave;
    printf("%c", c);
  }
  printf("\n");
}

int main(int argc, char* argv[]) {

  if (argc == 2) {
    codificar_mensaje(atoi(argv[1]));
  }

  return 0;
}