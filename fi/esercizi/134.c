/*
Scrivere un sottoprogramma distanzalineare che riceve in ingresso le seguenti
informazioni:
+ start: il primo valore (valore reale)
+ stop: l’ultimo valore (valore reale)
+ numero: il numero di valori da distribuire nell’intervallo [start; stop]
(valore intero)
+ escludistop: 1 se si vuole escludere il valore stop, ossia se i valori devono
coprire l’intervallo [start; stop), 0 altrimenti
+ valoricalcolati: array in cui salvare i dati calcolati.
Il sottoprogramma calcola e trasmette al chiamante (usando l’array
valoricalcolati, che è stato opportunamente dimensionato) l’insieme di numeri
uniformemente distribuiti nell’intervallo [start; stop] (oppure [start; stop)).
*/

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

void distribute(float, float, int, int, float *);

int main(int argc, char **argv) {
  float start, stop, *distribution;
  int n, open, i;
  scanf("%f%f%d%d", &start, &stop, &n, &open);
  distribution = malloc(n * sizeof(float));
  if (!distribution) ERROR(distribution);
  distribute(start, stop, n, open, distribution);
  for (i = 0; i < n; i++) printf("%g ", distribution[i]);
  free(distribution);
  return 0;
}

void distribute(float start, float stop, int n, int open, float *values) {
  float step;
  int i;
  step = (stop - start) / (open ? n : n - 1);
  for (i = 0; i < n; i++) values[i] = start + i * step;
}