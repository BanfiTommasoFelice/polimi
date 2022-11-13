/*
Scrivere un sottoprogramma check che ricevute due stringhe, tentativo e
soluzione, di ugual lunghezza (è senz’altro così) rappresentanti due vocaboli,
restituisce una stringa contenente: = se il carattere in posizione i di
tentativo è uguale al carattere in posizione i di soluzione,
+ se il carattere in posizione i di tentativo è uguale ad un carattere di
soluzione in posiziione j con j!=i, X se il carattere in posizione i di
tentativo non appartiene a soluzione.
*/

#define EQUAL  '='
#define IN     '+'
#define NOT_IN 'X'
#define COMBS  (1 << (8 * sizeof(char)))

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char*);
void check(char[], char[], char[]);

int main(int argc, char** argv) {
  int n;
  char* s;
  if (argc == 3) {
    n = strlen(argv[1]);
    assert(n == strlen(argv[2]));
    s = malloc((n + 1) * sizeof(char));
    check(argv[1], argv[2], s);
    printf("%s", s);
    free(s);
  } else
    usage(argv[0]);
  return (argc != 3);
}

void usage(char* p) { printf("usage: %s string string", p); }

int cmp(char* a, char* b) { return (*a) - (*b); }

void check(char a[], char b[], char c[]) {
  int i, n;
  char* s;
  n = strlen(a);
  s = malloc(n * sizeof(char));
  memcpy(s, b, n * sizeof(char));
  qsort(s, n, sizeof(char), cmp);
  for (i = 0; i < n; i++)
    if (a[i] == b[i])
      c[i] = EQUAL;
    else if (bsearch(&a[i], s, n, sizeof(char), cmp))
      c[i] = IN;
    else
      c[i] = NOT_IN;
  free(s);
  c[n] = 0;
}

void _check(char a[], char b[], char c[]) {
  int i;
  char* f;
  f = calloc(COMBS, sizeof(char));
  for (i = 0; b[i]; i++) f[b[i]] = 1;
  for (i = 0; a[i]; i++)
    if (a[i] == b[i])
      c[i] = EQUAL;
    else if (f[a[i]])
      c[i] = IN;
    else
      c[i] = NOT_IN;
  c[i] = 0;
  free(f);
}
