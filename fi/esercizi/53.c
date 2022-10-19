/*
Scrivere un programma in linguaggio C (ANSI 89) che chiede all’utente una
sequenza di al massimo 30 caratteri. Il programma identifica nella sequenza
tutte le sotto-sequenze di sole cifre in posizioni consecutive, e visualizza le
lunghezze della sotto-sequenza più lunga e di quella più corta. Nel caso la
stringa non contenga alcuna cifra, il programma visualizza il messaggio “0 0”.
*/

#define MAXC    30
#define INT_MAX 0x7fffffff

#include <stdio.h>

int main(int argc, char** argv) {
  char s[MAXC + 1];
  int min, max, tmp, i;
  gets(s);
  min = INT_MAX;
  max = 0;
  tmp = 0;
  for (i = 1; s[i]; i++)
    if ('0' <= s[i] && s[i] <= '9')
      tmp++;
    else if (tmp) {
      if (min > tmp) min = tmp;
      if (max < tmp) max = tmp;
      tmp = 0;
    }
  if (tmp) {
    if (min > tmp) min = tmp;
    if (max < tmp) max = tmp;
  }
  if (min == INT_MAX) min = 0;
  printf("%d %d", min, max);
  return 0;
}
