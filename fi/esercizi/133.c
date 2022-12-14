/*
Scrivere un programma che acquisiti tre interi corrispondenti a giorno mese ed
anno di una data, calcoli e visualizzi il numero del giorno nell’anno. Per
esempio se l’utente inserisce 5 3 2022 il programma calcola e visualizza 64 (31
giorni a gennaio, 28 a febbraio - non è un anno bisestile, 5 giorni a marzo). Si
utilizzi il costrutto switch.
*/

#include <stdio.h>

typedef struct day_s {
  int day, month, year;
} day_t;

void scan_day(day_t *);
int bisestile(int);
int doy(day_t);

int main(int argc, char **argv) {
  day_t x;
  int n;
  scan_day(&x);
  n = doy(x);
  printf("%d", n);
  return 0;
}

void scan_day(day_t *d) { scanf("%d%d%d", &d->day, &d->month, &d->year); }
int bisestile(int y) { return !(y % 100 ? y % 4 : y % 400); }
int doy(day_t x) {
  const int DAYS_PER_MONTH[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
  };
  int n;
  n = x.day;
  switch (x.month) {
  case 12:
    n += DAYS_PER_MONTH[11];
  case 11:
    n += DAYS_PER_MONTH[10];
  case 10:
    n += DAYS_PER_MONTH[9];
  case 9:
    n += DAYS_PER_MONTH[8];
  case 8:
    n += DAYS_PER_MONTH[7];
  case 7:
    n += DAYS_PER_MONTH[6];
  case 6:
    n += DAYS_PER_MONTH[5];
  case 5:
    n += DAYS_PER_MONTH[4];
  case 4:
    n += DAYS_PER_MONTH[3];
  case 3:
    n += DAYS_PER_MONTH[2] + bisestile(x.year);
  case 2:
    n += DAYS_PER_MONTH[1];
  case 1:
    n += DAYS_PER_MONTH[0];
  }
  return n;
}