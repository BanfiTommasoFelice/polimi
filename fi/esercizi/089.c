/*
Scrivere un sottoprogramma ricorsivo che ricevuta in ingresso una stringa ed un
carattere, restituisce 1 se il carattere compare nella stringa, 0 altrimenti.
*/

#define MAXC 100

#include <stdio.h>

int rfind(char*, char);

int main(int argc, char** argv) {
  char s[MAXC + 1], c;
  int f;
  scanf("%s %c", s, &c);
  f = rfind(s, c);
  printf("%d", f);
  return 0;
}

int rfind(char* s, char c) {
  if (!*s) return 0;
  return (*s == c) || rfind(s + 1, c);
}
