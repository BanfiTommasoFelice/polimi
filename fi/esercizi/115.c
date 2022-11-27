/*
Scrivere un programma che acquisisca una sequenza di valori a priori di
lunghezza indeterminata e che termina con l’inserimento del valore 0 che non
appartiene ai dati e visualizza i valori in ordine inverso.
*/

#define STOP 0

#include <list.h>
#include <stdio.h>

GET(int)

int main(int argc, char **argv) {
  int n;
  list_t *list;
  node_t *node;
  list = list_new();
  while (scanf("%d", &n) && n != STOP) list_push_front(list, &n, sizeof(int));
  for (node = list_head(list); node; node = node_next(node))
    printf("%d ", get_int(node));
  list_free(list);
  return 0;
}
