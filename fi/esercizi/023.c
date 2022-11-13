/*
Si scriva un programma in C (ANSI 89) che acquisito un numero strettamente
positivo (e fino che non è tale, lo richiede) determini la parte intera della
sua radice quadrata.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  int n, q;
  do scanf("%d", &n);
  while (n < 0);
  q = 0;
  while (q * q < n) q++;
  if (q * q != n) q--;
  printf("%d", q);
  return 0;
}
