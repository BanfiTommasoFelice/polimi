/*
Scrivere un programma che acquisisce in ingresso una stringa di al più 100
caratteri e calcola e visualizza 1 se si tratta di una palindrome, 0 altrimenti.
*/

#define MAXC 100

#include <stdio.h>

int main(int argc, char** argv) {
  char s[MAXC + 1];
  int p, i, l;
  gets(s);
  l = 0;
  p = 1;
  while (s[++l]) {}
  for (i = 0; p && i < l / 2; i++)
    if (s[i] != s[l - i - 1]) p = 0;
  printf("%d", p);
  return 0;
}
