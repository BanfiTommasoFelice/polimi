/*
Scrivere un programma in C (ANSI 89) che acquisisce una sequenza di al più 100
interi chiedendo per prima cosa all’utente quanti valori intenda inserire e
verificando che la quantità non superi il vincolo, altrimenti viene chiesta
nuovamente. Il programma calcola il valore più frequente e la sequenza di valori
privata del valore più frequente, preceduta dalla lunghezza di tale sequenza
risultante. A parità di numero di occorrenze si consideri l’intero più piccolo.
*/

#define MAXN 100

#include <stdio.h>

typedef struct {
  int x, c;
} node_t;

int main(int argc, char** argv) {
  int n, m, v[MAXN], r[MAXN], i, j;
  node_t g[MAXN];
  do scanf("%d", &n);
  while (n > MAXN || n < 1);
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  m = 0;
  for (i = 0; i < n; i++) {
    j = 0;
    while (j < m && g[j].x != v[i]) j++;
    if (j == m)
      g[m++] = (node_t){ v[i], 1 };
    else
      g[j].c++;
  }
  j = 0;
  for (i = 1; i < m; i++)
    if (g[i].c > g[j].c)
      j = i;
    else if (g[i].c == g[j].c && g[i].x < g[j].x)
      j = i;
  m = 0;
  for (i = 0; i < n; i++)
    if (v[i] != g[j].x) r[m++] = v[i];
  printf("%d\n", m);
  for (i = 0; i < m; i++) printf("%d ", r[i]);
  return 0;
}
