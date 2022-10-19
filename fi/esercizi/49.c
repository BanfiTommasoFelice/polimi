/*
Si scriva un programma in linguaggio C (ANSI 89) che acquisisce il prezzo di
massimo 50 prodotti, espresso mediante un valore reale, che termina quando
l’utente inserisce un valore non positivo (nel caso di 50 prodotti, verrebbe
fornito come 51 prezzo). Il programma acquisisce quindi la quantità di denaro
disponibile. Il programma calcola e visualizza il numero massimo di prodotti
acquistabili (si vuole massimizzare la quantità di prodotti).
*/

#define MAXN 50

#include <stdio.h>

int main(int argc, char** argv) {
  int n, r, i, j, g;
  float p[MAXN], t, tmp;
  n = 0;
  while (scanf("%f", &p[n]) && p[n] > 0) n++;
  scanf("%f", &t);
  r = 0;
  g = 1;
  for (i = 0; g && i < n; i++) {
    for (j = i + 1; j < n; j++)
      if (p[i] > p[j]) {
        tmp  = p[i];
        p[i] = p[j];
        p[j] = tmp;
      }
    if (t >= p[i]) {
      r++;
      t -= p[i];
    } else
      g = 0;
  }
  printf("%d", r);
  return 0;
}
