/*
Si scriva un sottoprogramma che ricevuto in ingresso un array x di valori interi
ed un valore intero n e qualsiasi parametro ritenuto strettamente necessario,
trasmette al chiamante l’array di valori che costituiscono la media mobile di x
di finestra n. L’elemento i-esimo della media mobile viene calcolato come media
degli n valori del vettore in ingresso che precedono e includono l’elemento i.
Se l’elemento i è preceduto da meno di n-1 valori, la media si calcola su
quelli.
*/

#include <stdio.h>
#include <stdlib.h>

void sliding_avg(int, int *, int, float *);

int main(int argc, char **argv) {
  int i, n, k, *x;
  float *out;
  scanf("%d", &n);
  x = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) scanf("%d", &x[i]);
  scanf("%d", &k);
  out = malloc(n * sizeof(float));
  sliding_avg(n, x, k, out);
  for (i = 0; i < n; i++) printf("%.2f ", out[i]);
  free(x);
  free(out);
  return 0;
}

void sliding_avg(int n, int *x, int k, float *out) {
  int sum, i;
  sum = 0;
  for (i = 0; i < k; i++) {
    sum += x[i];
    out[i] = sum / (i + 1.f);
  }
  for (; i < n; i++) {
    sum -= x[i - k];
    sum += x[i];
    out[i] = (float)sum / k;
  }
}
