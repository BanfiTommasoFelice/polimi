/*
Scrivere un sottoprogramma che riceve una lista dinamica di numeri l1 e da
questa costruisce una nuova lista l2 come segue: gli elementi di l1 vengono
presi a coppie e viene inserito prima il secondo elemento della coppia e poi il
primo. Nel caso la lista l1 contenga un numero dispari di elementi, l’ultimo
elemento viene copiato alla fine di l2.
*/

#include <list.h>
#include <stdio.h>

list_t *f(list_t *);
GET(int)
GET_PTR(int)

int main(int argc, char **argv) {
  int x;
  list_t *a, *b;
  node_t *node;
  a = list_new();
  while (scanf("%d", &x) && x > 0) list_push_back(a, &x, sizeof(int));
  b = f(a);
  for (node = list_head(b); node; node = node_next(node))
    printf("%d ", get_int(node));
  list_free(a);
  list_free(b);
  return 0;
}

list_t *f(list_t *in) {
  list_t *out;
  node_t *node;
  out = list_new();
  for (node = list_head(in); node && node->next; node = node->next->next) {
    list_push_back(out, get_int_ptr(node->next), sizeof(int));
    list_push_back(out, get_int_ptr(node), sizeof(int));
  }
  if (node) list_push_back(out, get_int_ptr(node), sizeof(int));
  return out;
}