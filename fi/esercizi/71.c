/*
Scrivere un sottoprogramma in C che riceve come parametri due frazioni, ne
esegue la moltiplicazione, semplifica il risultato (mediante la funzione
precedentemente definita) e trasmette il risultato.
*/

#include <stdio.h>

typedef struct frac_s {
  int num, den;
} frac_t;

int gcd(int a, int b);
void scan(frac_t*);
void simplify(frac_t*);
void mul(frac_t*, frac_t*, frac_t*);

int main(int argc, char** argv) {
  frac_t a, b, c;
  scan(&a);
  scan(&b);
  mul(&c, &a, &b);
  printf("%d/%d", c.num, c.den);
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

void mul(frac_t* c, frac_t* a, frac_t* b) {
  c->num = a->num * b->num;
  c->den = a->den * b->den;
  simplify(c);
}
