/*
Data una stringa, questa è costituita da parentesi tonde bilanciate se ad ogni
parentesi aperta corrisponde una parentesi chiusa (che viene dopo di essa) e ad
ogni parentesi chiusa corrisponde una parentesi aperta (che viene prima di
essa). Sono stringhe valide: “ “, “()”, “()()”, “(() ())”. Non sono stringhe
valide: “(“, “) (“, “(()”. Si scriva un sottoprogramma che data una stringa
valida determini e restituisca al chiamante il massimo livello di annidamento
delle parentesi.
*/

#define OPEN  '('
#define CLOSE ')'
#define MAXC  100

#include <stdio.h>

int max(int, int);
int depth(char[]);

int main(int argc, char** argv) {
  char s[MAXC + 1];
  int md;
  scanf("%s", s);
  md = depth(s);
  printf("%d", md);
  return 0;
}

int max(int a, int b) { return (a > b ? a : b); }

int depth(char s[]) {
  int d, i, m;
  i = 0;
  d = (s[0] == OPEN);
  m = d;
  while (s[++i]) {
    if (s[i] == OPEN)
      d++;
    else if (s[i] == CLOSE)
      m = max(m, d--);
  }
  return m;
}
