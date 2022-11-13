/*
Si scriva un sottoprogramma in linguaggio C (ANSI 89) che riceve in ingresso un
valore intero e restituisce 1 nel caso sia un valore primo, 0 altrimenti.
*/

#include <stdio.h>

int prime(int);

int main(int argc, char** argv) { return 0; }

int prime(int n) {
  int p, i;
  p = (n < 4 ? n > 1 : (n % 2 && n % 3));
  for (i = 5; p && i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) p = 0;
  return p;
}
