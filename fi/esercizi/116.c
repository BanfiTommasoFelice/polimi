/*
Scrivere un sottoprogramma che ricevuta in ingresso una lista per la gestione
dei numeri interi la compatta, facendo in modo che alla fine la lista non
contenga valori replicati o nulli. Il programma chiamante dovrà ovviamente
accedere al termine dell’esecuzione del sottoprogramma, alla lista compattata.
*/

#define DISCARD 0

#include <list.h>
#include <stdio.h>

void compact(list_t *);
GET(int)

int main(int argc, char **argv) {
  int n, x;
  list_t *list;
  node_t *node;
  list = list_new();
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    list_push_back(list, &x, sizeof(int));
  }
  compact(list);
  for (node = list_head(list); node; node = node_next(node))
    printf("%d ", get_int(node));
  list_free(list);
  return 0;
}

void compact(list_t *list) {
  list_t *ausiliary;
  node_t *node;
  int x;
  ausiliary = list_new();
  for (node = list_head(list); node; node = node_next(node))
    if (!list_find(ausiliary, node->data, sizeof(int)))
      list_push_back(ausiliary, node->data, sizeof(int));
  list_clear(list);
  for (node = list_head(ausiliary); node; node = node_next(node)) {
    x = get_int(node);
    if (x != DISCARD) list_push_back(list, &x, sizeof(int));
  }
  list_free(ausiliary);
}