/*
Si realizzi un programma in linguaggio C ANSI che riceve in ingresso un numero
reale positivo (è senz'altro così) e calcola e visualizza il valore intero
arrotondato per difetto. Nota: riflettere sull'algoritmo per l'arrotondamento
per eccesso, e su quello per l'arrotondamento per difetto se la frazione è
inferiore a 0.50, per eccesso se non inferiore.
*/

#include "stdio.h"

int main(int argc, char **argv) {
  double x;
  unsigned y;
  scanf("%lf", &x);
  y = (unsigned)x;
  printf("%u", y);
  return 0;
}
