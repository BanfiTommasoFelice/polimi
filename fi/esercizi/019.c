/*
Scrivere un programma in linguaggio C ANSI che acquisisce un valore intero non
negativo e fino a quando non è tale lo richiede, quindi calcola e visualizza il
numero di cifre di cui è composto.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  int n, m, tmp;
  do scanf("%d", &n);
  while (n <= 0);
  m   = 0;
  tmp = n;
  while (tmp) {
    tmp /= 10;
    m++;
  }
  printf("%d", m);
  return 0;
}
