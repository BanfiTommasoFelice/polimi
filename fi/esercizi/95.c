/*
Si vuole realizzare un programma in C (C89) per la gestione di un archivio di
album musicali (al massimo 100). Ogni album è caratterizzato da un titolo ed un
autore (entrambe stringhe di al massimo 30 caratteri), un anno di pubblicazione,
il numero di tracce, la durata complessiva (in termini di ore, minuti, secondi);
infine, si vuole memorizzare anche il prezzo del album (un valore float).
Definire un tipo di dato per rappresentare l’archivio di album. In seguito
scrivere un programma che chiede all’utente prima il numero di album da inserire
e poi i dati di ciascun album (assumendo che l’utente inserisca correttamente i
dati). Il programma visualizza i dati del album di durata massima; se sono
presenti più album di stessa durata massima il programma visualizzerà i dati del
primo di essi (VARIANTE: il programma visualizza i dati di tutti gli album di
durata massima, se ne sono stati trovati più di uno). In seguito il programma
chiede il nome di un autore e visualizza i titoli di tutti gli album pubblicati
da questo. Infine il programma visualizza l’autore che ha pubblicato più album;
se più autori autori hanno lo stesso numero massimo di album, si visualizzi il
primo.
*/

#define MAXN               100
#define MAXC               30
#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR   60
#define SECONDS_PER_HOUR   (SECONDS_PER_MINUTE * MINUTES_PER_HOUR)

#include <stdio.h>
#include <string.h>

typedef struct time_s {
  int h, m, s;
} time_t;

typedef struct album_s {
  char title[MAXC + 1], author[MAXC + 1];
  int year, tracks;
  time_t duration;
  float price;
} album_t;

int time_cmp(time_t*, time_t*);
void scan(album_t*);
void print(album_t*);
time_t maxduration(int, album_t[]);
int maxfreq(int, album_t[]);

int main(int argc, char** argv) {
  album_t v[MAXN];
  time_t d;
  int n, i;
  char author[MAXC + 1];
  scanf("%d", &n);
  for (i = 0; i < n; i++) scan(&v[i]);
  d = maxduration(n, v);
  for (i = 0; i < n; i++)
    if (!time_cmp(&v[i].duration, &d)) print(&v[i]);
  scanf("%s", author);
  for (i = 0; i < n; i++)
    if (!strcmp(v[i].author, author)) print(&v[i]);
  i = maxfreq(n, v);
  printf("%s\n", v[i].author);
  return 0;
}

int time_cmp(time_t* a, time_t* b) {
  int x, y;
  x = a->h * SECONDS_PER_HOUR + a->m * SECONDS_PER_MINUTE + a->s;
  y = b->h * SECONDS_PER_HOUR + b->m * SECONDS_PER_MINUTE + b->s;
  return x - y;
}

void scan(album_t* a) {
  scanf("%s", a->title);
  scanf("%s", a->author);
  scanf("%d", &a->year);
  scanf("%d", &a->tracks);
  scanf("%d%d%d", &a->duration.h, &a->duration.m, &a->duration.s);
  scanf("%f", &a->price);
}

void print(album_t* a) {
  printf("%s (%s) [%d] %d:%d:%d $%.2f\n", a->title, a->author, a->year,
         a->duration.h, a->duration.m, a->duration.s, a->price);
}

time_t maxduration(int n, album_t v[]) {
  int m, i;
  m = 0;
  for (i = 1; i < n; i++)
    if (time_cmp(&v[i].duration, &v[m].duration)) m = i;
  return v[m].duration;
}

int maxfreq(int n, album_t v[]) {
  int authors[MAXN], cnt[MAXN], i, j, m, s;
  m = 0;
  for (i = 0; i < n; i++) {
    s = 0;
    for (j = 0; !s && j < m; j++)
      s = !strcmp(v[i].author, v[authors[j]].author);
    if (s)
      cnt[--j]++;
    else {
      authors[m] = i;
      cnt[m]     = 1;
      m++;
    }
  }
  s = 0;
  for (i = 1; i < m; i++)
    if (cnt[i] > cnt[s]) s = i;
  return authors[s];
}
