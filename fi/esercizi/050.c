/*
Si scriva un programma in linguaggio C (ANSI 89) che acquisisce un array
bidimensionale quadrato di dimensione 4. Terminata l’acquisizione, il programma
calcola e visualizza 1, se i valori sulla diagonale sono strettamente crescenti,
0 altrimenti.
*/

#define N 4

#include <stdio.h>

int main(int argc, char** argv) {
  int m[N][N], i, j, r;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) scanf("%d", &m[i][j]);
  r = 1;
  for (i = 1; r && i < N; i++)
    if (m[i][i] <= m[i - 1][i - 1]) r = 0;
  printf("%d", r);
  return 0;
}
