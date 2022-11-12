/*
Si scriva un programma che ricevuta in ingresso una stringa di al massimo 50
caratteri composta da parentesi bilanciate (e fino a che non è tale la richieda)
determini e visualizzi il massimo livello di annidamento delle parentesi di tale
stringa.
*/

#define OPEN  '('
#define CLOSE ')'
#define MAXC  50

#include <stdio.h>

int valid(char[]);
int max(int, int);
int depth(char[]);

int main(int argc, char** argv) {
  char s[MAXC + 1];
  int md;
  do scanf("%s", s);
  while (!valid(s));
  md = depth(s);
  printf("%d", md);
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
