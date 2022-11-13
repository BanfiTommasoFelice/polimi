/*
Si scriva un sottoprogramma che ricevute in ingresso due date, da e a, del tipo
precedente introdotto, e senz’altro valide e con a successiva a da, calcola e
restituisce al chiamante il numero di giorni che intercorrono tra le due date.
Per esempio, se il programma riceve 15 agosto 2022 e 24 ottobre 2022 il
sottoprogramma restituisce 70.
*/

#include <stdio.h>

typedef struct date_s {
  int d, m, y;
} date_t;

int datediff(date_t*, date_t*);

int main(int argc, char** argv) {
  date_t a, b;
  int d;
  scanf("%d%d%d", &a.d, &a.m, &a.y);
  scanf("%d%d%d", &b.d, &b.m, &b.y);
  d = datediff(&a, &b);
  printf("%d", d);
  return 0;
}

int bisestile(int y) { return !(y % 100 ? y % 4 : y % 400); }

void increment(date_t* d) {
  const int DAYS[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  d->d++;
  if (d->d > DAYS[d->m] + (bisestile(d->y) && d->m == 2)) {
    d->d = 1;
    d->m++;
  }
  if (d->m > 12) {
    d->m = 1;
    d->y++;
  }
}

int datediff(date_t* a, date_t* b) {
  /* TODO: modify this part according to the specification */
  const int DAYS[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  const int YEAR     = 365;

  int d;
  date_t t;
  d = 0;
  t = *a;
  while (t.y != b->y) { d += YEAR + bisestile(t.y++); }
  while (t.m > b->m) {
    d -= DAYS[t.m--]; /* FIXME: consider the case of bisestile year */
  }
  while (t.m < b->m) {
    d += DAYS[t.m++]; /* FIXME: consider the case of bisestile year */
  }
  while (t.d > b->d) {
    d--;
    t.d--;
  }
  while (t.d < b->d) {
    d++;
    t.d++;
  }
  /* code to test the correctness of above */
  int c;
  c = 0;
  t = *a;
  while (t.d != b->d || t.m != b->m || t.y != b->y) {
    c++;
    increment(&t);
  }
  if (c != d) printf("ERROR! correct: %d\n", c);

  return d;
}
