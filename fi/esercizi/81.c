/*
Scrivere un programma che ricevuto in ingresso un numero intero `n` visualizza
l’intero positivo piu piccolo che sia un multiplo di `n` e sia costituito solo
dalle cifre 0 e 9.
*/

#define BASE     10
#define VALID(x) (x == 0 || x == 9)

#include <stdio.h>

int check(int);

int main(int argc, char** argv) {
  int n, m;
  scanf("%d", &n);
  m = n;
  while (!check(m)) m += n;
  printf("%d", m);
  return 0;
}

int check(int n) {
  int o;
  o = 1;
  while (o && n) {
    o = n % 10;
    o = VALID(o);
    n /= 10;
  }
  return o;
}
