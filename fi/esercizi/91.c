/*
Scrivere un programma che acquisito da riga di comando una sequenza di caratteri
ed un carattere calcola e visualizza il numero di volte che il carattere compare
nella sequenza avvalendosi di un sottoprogramma ricorsivo (passaggio da stringa
a carattere).
*/

#include <stdio.h>
#include <stdlib.h>

void usage(char*);
int rcount(char*, char);

int main(int argc, char** argv) {
  char *s, c;
  int cnt;
  if (argc == 3) {
    s   = argv[1];
    c   = argv[2][0];
    cnt = rcount(s, c);
    printf("%d", cnt);
  } else
    usage(argv[0]);
  return (argc != 3);
}

void usage(char* p) { printf("usage: %s string char\n", p); }

int rcount(char* s, char c) {
  if (!*s) return 0;
  return (*s == c) + rcount(s + 1, c);
}
