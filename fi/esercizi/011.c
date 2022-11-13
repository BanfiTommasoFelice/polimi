/*
Si realizzi un programma in linguaggio C ANSI per inserire il prezzo di costo e
il prezzo di vendita di un prodotto e verificarne il profitto o la perdita. Il
programma deve restituire insieme al margine ottenuto, in valore assoluto, il
carattere '+' nel caso di profitto, '-' in caso di perdita totale o il carattere
'x' se non si abbia né profitto né perdita.
*/

#define PROFIT '+'
#define LOSS   '-'
#define EVEN   'x'

#include <stdio.h>

int main(int argc, char** argv) {
  float cost, price, margin;
  char result;
  scanf("%f%f", &cost, &price);
  margin = price - cost;
  if (margin < 0) {
    result = LOSS;
    margin *= -1;
  } else if (margin > 0)
    result = PROFIT;
  else
    result = EVEN;
  printf("%c%f", result, margin);
  return 0;
}
