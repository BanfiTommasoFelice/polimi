/*
Scrivere un programma in linguaggio C ANSI che acquisisce un numero intero fine,
e quindi una sequenza di valori interi che si ritiene terminata quando l’utente
inserisce il valore fine (che non è parte della sequenza). Il programma calcola
e visualizza il valore massimo, minimo e la media dei valori. Nel caso in cui
l’utente inserisca subito il valore fine (sequenza di valori vuota), il
programma visualizza il valore fine come valore massimo, minimo e media.
*/

#define INT_MIN 0x80000000
#define INT_MAX 0x7fffffff

#include <stdio.h>

int main(int argc, char** argv) {
  int fine, curr, min, max, sum, n;
  float avg;
  scanf("%d", &fine);
  sum = 0;
  n   = 0;
  max = INT_MIN;
  min = INT_MAX;
  while (scanf("%d", &curr) && curr != fine) {
    n++;
    if (curr > max) max = curr;
    if (curr < min) min = curr;
    sum += curr;
  }
  if (n) avg = (float)sum / n;
  if (n)
    printf("%d %d %f", min, max, avg);
  else
    printf("%d %d %d", fine, fine, fine);
  return 0;
}
