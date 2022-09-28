/*
Si realizzi un programma in linguaggio C ANSI che, letti tre numeri interi a, b,
c, stampi a terminale la sequenza dei tre numeri in ordine monotono non
decrescente.
*/

#include <stdio.h>

int main(int argc, char **argv) {
  int a, b, c, tmp;
  scanf("%d%d%d", &a, &b, &c);
  if (a > b) {
    tmp = a;
    a   = b;
    b   = tmp;
  }
  if (b > c) {
    tmp = c;
    c   = b;
    b   = tmp;
  }
  if (a > b) {
    tmp = a;
    a   = b;
    b   = tmp;
  }
  printf("%d %d %d", a, b, c);
  return 0;
}
