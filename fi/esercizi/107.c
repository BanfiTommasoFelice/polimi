/*
La torre di Hanoi è un rompicapo in cui si hanno tre pioli (A, B, C) ed n dischi
di dimensione crescente. All’inizio del gioco, tutti i dischi sono sul piolo A
ordinati dal più grande (in basso) al più piccolo (in alto). Lo scopo del gioco
è spostare tutti i dischi sul piolo C rispettando due regole: non si può muovere
più di un disco per volta; non si può mai appoggiare un disco sopra un disco più
piccolo. SUGGERIMENTO: provare a pensare ad una soluzione ricorsiva, usando come
dimensione del problema il numero di dischi da spostare.
*/

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

void hanoi(int);

int main(int argc, char **argv) {
  int n;
  scanf("%d", &n);
  hanoi(n);
  return 0;
}

int move(int *i, int *j, int *V, int *W, char N, char M) {
  int x;
  x = (~*i && (!~*j || V[*i] < W[*j]));
  if (x) {
    printf("moving %d from %c to %c\n", V[*i], N, M);
    W[++(*j)] = V[(*i)--];
  }
  return x;
}

void hanoi(int n) {
  int *A, *B, *C;
  int x, y, z;
  int i;

  A = malloc(n * sizeof(int));
  B = malloc(n * sizeof(int));
  C = malloc(n * sizeof(int));

  if (!A) ERROR(A);
  if (!B) ERROR(B);
  if (!C) ERROR(C);

  for (i = 0; i < n; i++) A[i] = n - i;
  x = n - 1;
  y = -1;
  z = -1;
  i = 0;
  while (~x || ~y) {
    if (n & 1) {
      if (!i) i = move(&x, &z, A, C, 'A', 'C');
      if (!i) i = move(&z, &x, C, A, 'C', 'A');
      i = (!~x && !~y);
      if (!i) i = move(&x, &y, A, B, 'A', 'B');
      if (!i) i = move(&y, &x, B, A, 'B', 'A');
      i = (!~x && !~y);
    } else {
      if (!i) i = move(&x, &y, A, B, 'A', 'B');
      if (!i) i = move(&y, &x, B, A, 'B', 'A');
      i = (!~x && !~y);
      if (!i) i = move(&x, &z, A, C, 'A', 'C');
      if (!i) i = move(&z, &x, C, A, 'C', 'A');
      i = (!~x && !~y);
    }
    if (!i) i = move(&y, &z, B, C, 'B', 'C');
    if (!i) i = move(&z, &y, C, B, 'C', 'B');
    i = (!~x && !~y);
  }

  free(A);
  free(B);
  free(C);
}
