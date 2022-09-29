/*
Scrivere un programma in linguaggio C ANSI che acquisisce un numero intero e
verifica e visualizza se questo sia un cubo perfetto. Nel caso sia un cubo
perfetto visualizza 1 seguito (dopo lo spazio) dalla radice del cubo, altrimenti
visualizza 0 seguito da un numero intero che verrà ignorato.
*/

#define EPS 1e-6

#include <stdio.h>

int main(int argc, char** argv) {
  int n, d;
  float x, y;
  scanf("%d", &n);
  d = n % 9;
  if (d < 2 || d > 7) {
    x = 0;
    y = 1; /* valore qualsiasi */
    do {   /* metodo di Newton */
      x = y;
      y = x - (x * x * x - n) / (3.0 * x * x);
      /* printf("%11.3f\t%.8f\n", y, y - x); */
    } while (y - x > EPS || x - y > EPS);
    if (y - (int)y > EPS)
      printf("0 0");
    else
      printf("1 %d", (int)y);
  } else {
    printf("0 0");
  }
  return 0;
}
