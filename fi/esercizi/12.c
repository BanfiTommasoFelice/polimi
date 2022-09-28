/*
Si realizzi un programma in linguaggio C ANSI che chiede all’utente due numeri
in virgola mobile che rappresentano i parametri a e b di un'equazione di primo
grado ax + b = 0. Il programma calcola e visualizza la soluzione dell'equazione.
Inoltre, se l'equazione risulta impossibile, il programma restituisce il
carattere 'y', se indeterminata 'z'.
*/

#define POSSIBLE      'x'
#define IMPOSSIBLE    'y'
#define INDETERMINATE 'z'

#include <stdio.h>

int main(int argc, char** argv) {
  float a, b, x;
  char result;
  scanf("%f%f", &a, &b);
  if (a == 0 && b == 0)
    result = INDETERMINATE;
  else if (a == 0)
    result = IMPOSSIBLE;
  else {
    result = POSSIBLE;
    x      = -b / a;
  }
  if (result == POSSIBLE)
    printf("%f", x);
  else
    printf("%c", result);
  return 0;
}
