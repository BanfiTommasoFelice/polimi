/*
Scrivere un sottoprogramma mixarr in C (ANSI C) che, ricevuti come parametri tre
array, a1, a2 e a3, e qualsiasi altro parametro ritenuto strettamente
necessario, salva in a3 una copia dei valori contenuti in a1 ed a2 ordinandoli
in ordine crescente e senza ripetizioni e restituisce il numero di elementi
effettivamente scritti in a3. Nella realizzazione del sottoprogramma è
necessario tener conto dei seguenti aspetti:
+ il sottoprogramma può modificare i dati contenuti negli array di partenza;
+ si assuma che a3 abbia abbastanza spazio per memorizzare la sequenza
risultante. Nello sviluppo della soluzione realizzare un sottoprogramma sortarr
che ricevuti in ingresso un array, un intero updown e qualsiasi altro parametro
ritenuto strettamente necessario, ordina il contenuto dell’array in senso
crescente se updown vale 1, in senso decrescente se vale -1. In caso updown
contenga un valore diverso il sottoprogramma non effettua alcuna modifica.
Sviluppare infine un programma che chiede all’utente i dati per popolare due
array da 20 elementi, invoca il sottoprogramma sopra definito e visualizza il
risultato (la visualizzazione non viene fatta nel sottoprogramma mixarr).
*/

#define N 3

#include <stdio.h>

int mixarr(int[], int, int[], int, int[]);

int main(int argc, char** argv) {
  int n, v[N], w[N], z[N + N], i;
  for (i = 0; i < N; i++) scanf("%d", &v[i]);
  for (i = 0; i < N; i++) scanf("%d", &w[i]);
  n = mixarr(z, N, v, N, w);
  for (i = 0; i < n; i++) printf("%d ", z[i]);
  return 0;
}

void swap(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a  = *b;
  *b  = tmp;
}

void sort(int n, int v[], int o) {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if ((o == 1 && v[i] > v[j]) || (o == -1 && v[i] < v[j]))
        swap(&v[i], &v[j]);
}

int mixarr(int z[], int n, int v[], int m, int w[]) {
  int p, i, j;
  sort(n, v, 1);
  sort(m, w, 1);
  i = j = p = 0;
  while (i < n && j < m)
    if (v[i] < w[j])
      z[p++] = v[i++];
    else
      z[p++] = w[j++];
  while (i < n) z[p++] = v[i++];
  while (j < m) z[p++] = w[j++];
  for (i = 1, j = 0; i < p; i++)
    if (z[i] != z[j]) z[++j] = z[i];
  return j + !!p;
}
