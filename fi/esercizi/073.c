/*
Scrivere un programma in C che mediante l’ausilio dei sottoprogrammi sopra
definiti, chiede all’utente due frazioni le somma e le moltiplica e visualizza i
due risultati.
*/

#include <stdio.h>

typedef struct frac_s {
  int num, den;
} frac_t;

int gcd(int a, int b);
void scan(frac_t*);
void print(frac_t*);
void simplify(frac_t*);
void add(frac_t*, frac_t*, frac_t*);
void mul(frac_t*, frac_t*, frac_t*);

int main(int argc, char** argv) {
  frac_t a, b, c, d;
  scan(&a);
  scan(&b);
  add(&c, &a, &b);
  mul(&d, &a, &b);
  print(&c);
  printf("\n");
  print(&d);
  return 0;
}

void scan(frac_t* f) {
  scanf("%d", &f->num);
  do scanf("%d", &f->den);
  while (!f->den);
}

void print(frac_t* f) { printf("%d/%d", f->num, f->den); }

int gcd(int a, int b) {
  int t;
  while (b) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
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

void add(frac_t* c, frac_t* a, frac_t* b) {
  c->num = a->num * b->den + a->den * b->num;
  c->den = a->den * b->den;
  simplify(c);
}

void mul(frac_t* c, frac_t* a, frac_t* b) {
  c->num = a->num * b->num;
  c->den = a->den * b->den;
  simplify(c);
}
