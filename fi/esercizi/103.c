/*
Si scriva un programma che chiede all’utente il numero di dati (valori interi)
che intende fornire (nel caso l’utente inserisca un valore inferiore a 1 lo
richiede), quindi li acquisisce, li ordina in senso crescente e li visualizza.
*/

#define MINN 1

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void*, const void*);

int main(int argc, char** argv) {
  int n, *v, i;
  do scanf("%d", &n);
  while (n < MINN);
  v = malloc(n * sizeof(int));
  if (v) {
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    qsort(v, n, sizeof(int), cmp);
    for (i = 0; i < n; i++) printf("%d ", v[i]);
  } else
    ERROR(v);
  free(v);
  return 0;
}

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }
