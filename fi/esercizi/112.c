/*
Scrivere un programma che chiede all’utente un valore intero che indica il
termine della sequenza dati *e non ne fa parte*, quindi acquisisce una sequenza
di valori interi a priori di lunghezza ignota, che termina quando l’utente
inserisce il valore indicato. Il programma visualizza tutti e soli i valori
sopra il valore medio.
*/

#include <list.h>
#include <stdio.h>

GET(int)

int main(int argc, char **argv) {
  int n, stop, sum;
  list_t *list;
  node_t *node;
  scanf("%d", &stop);
  list = list_new();
  sum  = 0;
  while (scanf("%d", &n) && n != stop) {
    list_push_back(list, &n, sizeof(int));
    sum += n;
  }
  stop = list_size(list);
  node = list_head(list);
  while (node) {
    n = get_int(node);
    if (n * stop > sum) printf("%d ", n);
    node = node_next(node);
  }
  list_free(list);
  return 0;
}
