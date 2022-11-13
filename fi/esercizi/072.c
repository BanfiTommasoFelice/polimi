/*
Scrivere un sottoprogramma in C che riceve come parametro una frazione e la
stampa a video.
*/

#include <stdio.h>

typedef struct frac_s {
  int num, den;
} frac_t;

void scan(frac_t*);
void print(frac_t*);

int main(int argc, char** argv) {
  frac_t f;
  scan(&f);
  print(&f);
  return 0;
}

void scan(frac_t* f) {
  scanf("%d", &f->num);
  do scanf("%d", &f->den);
  while (!f->den);
}

void print(frac_t* f) { printf("%d/%d", f->num, f->den); }
