/*
Si realizzi un programma in linguaggio C ANSI che acquisisce un valore intero
positivo (è senz'altro così) che rappresenta il raggio di una circonferenza e
calcola e visualizza il perimetro e l'area.
*/

#include "math.h"
#include "stdio.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(int argc, char **argv) {
  unsigned int r;
  double p, a;
  scanf("%u", &r);
  p = 2 * M_PI * r;
  a = M_PI * r * r;
  printf("%f %f", p, a);
  return 0;
}
