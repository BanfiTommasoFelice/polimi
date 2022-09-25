/*
Si realizzi un programma in linguaggio C ANSI che riceve in ingresso tre numeri
interi positivi (è senz'altro così) `a`, `l` e `lato` che rappresentano
rispettivamente l'altezza (`a`) e la larghezza (`l`) di un pavimento, e il lato
di una piatrella quadrata (`lato`) con cui ricoprirlo. Il programma calcola e
visualizza il numero di piastrelle *intere* che dovranno essere utilizzate per
ricoprire il pavimento.
*/

#include "stdio.h"

int main(int argc, char **argv) {
  unsigned a, l, lato, x, y, result;
  scanf("%u%u%u", &a, &l, &lato);
  x      = a / lato;
  y      = l / lato;
  result = x * y;
  printf("%u", result);
  return 0;
}
