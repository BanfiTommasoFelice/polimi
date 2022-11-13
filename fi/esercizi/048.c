/*
Scrivere un programma in linguaggio C (ANSI 89) che chiede all’utente una
sequenza di 10 numeri interi. Il programma controlla che non vi siano duplicati
all’interno della sequenza data e visualizza l’esito del test, cioè 1 se non ci
sono duplicati, 0 altrimenti.
*/

#define N 10

#include <stdio.h>

int main(int argc, char** argv) {
  int v[N], r, i, j;
  for (i = 0; i < N; i++) scanf("%d", &v[i]);
  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++)
      if (v[i] > v[j]) {
        r    = v[i];
        v[i] = v[j];
        v[j] = r;
      }
  r = 1;
  j = v[0];
  for (i = 1; r && i < N; i++) (v[i] == j) && (r = 0) || (j = v[i]);
  printf("%d", r);
  return 0;
}
