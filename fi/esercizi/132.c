/*
La cerniera è uno schema enigmistico che segue una formula del tipo ZX / YZ =
XY, ossia date due stringhe s1 e s2 cerca una sottostringa Z presente in
entrambe, in s1 all’inizio, in s2 alla fine, e se esiste definisce una nuova
stringa concatenando ciò che avanza da s1 e s2. Non consideriamo valide
soluzioni in cui Y non esista, ossia s2 è una sottostringa di s1.
Scrivere un sottoprogramma cercacerniera che riceve in ingresso due stringhe e
restituisce l’indice della posizione in cui comincia in s2 la sottostringa Z, se
esiste, -1 se non esiste. Con questa informazione il chiamante potrà creare la
stringa risultante. Naturalmente non è importante in questo frangente che il
vocabolo risultante dalla cerniera abbia senso in italiano. Scrivere un
sottoprogramma creacerniera che riceve in ingresso due stringhe s1 e s2 ed un
valore intero inizio. Il sottoprogramma crea e restituisce una nuova stringa che
si ottiene concatenando i caratteri di s1 che seguono la sottostringa di s2 a
partire dalla posizione inizio, ai caratteri di s2 che precedono inizio.
Senz’altro il valore di inizio è compatibile con le dimensioni di s1 e s2.
*/

#define B1 0x1b60267fb
#define B2 0x193407893
#define G  0xc023c3

#include <err.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long u64;
typedef struct hash_s {
  u64 x, y, l;
} hash_t;

u64 fexpm(u64, u64, u64);
u64 modinv(u64, u64);
void hash_init(hash_t *);
void hash_add_left(hash_t *, int);
void hash_add_right(hash_t *, int);
void hash_del_left(hash_t *, int);
void hash_del_right(hash_t *, int);
int hash_eq(hash_t *, hash_t *);

void usage(char *);
int find_zip(char *, char *);
char *zip_up(char *, char *, int);

int main(int argc, char **argv) {
  int zip;
  char *s;
  if (argc == 3) {
    zip = find_zip(argv[1], argv[2]);
    printf("%d\n", zip);
    if (zip != -1) {
      s = zip_up(argv[1], argv[2], zip);
      printf("%s", s);
      free(s);
    }
  } else
    usage(argv[0]);
  return 0;
}

void usage(char *p) { printf("usage: %s string string\n", p); }

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

u64 modinv(u64 n, u64 m) { return fexpm(n, m - 2, m); }

void hash_init(hash_t *h) {
  h->x = 0;
  h->y = 0;
  h->l = 0;
}
void hash_add_right(hash_t *h, int n) {
  h->x = (h->x * B1 + n) % G;
  h->y = (h->y * B2 + n) % G;
  h->l++;
}
void hash_add_left(hash_t *h, int n) {
  h->x += (fexpm(B1, h->l, G) * n) % G;
  h->y += (fexpm(B2, h->l, G) * n) % G;
  h->x %= G;
  h->y %= G;
  h->l++;
}
void hash_del_left(hash_t *h, int n) {
  u64 p;
  h->l--;
  p    = fexpm(B1, h->l, G) * n;
  h->x = (h->x - p % G + G) % G;
  p    = fexpm(B2, h->l, G) * n;
  h->y = (h->y - p % G + G) % G;
}
void hash_del_right(hash_t *h, int n) {
  h->x = ((h->x - n % G + G) % G) * modinv(B1, G);
  h->y = ((h->y - n % G + G) % G) * modinv(B2, G);
  h->x %= G;
  h->y %= G;
  h->l--;
}
int hash_eq(hash_t *a, hash_t *b) {
  return (a->x == b->x && a->y == b->y && a->l == b->l);
}

int find_zip(char *s1, char *s2) {
  int i, j, n, m, k;
  hash_t h1, h2;
  hash_init(&h1);
  hash_init(&h2);
  n = strlen(s1);
  m = strlen(s2);
  k = (n < m ? n : m);
  if (k-- == 0) return -1;
  for (i = 0; i < k; i++) hash_add_right(&h1, s1[i]);
  for (j = m - 1; j >= m - k; j--) hash_add_left(&h2, s2[j]);
  for (i--, j++; !hash_eq(&h1, &h2) && j < m; i--, j++) {
    hash_del_right(&h1, s1[i]);
    hash_del_left(&h2, s2[j]);
  }
  return (j < m ? j : -1);
}

char *zip_up(char *s1, char *s2, int j) {
  char *s;
  int n, m, k;
  n = strlen(s1);
  m = strlen(s2);
  k = m - j;
  s = malloc((n + m - 2 * k + 1) * sizeof(char));
  if (!s) ERROR(s);
  strncpy(s, s1 + k, n - k);
  strncpy(s + n - k, s2, j);
  s[n + m - 2 * k] = 0;
  return s;
}