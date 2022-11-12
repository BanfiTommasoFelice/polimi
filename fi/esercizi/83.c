/*
Si scriva un sottoprogramma per determinare se una stringa è costituita da
parentesi tonde bilanciate. Il sottoprogramma restituisce 1 se la stringa è
valida, 0 altrimenti.
*/

#define OPEN  '('
#define CLOSE ')'
#define MAXC  100

#include <stdio.h>

int valid(char[]);

int main(int argc, char** argv) {
  char s[MAXC + 1];
  int v;
  scanf("%s", s);
  v = valid(s);
  printf("%d", v);
  return 0;
}

int valid(char s[]) {
  int n, i, v;
  if (!s[0]) return 1; /* FIXME: remove unnecessary return */
  v = (s[0] == OPEN);
  i = 0;
  n = 1;
  while (v && s[++i]) {
    if (s[i] == OPEN)
      n++;
    else if (s[i] == CLOSE)
      n--;
    v = n >= 0;
  }
  return v && n == 0;
}
