/*
Scrivere un sottoprogramma in C che riceve come parametro una frazione e la
semplifica spostando l’eventuale segno meno al numeratore e la trasmette al
chiamante.
*/

#include <stdio.h>

typedef struct frac_s {
  int num, den;
} frac_t;

int gcd(int a, int b);
void scan(frac_t*);
void simplify(frac_t*);

int main(int argc, char** argv) {
  frac_t f;
  scan(&f);
  simplify(&f);
  printf("%d/%d", f.num, f.den);
  return 0;
}

int gcd(int a, int b) {
  int t;
  while (b) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void scan(frac_t* f) {
  scanf("%d", &f->num);
  do scanf("%d", &f->den);
  while (!f->den);
}

void simplify(frac_t* f) {
  int s, g;
  s = (f->num < 0) ^ (f->den < 0);
  if (f->num < 0) f->num *= -1;
  if (f->den < 0) f->den *= -1;
  g = gcd(f->num, f->den);
  f->num /= g;
  f->den /= g;
  if (s) f->num *= -1;
}
