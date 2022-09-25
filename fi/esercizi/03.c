/*
Si realizzi un programma in linguaggio C ANSI che acquisisce un valore reale e
ne visualizza la parte decimale.
*/

#include "stdio.h"

int main(int argc, char **argv) {
  double x, y;
  scanf("%lf", &x);
  y = x - (double)((int)x);
  printf("%f", y);
  return 0;
}
