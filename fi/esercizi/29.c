/*
Si traduca in linguagggio C (ANSI 89) il diagramma di flusso seguente.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  int n, pre, cont, corr, tmp;
  do scanf("%d", &n);
  while (n < 0);
  pre  = 0;
  cont = 1;
  printf("%d\n", pre);
  if (cont < n) {
    corr = 1;
    cont++;
    printf("%d\n", corr);
    while (cont < n) {
      tmp = corr;
      corr += pre;
      pre = tmp;
      cont++;
      printf("%d\n", corr);
    }
  }
  return 0;
}
