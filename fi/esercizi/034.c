/*
Si scriva un programma in C (ANSI 89) che acquisito un valore intero calcola e
visualizza 1 se è un numero primo, 0 se non lo è, -1 se è un numero negativo.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  int n, p, i;
  scanf("%d", &n);
  if (n < 0)
    p = -1;
  else {
    if (n < 4)
      p = n > 1;
    else if (n % 2 == 0 || n % 3 == 0)
      p = 0;
    else
      p = 1;
    for (i = 5; p && i * i <= n; i += 6)
      if (n % i == 0 || n % (i + 2) == 0) p = 0;
  }
  printf("%d", p);
  return 0;
}
