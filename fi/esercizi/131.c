/*
Scrivere un programma che riceve in ingresso da riga di comando due nomi di file
binari. Il primo file contiene solo valori interi: il primo valore è il numero
totale di ulteriori dati presenti nel file. Il programma scrive nel secondo file
i valori presenti nel primo file, in ordine inverso, sempre preceduti dal numero
totale di valori.
*/

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char *);
void swap(int *, int *);
void reverse(FILE *, FILE *);

int main(int argc, char **argv) {
  FILE *fsrc, *fdst;
  if (argc == 3) {
    fsrc = fopen(argv[1], "r");
    fdst = fopen(argv[2], "w");
    if (!fsrc) ERROR(fsrc);
    if (!fdst) ERROR(fdst);
    reverse(fsrc, fdst);
    fclose(fsrc);
    fclose(fdst);
  } else
    usage(argv[0]);
  return (argc != 3);
}

void usage(char *p) { printf("usage: %s input output\n", p); }

void swap(int *a, int *b) {
  int t = *a;
  *a    = *b;
  *b    = t;
}

void reverse(FILE *fsrc, FILE *fdst) {
  int n, *v, i, j;
  fread(&n, sizeof(int), 1, fsrc);
  fwrite(&n, sizeof(int), 1, fdst);
  v = malloc(n * sizeof(int));
  fread(v, sizeof(int), n, fsrc);
  for (i = 0, j = n - 1; i < j; i++, j--) swap(&v[i], &v[j]);
  fwrite(v, sizeof(int), n, fdst);
  free(v);
}