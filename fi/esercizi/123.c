/*
Scrivere un programma in C (ANSI 89) che chiede all’utente il nome di un file
(stringa di al più 40 caratteri) di testo contenente valori interi. Il programma
calcola e visualizza le seguenti informazioni:
+ numero di valori presenti nel file
+ valore massimo
+ valore minimo
+ numero di valori positivi
+ numero di valori negativi
+ numero di valori nulli
+ media dei valori presenti
Nel caso in cui il file sia vuoto, viene visualizzato il messaggio File vuoto
*/

#define NAME_MAX 40
#define INT_MIN  ((int)0x80000000)
#define INT_MAX  ((int)0x7fffffff)

#include <stdio.h>

int main(int argc, char **argv) {
  char filename[NAME_MAX + 1];
  int x, n, sum, minimum, maximum, positive, negative, zero;
  FILE *file;
  scanf("%s", filename);
  if ((file = fopen(filename, "r"))) {
    n        = 0;
    sum      = 0;
    positive = 0;
    negative = 0;
    zero     = 0;
    maximum  = INT_MIN;
    minimum  = INT_MAX;
    while (!feof(file) && 1 == fscanf(file, "%d", &x)) {
      if (x < minimum) minimum = x;
      if (x > maximum) maximum = x;
      sum += x;
      if (x > 0) positive++;
      if (x < 0) negative++;
      if (x == 0) zero++;
      n++;
    }
    fclose(file);
    if (n == 0)
      printf("file vuoto\n");
    else {
      printf("# totale: %d\n", n);
      printf("massimo: %d\n", maximum);
      printf("minimo: %d\n", minimum);
      printf("# positivi: %d\n", positive);
      printf("# negativi: %d\n", negative);
      printf("# nulli: %d\n", zero);
      printf("media: %f\n", (float)sum / n);
    }
  } else {
    fprintf(stderr, "file not found.\n");
  }
  return 0;
}
