/*
Si realizzi un programma in linguaggio C ANSI che riceve in ingresso valore
intero e calcola e visualizza il suo valore assoluto.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  int n, abs;
  scanf("%d", &n);
  if (n < 0)
    abs = -n;
  else
    abs = n;
  printf("%d", abs);
  return 0;
}
