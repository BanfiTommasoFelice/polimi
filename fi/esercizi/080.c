/*
Si scriva un sottoprogramma che riceve in ingresso un array di valori interi e
qualsiasi altro parametro ritenuto strettamente necessario e calcola e trasmette
al chiamante un array di interi, tale per cui il valore i-esimo è pari al numero
di valori presenti nell’array di partenza di valore inferiore al valore in
posizione i. Si scriva poi un programma che ricevuti in ingresso al massimo 50
numeri interi positivi (l’acquisizione termina quando l’utente inserisce un
valore negativo o nullo) avvalendosi del precedente sottoprogramma visualizzi i
valori minori di quanti acquisiti in ingresso.
*/

#define MAXN 50

#include <stdio.h>
#include <stdlib.h>

void f(int, int[], int[]);

int main(int argc, char **argv) {
  int n, i, v[MAXN], w[MAXN];
  n = 0;
  do scanf("%d", &v[n]);
  while (n < MAXN && v[n++] > 0);
  if (n < MAXN && v[n] <= 0) n--;
  f(n, v, w);
  for (i = 0; i < n; i++) printf("%d ", w[i]);
  return 0;
}

int cmp(int *a, int *b) { return (*a) - (*b); }

int *low_bound(int *a, int *b, int k) {
  int c, s, *i;
  c = b - a;
  while (c > 0) {
    s = c / 2;
    i = a + s;
    if (*i < k) {
      a = ++i;
      c -= s + 1;
    } else
      c = s;
  }
  return a;
}

int *up_bound(int *a, int *b, int k) {
  int c, s, *i;
  c = b - a;
  while (c > 0) {
    s = c / 2;
    i = a + s;
    if (*i <= k) {
      a = ++i;
      c -= s + 1;
    } else
      c = s;
  }
  return a;
}

void f(int n, int v[], int w[]) {
  int t[MAXN], i;
  for (i = 0; i < n; i++) t[i] = v[i];
  qsort(t, n, sizeof(int), cmp);
  for (i = 0; i < n; i++) w[i] = low_bound(t, t + n, v[i]) - t;
}
