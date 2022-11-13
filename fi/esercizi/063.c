/*
Scrivere un programma che mostra a video il triangolo di Tartaglia di dimensione
chiesta all’utente (massimo 10). Il programma deve eseguire un controllo di
validità sulla dimensione chiesta all’utente e nel caso di valore non valido
richiederla.
*/

#define MINL 1
#define MAXL 10

#include <stdio.h>

void scan(int*, int, int);

int main(int argc, char** argv) {
  int n, t[MAXL][MAXL], i, j;
  scan(&n, MINL, MAXL);
  for (i = 0; i < n; i++) t[i][0] = t[i][i] = 1;
  for (i = 1; i < n; i++)
    for (j = 1; j < i; j++) t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) printf("%d ", t[i][j]);
    printf("\n");
  }
  return 0;
}

void scan(int* n, int min, int max) {
  do scanf("%d", n);
  while (*n < min || *n > max);
}
