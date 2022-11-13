/*
Si scriva un programma in C (ANSI 89) che acquisisce i dati di array
bidimensionale quadrato di dimensione 3 di valori interi. In seguito il
programma calcola e visualizza 1 se si tratta di un quadrato magico seguito dal
valore della somma, 0 altrimenti (seguito da un valore qualsiasi). Un quadrato
magico è un insieme di numeri interi distinti in una tabella quadrata tale che
la somma dei numeri presenti in ogni riga, in ogni colonna e in entrambe le
diagonali dia sempre lo stesso valore.
*/

#define N 3

#include <stdio.h>

int main(int argc, char** argv) {
  int m[N][N], i, j, s, t, r;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) scanf("%d", &m[i][j]);
  s = 0;
  for (i = 0; i < N; i++) {
    s += m[i][i];
    t += m[i][N - i - 1];
  }
  for (i = 0; s == t && i < N; i++) {
    t = 0;
    for (j = 0; j < N; j++) t += m[i][j];
  }
  for (j = 0; s == t && j < N; j++) {
    t = 0;
    for (i = 0; i < N; i++) t += m[i][j];
  }
  r = (s == t);
  printf("%d %d", r, s);
  return 0;
}
