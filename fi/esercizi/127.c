/*
Scrivere un sottoprogramma che ricevute in ingresso due liste ne restituisce una
nuova creata alternando gli elementi delle due liste, e poi mettendo in coda
tutti quelli della lista più lunga.
*/

#include <list.h>
#include <stdio.h>

GET(int)
GET_PTR(int)
list_t *merge(list_t *, list_t *);

int main(int argc, char **argv) {
  list_t *a, *b, *c;
  node_t *node;
  int x;
  a = list_new();
  b = list_new();
  while (scanf("%d", &x) && x) list_push_back(a, &x, sizeof(int));
  while (scanf("%d", &x) && x) list_push_back(b, &x, sizeof(int));
  c = merge(a, b);
  for (node = list_head(c); node; node = node_next(node))
    printf("%d ", get_int(node));
  list_free(a);
  list_free(b);
  list_free(c);
  return 0;
}

list_t *merge(list_t *a, list_t *b) {
  list_t *c = list_new();
  node_t *x, *y;
  x = list_head(a);
  y = list_head(b);
  while (x && y) {
    list_push_back(c, get_int_ptr(x), sizeof(int));
    list_push_back(c, get_int_ptr(y), sizeof(int));
    x = node_next(x);
    y = node_next(y);
  }
  while (x) {
    list_push_back(c, get_int_ptr(x), sizeof(int));
    x = node_next(x);
  }
  while (y) {
    list_push_back(c, get_int_ptr(y), sizeof(int));
    y = node_next(y);
  }
  return c;
}