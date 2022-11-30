/*
Scrivere un programma in C (ANSI 89) che acquisisce una sequenza di valori di
lunghezza a priori ignota dall’utente, che si ritiene terminata quando l’utente
inserisce un valore inferiore a 1. Il programma salva i numeri primi nel file
primi.csv, scrivendoli uno per riga.
*/

#define MIN      1
#define FILENAME "primi.csv"

#include <stdio.h>

int prime(int);

int main(int argc, char **argv) {
  FILE *file;
  int x;
  if ((file = fopen(FILENAME, "w"))) {
    while (scanf("%d", &x) && x >= MIN)
      if (prime(x)) fprintf(file, "%d\n", x);
    fclose(file);
  } else
    fprintf(stderr, "file not found.\n");
  return 0;
}

int prime(int n) {
  int u, p;
  p = (n < 4 ? n > 1 : n % 2 && n % 3);
  for (u = 5; p && u * u <= n; p += 6) p = n % u && n % (u + 2);
  return p;
}