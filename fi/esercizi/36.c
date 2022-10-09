/*
Si scriva un programma in C (ANSI 89) che acquisisce i dati di un array
bidimensionale quadrato di dimensione 5x5 di valori interi. Il programma
visualizza 1 se si tratta di una matrice identità, 0 altrimenti.
*/

#define NR 5
#define NC 5

#include <stdio.h>

int main(int argc, char** argv) {
  int m[NR][NC], s, i, j;
  for (i = 0; i < NR; i++)
    for (j = 0; j < NC; j++) scanf("%d", &m[i][j]);
  s = (NR == NC);
  for (i = 0; s && i < NR; i++)
    for (j = 0; s && j < NC; j++)
      if (i == j && m[i][j] != 1)
        s = 0;
      else if (i != j && m[i][j] != 0)
        s = 0;
  printf("%d", s);
  return 0;
}
