/*
Scrivere un sottoprogramma che ricevuto in ingresso un array e qualsiasi altro
parametro ritenuto strettamente necessario restituisca una lista contenente
tutti i numeri primi presenti nell’array.
*/

#include <err.h>
#include <list.h>
#include <stdio.h>
#include <stdlib.h>

int prime(int);
list_t *prime_list(int, int *);
GET(int)

int main(int argc, char **argv) {
  int n, *v, i;
  list_t *list;
  node_t *node;
  scanf("%d", &n);
  v = malloc(n * sizeof(int));
  if (!v) ERROR(v);
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  list = prime_list(n, v);
  for (node = list_head(list); node; node = node_next(node))
    printf("%d ", get_int(node));
  list_free(list);
  return 0;
}

/*
int prime(int n) {
  const int WHEEL[] = { 0, 4, 6, 10, 12, 16, 22, 24 };
  int p, u, i;
  p = (n < 6 ? n > 1 && n != 4 : (n % 2 && n % 3 && n % 5));
  for (u = 7; p && u * u <= n; u += 30)
    for (i = 0; p && i < sizeof(WHEEL) / sizeof(int); i++)
      p = (n % (u + WHEEL[i]));
  return p;
}
*/

int prime(int n) {
  int p, u;
  p = (n < 4 ? n > 1 : (n % 2 && n % 3));
  for (u = 5; p && u * u <= n; u += 6) p = (n % u && n % (u + 2));
  return p;
}

list_t *prime_list(int n, int *v) {
  int i;
  list_t *list;
  list = list_new();
  for (i = 0; i < n; i++)
    if (prime(v[i])) list_push_back(list, &v[i], sizeof(int));
  return list;
}