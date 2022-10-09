/*
Si scriva un programma in C (ANSI 89) che acquisiti due valore naturali che
devono essere compresi nell’intervallo [1,1023] (e fino a che il vincolo non
viene rispettato non si procede), calcola e visualizza la loro rappresentazione
in binario usando lo stesso numero di cifre.
*/

#define MIN  1
#define MAX  1023
#define BASE 2
#define N    10 /* ceil(log_BASE(MAX)) */

#include <stdio.h>

int main(int argc, char** argv) {
  int n, m, i, j, binn[N], binm[N];
  do scanf("%d", &n);
  while (n < MIN || n > MAX);
  do scanf("%d", &m);
  while (m < MIN || m > MAX);
  for (i = 0; i < N; i++, n /= BASE) binn[i] = n % BASE;
  for (j = 0; j < N; j++, m /= BASE) binm[j] = m % BASE;
  while (!binn[--i]) {}
  while (!binm[--j]) {}
  if (i < j)
    i = j;
  else if (j < i)
    j = i;
  for (; i >= 0; i--) printf("%d", binn[i]);
  printf("\n");
  for (; j >= 0; j--) printf("%d", binm[j]);
  return 0;
}
