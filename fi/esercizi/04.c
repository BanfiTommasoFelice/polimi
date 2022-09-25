/*
Si realizzi un programma in linguaggio C ANSI che riceve in ingresso un numero
intero positivo (è senz'altro così), che rappresenta un tempo espresso in
secondi. L'algoritmo calcola e visualizza lo stesso tempo espresso in giorni,
ore, minuti e secondi. Ad esempio se il valore in ingresso è 105738 (secondi),
l'algoritmo visualizza 1d 5h 22m 18s.
*/

#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR   60
#define HOURS_PER_DAY      24

#define SECONDS_PER_HOUR (SECONDS_PER_MINUTE * MINUTES_PER_HOUR)
#define SECONDS_PER_DAY  (SECONDS_PER_HOUR * HOURS_PER_DAY)

#include "stdio.h"

int main(int argc, char **argv) {
  unsigned s, m, h, d;
  scanf("%u", &s);
  d = s / SECONDS_PER_DAY;
  s %= SECONDS_PER_DAY;
  h = s / SECONDS_PER_HOUR;
  s %= SECONDS_PER_HOUR;
  m = s / SECONDS_PER_MINUTE;
  s %= SECONDS_PER_MINUTE;
  printf("%ud %uh %um %us", d, h, m, s);
  return 0;
}
