/*
Si scriva un programma in C (ANSI 89) che acquisito un valore naturale che deve
essere compreso nell’intervallo [1,1023] (e fino a che non è tale lo richiede),
calcola e visualizza la sua rappresentazione nel sistema binario utilizzando il
numero massimo di bit previsti data l’ampiezza dell’intervallo.
*/

#define MIN  1
#define MAX  1023
#define BASE 2
#define N    10 /* ceil(log_BASE(MAX)) */

#include <stdio.h>

int main(int argc, char** argv) {
  int n, i, result[N];
  do scanf("%d", &n);
  while (n < MIN || n > MAX);
  for (i = 0; i < N; i++, n /= BASE) result[i] = n % BASE;
  for (i--; i >= 0; i--) printf("%d", result[i]);
  return 0;
}
