/*
Scrivere un sottoprogramma in C che chiede all’utente una frazione valida
(denominatore diverso da zero) e la trasmette al chiamate; nel caso la
condizione non sia soddisfatta il sottoprogramma richiede di nuovo all’utente di
inserire dei valori validi.
*/

#include <stdio.h>

typedef struct frac_s {
  int num, den;
} frac_t;

void scan(frac_t*);

int main(int argc, char** argv) {
  frac_t f;
  scan(&f);
  printf("%d/%d", f.num, f.den);
  return 0;
}

void scan(frac_t* f) {
  scanf("%d", &f->num);
  do scanf("%d", &f->den);
  while (!f->den);
}
