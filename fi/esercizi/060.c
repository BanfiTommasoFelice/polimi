/*
Si vuole rappresentare a video un valore naturale `num` utilizzando un numero a
scelta di cifre `k` inserendo `0` nelle posizioni più significative, fino a
raggiungere la dimensione desiderata. Per esempio, volendo rappresentare `842`
su `5` cifre, si ottiene `00842`. Scrivere un programma che acquisisce due
valori interi entrambi strettamente positivi (e finché non è così richiede il
valore che non rispetta il vincolo) `num` e `k`, quindi rappresenta `num` su `k`
cifre. Se `k` è minore del numero di cifre presenti in `num`, il programma
visualizza il valore `num` come è. Dopo il valore visualizzato, mettere un
`’a-capo’`.
*/

#define INT_MAX 0x7fffffff
#define BASE    10

#include <stdio.h>

void scan(int*, int, int);
int length(int, int);

int main(int argc, char** argv) {
  int n, d, l;
  scan(&n, 0, INT_MAX);
  scan(&d, 0, INT_MAX);
  l = length(n, BASE);
  while (d-- > l) printf("0");
  printf("%d", n);
  return 0;
}

void scan(int* n, int min, int max) {
  do scanf("%d", n);
  while (*n < min || *n > max);
}

int length(int n, int base) {
  int l;
  l = 1;
  while (n /= base) l++;
  return l;
}
