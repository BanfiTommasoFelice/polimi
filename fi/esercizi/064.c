/*
Scrivere un programma che acquisisce una stringa `seq1` di massimo 50 caratteri
e un numero intero `n`. Il valore `n` deve essere minore della lunghezza della
stringa e fino a quando non è tale lo richiede all’utente. In seguito il
programma crea una nuova stringa `seq2` che contiene la rotazione verso destra
di `seq1` di `n` posizioni e la visualizza. La nuova stringa va creata, non è
sufficiente visualizzare il risultato.
*/

#define MAXC 50

#include <stdio.h>
#include <string.h>

void scan(int*, int, int);

int main(int argc, char** argv) {
  char s[MAXC + 1], t[MAXC + 1];
  int n, l, i;
  scanf("%s", s);
  l = strlen(s);
  scan(&n, 0, l - 1);
  for (i = 0; i < l; i++) t[(i + n) % l] = s[i];
  t[l] = 0;
  printf("%s", t);
  return 0;
}

void scan(int* n, int min, int max) {
  do scanf("%d", n);
  while (*n < min || *n > max);
}
