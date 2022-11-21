/*
Si scriva un sottoprogramma soloconsonanti che ricevuta in ingresso una stringa
ne crea una nuova contenente solo le consonanti della stringa iniziale e la
restituisce al chiamante.
Scrivere un programma che acquisisce da riga di comando una stringa e
avvalendosi del sottoprogramma soloconsonanti ne estrae le sole consonanti
ordinate e le visualizza.
*/

#define ISVOWEL(x) \
  ((x) == 'a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u')

#include <ctype.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char*);
char* only_consonants(char*);

int main(int argc, char** argv) {
  char* s;
  if (argc == 2) {
    s = only_consonants(argv[1]);
    printf("%s", s);
    free(s);
  } else
    usage(argv[0]);
  return (argc != 2);
}

void usage(char* p) { printf("usage: %s string\n", p); }

char* only_consonants(char* s) {
  int n, i;
  char* t;
  n = 1;
  for (i = 0; s[i]; i++)
    if (isalpha(s[i]) && !ISVOWEL(tolower(s[i]))) n++;
  t = malloc(n * sizeof(char));
  if (t) {
    n = 0;
    for (i = 0; s[i]; i++)
      if (isalpha(s[i]) && !ISVOWEL(tolower(s[i]))) t[n++] = s[i];
    t[n] = 0;
  } else
    ERROR(t);
  return t;
}
