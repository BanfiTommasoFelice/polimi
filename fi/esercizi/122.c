/*
Scrivere un sottoprogramma in C (ANSI 89) che riceve in ingresso il nome di un
file binario e un array di interi e lo popola con i valori letti dal file. Il
file contiene un primo valore intero n che rappresenta il numero di valori
successivamente presenti nel file. Il sottoprogramma restituisce il numero di
valori letti. L’array è senz’altro dimensionato in modo tale da contenere i dati
presenti nel file.
*/

#define MAXN 1024

#include <limits.h>
#include <stdio.h>

size_t ffill(const char *, int *);

int main(int argc, char **argv) {
  char filename[NAME_MAX + 1];
  int v[MAXN];
  size_t n, i;
  scanf("%s", filename);
  n = ffill(filename, v);
  for (i = 0; i < n; i++) printf("%d ", v[i]);
  return 0;
}

size_t ffill(const char *filename, int *array) {
  FILE *file;
  size_t n;
  if ((file = fopen(filename, "rb"))) {
    fread(&n, sizeof(size_t), 1, file);
    fread(array, sizeof(int), n, file);
    fclose(file);
  } else
    fprintf(stderr, "file not found.\n");
  return n;
}