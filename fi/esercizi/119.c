/*
Scrivere un sottoprogramma che riceve come parametri una lista dinamica di
interi ordinata in ordine crescente ed un valore intero. Il sottoprogramma
inserisce il nuovo elemento nella lista preservando l’ordine crescente e
restituisce la testa della lista al chiamante. Realizzare sia la versione
iterativa che ricorsiva del sottoprogramma.
*/

#include <list.h>
#include <stdio.h>

void list_insert_sorted(list_t *, int);
GET(int)

int main(int argc, char **argv) {
  int x;
  list_t *list;
  node_t *node;
  list = list_new();
  while (scanf("%d", &x) && x > 0) list_push_back(list, &x, sizeof(int));
  scanf("%d", &x);
  list_insert_sorted(list, x);
  for (node = list_head(list); node; node = node_next(node))
    printf("%d ", get_int(node));
  list_free(list);
  return 0;
}

void list_insert_sorted(list_t *list, int x) {
  node_t *node;
  node = list_lower_bound(list, &x, sizeof(int));
  list_insert_after(list, node, &x, sizeof(int));
}
