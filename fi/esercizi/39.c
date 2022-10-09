/*
Si scriva un programma in C (ANSI 89) che acquisisce le date di nascita di 50
persone e una ulteriore data, datarif: il programma calcola e visualizza il
numero di persone che festeggiano il compleanno nello stesso giorno ed il numero
di persone nate lo stesso giorno.
*/

#define N 50

#include <stdio.h>

typedef struct {
  unsigned day, month;
  unsigned long year;
} date_t;

int main(int argc, char** argv) {
  date_t births[N], rif;
  int i, a, b;
  for (i = 0; i < N; i++)
    scanf("%u%u%lu", &births[i].day, &births[i].month, &births[i].year);
  scanf("%u%u%lu", &rif.day, &rif.month, &rif.year);
  a = b = 0;
  for (i = 0; i < N; i++)
    if (rif.day == births[i].day && rif.month == births[i].month) {
      a++;
      if (rif.year == births[i].year) b++;
    }
  printf("%d %d", a, b);
  return 0;
}
