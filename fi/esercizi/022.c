/*
Si scriva un programma in C (ANSI 89) che acquisito un numero visualizza la
somma delle sue cifre. Per esempio, se l’utente inserisce 18 il programma
calcola e visualizza 9, se l’utente inserisce -137 visualizza 11.
*/

#define BASE 10

#include <stdio.h>

int main(int argc, char** argv) {
  int n, s, tmp;
  scanf("%d", &n);
  s   = 0;
  tmp = n;
  if (tmp < 0) tmp *= -1;
  while (tmp) {
    s += tmp % BASE;
    tmp /= BASE;
  }
  printf("%d", s);
  return 0;
}
