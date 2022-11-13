/*
Scrivere un programma in linguaggio C (ANSI 89) che chiede all’utente di
inserire i dati interi di un array bi-dimensionale quadrato di dimensione 3 e
visualizza 1 se la matrice è simmetrica, 0 altrimenti.
*/

#define N 3

#include <stdio.h>

int main(int argc, char** argv) {
  int m[N][N], i, j, s;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) scanf("%d", &m[i][j]);
  s = 1;
  for (i = 0; s && i < N; i++)
    for (j = 0; s && j < i; j++)
      if (m[i][j] != m[j][i]) s = 0;
  printf("%d", s);
  return 0;
}
