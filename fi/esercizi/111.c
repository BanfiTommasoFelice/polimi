/*
Scrivere un sottoprogramma crop che ricevuta in ingresso una stringa frase ed un
carattere ch restituisce una nuova stringa che contiene i caratteri compresi tra
la prima e la seconda occorrenza del carattere ch, incluso il carattere ch. Nel
caso in cui la stringa frase non contenga due occorrenze del carattere ch,
restituisce NULL.
*/

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char *);
char *crop(char *, char);

int main(int argc, char **argv) {
  char *s;
  if (argc != 3)
    usage(argv[0]);
  else {
    s = crop(argv[1], argv[2][0]);
    if (s) printf("%s", s);
    free(s);
  }
  return (argc != 3);
}

void usage(char *p) { printf("usage: %s string char\n", p); }

char *crop(char *s, char c) {
  int i, j, k;
  char *r;
  for (i = 0; s[i] && s[i] != c; i++) {}
  if (s[i])
    for (j = i + 1; s[j] && s[j] != c; j++) {}
  else
    j = i;
  if (s[i] && s[j]) {
    r = malloc((j - i + 2) * sizeof(char));
    if (!r) ERROR(r);
    for (k = i; k <= j; k++) r[k - i] = s[k];
    r[k - i] = 0;
  } else
    r = NULL;
  return r;
}