#include <stdio.h>
#include "ej2.c"

int printbin(int n) {
  for (int i = 63; i >= 0; i--) {
    printf("%d", isOne(n, i));
  }
  printf("\n");
}