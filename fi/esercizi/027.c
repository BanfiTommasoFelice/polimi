/*
Scrivere un programma in C (ANSI 89) che acquisisce due numeri interi
strettamente positivi a e b (se i numeri non sono tali li richiede), calcola e
visualizza MCD e mcm.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  int a, b, x, y, tmp, mcd, mcm;
  do scanf("%d", &a);
  while (a <= 0);
  do scanf("%d", &b);
  while (b <= 0);
  x = a;
  y = b;
  while (y) {
    tmp = y;
    y   = x % y;
    x   = tmp;
  }
  mcd = x;
  mcm = a * b / mcd;
  printf("%d %d", mcd, mcm);
  return 0;
}
