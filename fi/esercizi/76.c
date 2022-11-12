/*
Scrivere un sottoprogramma che ricevuto in ingresso un valore intero restituisce
al chiamante il numero di cifre che compaiono più di una volta. Per esempio, se
il sottoprogramma riceve in ingresso il valore 3282821 il sottoprogramma
restituisce il valore 2, perché la cifra 8 e 2 compaiono entrambe più di una
volta.
*/

#define BASE 10

#include <stdio.h>

int f(int);

int main(int argc, char** argv) {
  int n;
  scanf("%d", &n);
  n = f(n);
  printf("%d", n);
  return 0;
}

int f(int n) {
  int o[BASE], i, c;
  for (i = 0; i < BASE; i++) o[i] = 0;
  while (n) {
    o[n % BASE]++;
    n /= BASE;
  }
  c = 0;
  for (i = 0; i < BASE; i++)
    if (o[i] > 1) c++;
  return c;
}
