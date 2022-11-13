/*
In un array bidimensionale di valori interi, si definisce dominante ogni
elemento dell’array che è strettamente maggiore di tutti gli elementi dell’array
bidimensionale che si trova in basso a destra rispetto all’elemento stesso (si
veda la figura), non considerando però tutti gli elementi presenti nell’ultima
colonna e nell’ultima riga. Si realizzi un sottoprogramma che ricevuto in
ingresso un array bidimensionale e qualsiasi altro parametro ritenuto
strettamente necessario calcoli e restituisca al chiamante il numero di elementi
dominanti presenti.
*/

#define R 4
#define C 8

#include <stdio.h>

int dominant(int[R][C]);

int main(int argc, char** argv) {
  int m[R][C], i, j;
  for (i = 0; i < R; i++)
    for (j = 0; j < C; j++) scanf("%d", &m[i][j]);
  i = dominant(m);
  printf("%d", i);
  return 0;
}

int max(int a, int b) { return (a > b ? a : b); }
int max3(int a, int b, int c) { return max(a, max(b, c)); }

int dominant(int m[R][C]) {
  int s[R][C], i, j, c;
  s[R - 1][C - 1] = m[R - 1][C - 1];
  for (j = C - 2; j >= 0; j--) s[R - 1][j] = max(s[R - 1][j + 1], m[R - 1][j]);
  for (i = R - 2; i >= 0; i--) {
    s[i][C - 1] = max(m[i][C - 1], s[i + 1][C - 1]);
    for (j = C - 2; j >= 0; j--)
      s[i][j] = max3(m[i][j], s[i + 1][j], s[i][j + 1]);
  }
  c = 0;
  for (i = 0; i < R - 1; i++)
    for (j = 0; j < C - 1; j++)
      if (m[i][j] > s[i + 1][j + 1]) c++;
  return c;
}
