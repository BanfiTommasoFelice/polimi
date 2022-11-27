/*
Scrivere un sottoprogramma ricorsivo che riceve come parametri un array di
interi ordinati in ordine crescente (e la sua dimensione) ed un numero n. Il
sottoprogramma verifica se n è contenuto nell’array utilizzando il metodo della
bisezione. In caso affermativo restituisce 1 altrimenti 0. Scrivere un programma
che chiede all’utente 10 valori interi, invoca il sottoprogramma definito e
visualizza il risultato.
*/

#define N 10

#include <stdio.h>

int find(int, int*, int);

int main(int argc, char** argv) {
  int v[N], i, n;
  for (i = 0; i < N; i++) scanf("%d", &v[i]);
  scanf("%d", &n);
  i = find(N, v, n);
  printf("%d", i);
  return 0;
}

int find(int n, int* v, int k) {
  int m, f;
  if (!n) return 0;
  f = (v[0] == k);
  m = (n - 1) / 2;
  f |= (v[m] == k);
  if (!f) {
    if (v[m] < k)
      f = find(m + !(n % 2), v + m + 1, k);
    else
      f = find(m, v, k);
  }
  return f;
}
