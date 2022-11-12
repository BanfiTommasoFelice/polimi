/*
Scrivere un sottoprogramma ricorsivo che ricevuta in ingresso una stringa ed un
carattere, calcola e restituisce il numero di volte che il carattere compare
nella stringa.
*/

#define MAXC 100

#include <stdio.h>

int rcount(char*, char);

int main(int argc, char** argv) {
  char s[MAXC + 1], c;
  int cnt;
  scanf("%s %c", s, &c);
  cnt = rcount(s, c);
  printf("%d", cnt);
  return 0;
}

int rcount(char* s, char c) {
  if (!*s) return 0;
  return (*s == c) + rcount(s + 1, c);
}
