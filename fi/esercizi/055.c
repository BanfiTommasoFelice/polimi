/*
Si traduca in linguaggio C (ANSI 89) il diagramma di flusso seguente.
*/

#define MAXN 50
#define STOP 0

#include <stdio.h>

int main(int argc, char** argv) {
  int d, v[MAXN], i, senzaprimi, primo, n, meta, div;
  d = 0;
  scanf("%d", &n);
  while (n != STOP) {
    v[d++] = n;
    scanf("%d", &n);
  }
  senzaprimi = 1;
  i          = 0;
  while (senzaprimi && i < d) {
    primo = 1;
    if (v[i] != 2) {
      if (v[i] == 1 || v[i] % 2 == 0) {
        primo = 0;
      } else {
        meta = v[i] / 2;
        div  = 3;
        while (primo && div < meta) {
          if (v[i] % div == 0) primo = 0;
          div += 2;
        }
      }
    }
    senzaprimi = primo;
  }
  printf("%d", senzaprimi);
  return 0;
}
