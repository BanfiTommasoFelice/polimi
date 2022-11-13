/*
Scrivere un programma in linguaggio C (ANSI 89) che legge una sequenza di numeri
interi strettamente positivi (sono senz’altro così) a priori di lunghezza
ignota, terminata dall’inserimento del valore 0. Il programma calcola e
visualizza la sottosequenza di numeri consecutivi in ordine strettamente
crescente di lunghezza massima.
*/

#define END 0

#include <stdio.h>

int main(int argc, char** argv) {
  int n, m, result, tmp;
  tmp = result = 0;
  scanf("%d", &n);
  if (n != END) {
    tmp++;
    do {
      scanf("%d", &m);
      if (m != END)
        if (m > n)
          tmp++;
        else if (tmp > result) {
          result = tmp;
          tmp    = 1;
        }
      n = m;
    } while (m != END);
    if (tmp > result) result = tmp;
  }
  printf("%d", result);
  return 0;
}
