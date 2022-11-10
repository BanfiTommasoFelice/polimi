/*
Scrivere un programma che acquisisce un valore intero strettamente positivo, e
finché non è tale lo richiede. Il programma analizza il valore intero e
visualizza 1 nel caso sia un `troncabile primo a destra`, 0 altrimenti. Un
numero si dice troncabile primo a destra se il numero stesso e tutti i numeri
che si ottengono eliminando una alla volta la cifra meno significativa del
numero analizzato al passo precedente, sono numeri primi. Per esempio, se il
numero iniziale è 719, i numeri che si ottengono “eliminando una alla volta la
cifra meno significativa del numero analizzato al passo precedente ..” sono 71
e 7. Dopo il valore visualizzato, mettere un `’a-capo’`.
*/

#define INT_MAX 0x7fffffff
#define BASE    10

#include <stdio.h>

void scan(int*, int, int);
int prime(int);

int main(int argc, char** argv) {
  int n, t;
  scan(&n, 0, INT_MAX);
  t = prime(n);
  while (t && (n /= BASE)) t = prime(n);
  printf("%d\n", t);
  return 0;
}

void scan(int* n, int min, int max) {
  do scanf("%d", n);
  while (*n < min || *n > max);
}

int prime(int n) {
  int p, i;
  p = (n < 4 ? n > 1 : (n % 2 && n % 3));
  for (i = 5; i * i <= n; i += 6) p = (n % i && n % (i + 2));
  return p;
}
