/*
Scrivere un programma in C (ANSI 89) che acquisita una stringa di al più 30
caratteri, individui la sottostringa più lunga in essa contenuta, senza
caratteri ripetuti. Il programma visualizza la lunghezza di tale sottostringa,
seguita da un carattere a-capo. Realizzare la propria soluzione organizzandola
in sottoprogrammi, come ritenuto più opportuno.
*/

#define MAXC  30
#define COMBS (1 << (8 * sizeof(char)))

#include <stdio.h>

int max(int, int);
int maxsubstr(char[]);

int main(int argc, char** argv) {
  char s[MAXC + 1], m;
  scanf("%s", s);
  m = maxsubstr(s);
  printf("%d\n", m);
  return 0;
}

int max(int a, int b) { return (a > b ? a : b); }

int maxsubstr(char s[]) {
  int p[COMBS], i, m;
  for (i = 0; i < COMBS; i++) p[i] = -1;
  i = m = 0;
  while (s[++i]) {}
  for (i--; i >= 0; i--) {
    if (p[s[i]] != -1) m = max(m, p[s[i]] - i);
    p[s[i]] = i;
  }
  if (!m)
    while (s[++m]) {}
  return m;
}
