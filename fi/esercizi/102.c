/*
Scrivere un sottoprogramma che dato un array bidimensionale A di numeri interi
di dimensione NxM e un array b di dimensione inferiore al numero di colonne
presenti nell’array bi-dimensionale, e qualsiasi altro parametro necessario,
verifica e restituisce al chiamante il numero di righe in cui l’array b compare
nell’array A. Se l’array b compare in una riga dell’array A, compare una unica
volta. Si assuma che l’array bidimensionale sia stato dichiarato nel chiamante
con dimensione definita con le direttive #define
*/

#define N  5
#define M  7
#define B1 0x1b60267fb
#define B2 0x193407893
#define G  0xc023c3

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long u64;

typedef struct hash_s {
  u64 x, y, l;
} hash_t;

u64 fexpm(u64, u64, u64);
void hash_init(hash_t*);
void hash_add(hash_t*, int);
void hash_del(hash_t*, int);
int hash_cmp(hash_t*, hash_t*);

int count(int[N][M], int, int[]);

int main(int argc, char** argv) {
  int m[N][M], v[M], i, j;
  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++) scanf("%d", &m[i][j]);
  i = 0;
  while (!feof(stdin) && i < M) scanf("%d", &v[i++]);
  j = count(m, i, v);
  printf("%d", j);
  return 0;
}

u64 fexpm(u64 b, u64 e, u64 m) {
  u64 r;
  r = 1;
  b %= m;
  while (e) {
    if (e & 1) r = (r * b) % m;
    b = (b * b) % m;
    e >>= 1;
  }
  return r;
}

void hash_init(hash_t* h) {
  h->x = 0;
  h->y = 0;
  h->l = 0;
}
void hash_add(hash_t* h, int n) {
  h->x = (h->x * B1 + n) % G;
  h->y = (h->y * B2 + n) % G;
  h->l++;
}
void hash_del(hash_t* h, int n) {
  u64 p;
  h->l--;
  p    = fexpm(B1, h->l, G) * n;
  h->x = (h->x - p % G + G) % G;
  p    = fexpm(B2, h->l, G) * n;
  h->y = (h->y - p % G + G) % G;
}
int hash_eq(hash_t* a, hash_t* b) {
  return (a->x == b->x && a->y == b->y && a->l == b->l);
}

int count(int m[N][M], int n, int v[]) {
  hash_t needle, haystack;
  int i, j, c;
  hash_init(&needle);
  for (i = 0; i < n; i++) hash_add(&needle, v[i]);
  c = 0;
  for (i = 0; i < N; i++) {
    hash_init(&haystack);
    for (j = 0; j < n; j++) hash_add(&haystack, m[i][j]);
    if (hash_eq(&needle, &haystack)) c++;
    for (j = n; j < M; j++) {
      hash_del(&haystack, m[i][j - n]);
      hash_add(&haystack, m[i][j]);
      if (hash_eq(&needle, &haystack)) c++;
    }
  }
  return c;
}
