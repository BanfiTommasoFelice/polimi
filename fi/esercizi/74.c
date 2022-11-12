/*
Scrivere un sottoprogramma baricentro che ricevuto in ingresso un array di
valori interi e qualsiasi altro parametro ritenuto strettamente necessario
restituisce l’indice dell’elemento che fa da baricentro agli elementi
dell’array, -1 se non esiste. Definiamo baricentro di un array di h elementi,
l’elemento in posizione i tale per cui: `v[0] + v[1] + ... + v[i] = v[i + 1] +
v[i + 2] + ... + v[h - 1]` Se dovessero esserci più baricentri, il
sottoprogramma restituirebbe quello più a sinistra.
*/

#include <stdio.h>
#include <stdlib.h>

int baricentro(int, int[]);

int main(int argc, char** argv) {
  int n, *v, i;
  scanf("%d", &n);
  v = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  i = baricentro(n, v);
  free(v);
  printf("%d", i);
  return 0;
}

int baricentro(int n, int v[]) {
  int s, t, i;
  s = t = 0;
  for (i = 0; i < n; i++) s += v[i];
  for (i = 0; s != t && i < n; i++) {
    t += v[i];
    s -= v[i];
  }
  return (i == n ? -1 : i - 1);
}
