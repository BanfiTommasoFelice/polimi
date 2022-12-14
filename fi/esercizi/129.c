/*
Scrivere un programma che acquisisce i dati per popolare due array
monodimensionali di 10 interi ciascuno. Il programma verifica quindi se, pur di
fare uno scorrimento circolare del secondo array, i due array siano identici.
Nello scorrimento circolare, la cifra che si trova in ultima posizione diventa
quella in prima posizione dopo lo scorrimento. In caso affermativo il programma
visualizza di quante posizioni deve essere fatto scorrere il secondo array verso
destra. In caso negativo, visualizza -1.
*/

#define N 10

#include <stdio.h>

int circular_equal(int, int *, int *);

int main(int argc, char **argv) {
  int a[N], b[N], i, n;
  for (i = 0; i < N; i++) scanf("%d", &a[i]);
  for (i = 0; i < N; i++) scanf("%d", &b[i]);
  i = circular_equal(N, a, b);
  printf("%d", i);
  return 0;
}

int circular_equal(int n, int *a, int *b) {
  int k, i;
  i = 0;
  for (k = 0; i != n && k < n; k++)
    for (i = 0; i < n && a[i] == b[(i + k) % n]; i++) {}
  return (k == n ? -1 : (!k ? 0 : n - k + 1));
}