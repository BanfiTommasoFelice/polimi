/*
Si scriva un programma in linguaggio C (ANSI 89) che acquisito un numero
maggiore o uguale a zero (e fino a che non è tale lo richiede), ne calcoli e
visualizzi il fattoriale.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  int n, f;
  do scanf("%d", &n);
  while (n < 0);
  f = n ? n : (n = 1);
  while (--n) f *= n;
  printf("%d", f);
  return 0;
}
