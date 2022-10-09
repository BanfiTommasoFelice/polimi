/*
Si scriva un programma in C (ANSI 89) che acquisito un valore intero non
negativo calcola e visualizza il suo fattoriale.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  long n, f;
  scanf("%ld", &n);
  f = n;
  while (--n) f *= n;
  printf("%ld", f);
  return 0;
}
