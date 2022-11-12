/*
Si scriva un sottoprogramma rimuoviDuplicati che ricevuto in ingresso un array
di valori interi (e qualsiasi altro parametro ritenuto strettamente necessario),
trasmetta al chiamante un array contente i valori dell’array in ingresso privo
di duplicati. Prestare attenzione alle informazioni che il sottoprogramma ed il
chiamante si devono scambiare. Realizzare poi un programma che acquisiti al
massimo 50 valori interi strettamente positivi (l’acquisizione termina quando
l’utente inserisce un valore negativo o nullo) chiami il sottoprogramma e poi
visualizzi i valori privi di ripetizioni.
*/

#define MAXN 50

#include <stdio.h>

int unique(int, int[], int[]);

int main(int argc, char** argv) {
  int n, m, v[MAXN], w[MAXN];
  n = 0;
  do scanf("%d", &v[n]);
  while (n < MAXN && v[n++] > 0);
  if (n < MAXN && v[n] <= 0) n--;
  m = unique(n, v, w);
  for (n = 0; n < m; n++) printf("%d ", w[n]);
  return 0;
}

int unique(int n, int v[], int w[]) {
  int m, i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m && w[j] != v[i]; j++) {}
    if (j == m) w[m++] = v[i];
  }
  return m;
}
