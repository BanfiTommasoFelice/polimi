/*
Scrivere un sottoprogramma rep che riceve in ingresso una stringa s e un intero
n (senz’altro non negativo). Il sottoprogramma restituisce una nuova stringa
ottenuta concatenando n copie di s. Non è consentito l’uso dei sottoprogrammi di
libreria quali strcat, strcpy e simili. Scrivere il programma che acquisisce da
riga di comando la stringa s e l’intero n, invoca il sottoprogramma sopra
definito e visualizza il risultato.
*/

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char*);
char* strmul(char[], int);

int main(int argc, char** argv) {
  char* s;
  int n;
  if (argc == 3) {
    n = atoi(argv[2]);
    s = strmul(argv[1], n);
    printf("%s", s);
    free(s);
  } else
    usage(argv[0]);
  return (argc != 3);
}

void usage(char* p) { printf("usage: %s string int\n", p); }

char* strmul(char s[], int k) {
  int n, i;
  char* m;
  n = 0;
  while (s[n]) n++;
  m = malloc((n * k + 1) * sizeof(char));
  if (m) {
    for (i = 0; i < n * k; i++) m[i] = s[i % n];
    m[i] = 0;
  } else
    ERROR(m);
  return m;
}
