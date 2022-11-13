/*
Si realizzi un programma in linguaggio C ANSI che acquisito un numero intero
visualizzi 1 se è pari, 0 se è dispari.
*/

#define EVEN '1'
#define ODD  '0'

#include <stdio.h>

int main(int argc, char** argv) {
  int n;
  char result;
  scanf("%d", &n);
  if (n % 2)
    result = ODD;
  else
    result = EVEN;
  printf("%c", result);
  return 0;
}
