/*
Si scriva un sottoprogramma ricorsivo che ricevuta in ingresso un valore intero
calcola e restituisce il suo fattoriale.
*/

#include <stdio.h>

int rfactorial(int);

int main(int argc, char** argv) {
  int n, f;
  scanf("%d", &n);
  f = rfactorial(n);
  printf("%d", f);
  return 0;
}

int rfactorial(int n) {
  if (n < 2) return 1;
  return n * rfactorial(n - 1);
}
