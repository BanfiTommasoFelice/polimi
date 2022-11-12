/*
Scrivere un sottoprogramma che riceve in ingresso un array di valori interi `v`
e qualsiasi altro parametro ritenuto necessario, ed altri due valori interi `da`
e `a`. Il sottoprogramma verifica se nell’array sono presenti tutti e soli i
valori inclusi nell’intervallo `[da,a]`, senza ripetizioni. In caso positivo il
sottoprogramma restituisce 1, 0 in caso contrario.
*/

#include <stdio.h>
#include <stdlib.h>

int check(int, int[], int, int);

int main(int argc, char** argv) {
  int n, *v, from, to;
  scanf("%d", &n);
  v = malloc(n * sizeof(int));
  for (to = 0; to < n; to++) scanf("%d", &v[to]);
  scanf("%d%d", &from, &to);
  n = check(n, v, from, to);
  printf("%d", n);
  return 0;
}

int check(int n, int v[], int from, int to) {
  int c, i;
  c = 1;
  for (i = 0; c && i < n; i++) c = (from <= v[i] && v[i] <= to);
  return c;
}
