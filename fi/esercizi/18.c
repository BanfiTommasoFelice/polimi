/*
Scrivere un programma in linguaggio C ANSI che acquisisce 20 valori interi e
calcola e visualizza il massimo.
*/

#define N       20
#define INT_MIN 0x80000000

#include <stdio.h>

int main(int argc, char** argv) {
  unsigned i = N;
  int n, m = INT_MIN;
  while (i--) {
    scanf("%d", &n);
    if (n > m) m = n;
  }
  printf("%d", m);
  return 0;
}
