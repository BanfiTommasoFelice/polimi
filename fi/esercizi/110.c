/*
Scrivere un programma che dati 10 numeri interi inseriti dall’utente, ed
acquisito un ulteriore numero intero strettamente positivo, determini quali sono
le combinazioni dei 10 numeri che hanno come somma il numero inserito. Si
supponga che esistano numeri ripetuti tra i 10 inseriti.
*/

#define N 10

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

int combinations(int, int *, int);

int main(int argc, char **argv) {
  int i, v[N], n;
  for (i = 0; i < N; i++) scanf("%d", &v[i]);
  scanf("%d", &n);
  n = combinations(N, v, n);
  printf("%d", n);
  return 0;
}

int max(int a, int b) { return a > b ? a : b; }

int knapsack(int W, int n, int *weight, int *values) {
  int *A, *B, *up, *down;
  int i, w;
  A = malloc((W + 1) * sizeof(int));
  B = malloc((W + 1) * sizeof(int));
  if (!A) ERROR(A);
  if (!B) ERROR(B);
  for (i = 0; i <= n; i++) {
    up   = (i % 2 ? A : B);
    down = (i % 2 ? B : A);
    for (w = 0; w <= W; w++)
      if (i == 0 || w == 0)
        down[w] = 0;
      else if (weight[i - 1] <= w)
        down[w] = max(values[i - 1] + up[w - weight[i - 1]], up[w]);
      else
        down[w] = up[w];
  }
  w = down[W];
  free(A);
  free(B);
  return w;
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int combinations(int n, int *v, int k) {
  int i, j, s, c, z;
  qsort(v, n, sizeof(int), cmp);
  i = 0;
  s = 0;
  c = 0;
  z = 0;
  while (v[i] == 0) {
    z++;
    i++;
  }
  j = i;
  while (j < n) {
    while (s > k && i < j) s -= v[i++];
    if (s == k) c++;
    s += v[j++];
  }
  return c * (1 << z);
}
