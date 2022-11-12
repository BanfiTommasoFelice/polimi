/*
Scrivere un sottoprogramma `minmaxstr` che riceve in ingresso una stringa e
trasmette al chiamante due caratteri, il minimo e il massimo nell’ordinamento
alfabetico tra quelli contenuti nella stringa. Per esempio, se la stringa in
ingresso è “esempio”, il minimo ed il massimo sono rispettivamente `e` ed `s`.
La stringa contenga tutti e soli caratteri alfabetici minuscoli. Rivedere il
sottoprogramma `minmaxstr` in modo tale che i caratteri possano essere sia
maiuscoli, sia minuscoli, e facendo in modo che il sottoprogramma trasmetta
comunque quelli minuscoli. In tal caso, se la stringa in ingresso è
“Architetto”, il minimo ed il massimo sono rispettivamente `a` ed `t`.
*/

#define MAXC     100
#define LOWER(x) (x | 0x20)

#include <stdio.h>

void minmaxstr(char[], char*, char*);

int main(int argc, char** argv) {
  char s[MAXC + 1], min, max;
  scanf("%s", s);
  minmaxstr(s, &min, &max);
  printf("%c %c", min, max);
  return 0;
}

void minmaxstr(char s[], char* min, char* max) {
  int i;
  if (s[0]) *min = *max = LOWER(s[0]);
  i = 0;
  while (s[++i]) {
    if (*min > s[i]) *min = LOWER(s[i]);
    if (*max < s[i]) *max = LOWER(s[i]);
  }
}
