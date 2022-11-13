/*
Si scriva un sottoprogramma ricorsivo che ricevuta in ingresso una stringa conta
e restituisce al chiamante la sua lunghezza.
*/

#define MAXC 100

#include <stdio.h>

int rstrlen(char*);

int main(int argc, char** argv) {
  char s[MAXC + 1];
  int l;
  scanf("%s", s);
  l = rstrlen(s);
  printf("%d", l);
  return 0;
}

int rstrlen(char* s) {
  if (!*s) return 0;
  return 1 + rstrlen(s + 1);
}
