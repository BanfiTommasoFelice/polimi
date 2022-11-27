/*
Si scriva un sottoprogramma che ricevuti in ingresso 2 insiemi di caratteri
rappresentati con delle stringhe restituisca al chiamante l’insieme di caratteri
(anche esso rappresentato come una stringa) intersezione dei due insiemi in
ingresso. Il risultato conterrà tutti e i soli caratteri presenti in entrambe le
stringhe, una sola volta. Si assuma che negli insiemi di ingresso ogni carattere
sia presente al più una volta e che gli insiemi possano contenere solo caratteri
minuscoli.
*/

#define N 26

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char*);
char* intersection(char*, char*);

int main(int argc, char** argv) {
  char* s;
  if (argc == 3) {
    s = intersection(argv[1], argv[2]);
    printf("%s", s);
    free(s);
  } else
    usage(argv[0]);
  return (argc != 3);
}

void usage(char* p) { printf("usage: %s string string\n", p); }

char* intersection(char* a, char* b) {
  int o[N], i, n;
  char* s;
  for (i = 0; i < N; i++) o[i] = 0;
  for (i = 0; a[i]; i++) o[a[i] - 'a'] = -1;
  for (i = 0; b[i]; i++) o[b[i] - 'a'] *= -1;
  n = 1;
  for (i = 0; i < N; i++)
    if (o[i] > 0) n++;
  s = malloc(n * sizeof(char));
  if (s) {
    n = 0;
    for (i = 0; i < N; i++)
      if (o[i] > 0) s[n++] = i + 'a';
    s[n] = 0;
  } else
    ERROR(s);
  return s;
}
