/*
Scrivere un programma in C (ANSI 89) che chiede all’utente il nome di un file
(stringa di al più 40 caratteri) di testo. Il programma conta e visualizza il
numero di caratteri in esso presenti ed anche il carattere con il codice ASCII
più grande trovato.
*/

#define NAME_MAX 40

#include <stdio.h>

int max(int, int);

int main(int argc, char **argv) {
  char filename[NAME_MAX + 1];
  FILE *file;
  char c, m;
  int cnt;
  scanf("%s", filename);
  file = fopen(filename, "r");
  if (file) {
    m = cnt = 0;
    while ((c = fgetc(file)) != EOF) {
      m = max(m, c);
      cnt++;
    }
    fclose(file);
    printf("%d %c", cnt, m);
  } else
    fprintf(stderr, "file not found.\n");
  return 0;
}

int max(int a, int b) { return a > b ? a : b; }