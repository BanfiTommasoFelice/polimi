/*
Scrivere un programma che chiede all’utente di inserire la dimensione dim della
matrice quadrata di numeri interi che intende usare, con dimensione massima
accettabile 10. Se il valore inserito dall’utente non rispetta questo vincolo,
viene chiesto nuovamente. Il programma acquisisce i dati della matrice dim × dim
e crea visualizza la matrice ruotata di 90 gradi in senso orario.
*/

#define NMAX 10

#include <stdio.h>

int main(int argc, char** argv) {
  int m[NMAX][NMAX], r[NMAX][NMAX], n, i, j;
  do scanf("%d", &n);
  while (n < 2 || n > NMAX);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%d", &m[i][j]);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) r[i][j] = m[n - j - 1][i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) printf("%d ", r[i][j]);
    printf("\n");
  }
  return 0;
}
