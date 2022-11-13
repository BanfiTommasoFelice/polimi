/*
Si realizzi un programma in linguaggio C ANSI che letta la data di nascita di
una persona e la data attuale nel formato giorno mese anno, calcola poi l’età
della persona in anni.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  unsigned birth_day, birth_month, birth_year;
  unsigned now_day, now_month, now_year;
  unsigned age;
  scanf("%u%u%u", &birth_day, &birth_month, &birth_year);
  scanf("%u%u%u", &now_day, &now_month, &now_year);
  age = now_year - birth_year;
  if (birth_month > now_month) age--;
  printf("%u", age);
  return 0;
}
