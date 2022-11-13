/*
Scrivere un programma che acquisito da riga di comando un valore intero
strettamente positivo calcola e visualizza il suo fattoriale avvalendosi di un
sottoprogramma ricorsivo (uso di atoi).
*/

#include <stdio.h>
#include <stdlib.h>

void usage(char*);
int rfactorial(int);

int main(int argc, char** argv) {
  int n, f;
  if (argc == 2) {
    n = atoi(argv[1]);
    f = rfactorial(n);
    printf("%d", f);
  } else
    usage(argv[0]);
  return (argc != 2);
}

void usage(char* p) { printf("usage: %s int\n", p); }

int rfactorial(int n) {
  if (n < 2) return 1;
  return n * rfactorial(n - 1);
}
