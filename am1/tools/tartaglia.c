// #define LATEX

#include "stdio.h"
#include "stdlib.h"

typedef unsigned long n_t;

n_t **alloc(n_t, n_t);
void dealloc(n_t, n_t **);
void build(n_t, n_t, n_t **);
void print(n_t, n_t, n_t **);

int main(int argc, char **argv) {
  if (argc != 3) return 1;
  n_t n, m;
  n = atoi(argv[1]);
  m = atoi(argv[2]) + 1;

  n_t **t = alloc(n, m);
  build(n, m, t);
  print(n, m, t);
  dealloc(n, t);

  return 0;
}

inline n_t min(n_t a, n_t b) { return a < b ? a : b; }
inline n_t max(n_t a, n_t b) { return a > b ? a : b; }

n_t **alloc(n_t n, n_t m) {
  n_t **t = malloc(n * sizeof(n_t *));
  for (n_t i = 0; i < n; i++) t[i] = malloc(m * sizeof(n_t));
  return t;
}

void dealloc(n_t n, n_t **t) {
  for (n_t i = 0; i < n; i++) free(t[i]);
  free(t);
}

void build(n_t n, n_t m, n_t **t) {
  for (n_t i = 0; i < n; i++) t[i][0] = 1;
  for (n_t i = 0; i < min(n, m); i++) t[i][i + 1] = 1;
  for (n_t i = 0; i < n; i++)
    for (n_t j = 1; j < m && j < i + 1; j++)
      t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
}

void print(n_t n, n_t m, n_t **t) {
#ifdef LATEX
  for (n_t j = 0; j < m; j++) printf("& %lu ", j);
  printf("\\\\\n");
#endif
  for (n_t i = 0; i < n; i++) {
#ifndef LATEX
    for (n_t j = 0; j < m && j <= i + 1; j++) printf("%lu\t", t[i][j]);
#else
    printf("%lu & ", i + 1);
    for (n_t j = 0; j < m && j < i + 1; j++) printf("%lu & ", t[i][j]);
    printf("%lu \\\\", t[i][i + 1]);
#endif
    printf("\n");
  }
}