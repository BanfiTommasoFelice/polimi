/*
Si realizzi un programma in linguaggio C ANSI che riceve in ingresso valore
intero e calcola e visualizza ‘+’ se il valore è positivo, ‘-’ se il valore è
negativo, ‘ ‘ (spazio) se è nullo.
*/

#define POSITIVE '+'
#define NEGATIVE '-'
#define ZERO     ' '

#include <stdio.h>

int main(int argc, char** argv) {
  int n;
  char result;
  scanf("%d%", &n);
  if (n > 0)
    result = POSITIVE;
  else if (n < 0)
    result = NEGATIVE;
  else
    result = ZERO;
  printf("%c", result);
  return 0;
}
