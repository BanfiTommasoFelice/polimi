/*
Scrivere un programma in linguaggio C ANSI che realizzi l'algoritmo definito dal
diagramma di flusso di seguito riportato.
*/

#define TWO_REAL_DISTINCT_SOLUTIONS "due soluzioni reali distinte"
#define TWO_REAL_EQUAL_SOLUTIONS    "due soluzioni reali uguali"
#define TWO_COMPLEX_SOLUTIONS       "due soluzioni complesse"
#define ONE_REAL_SOLUTION           "una soluzione reale"
#define IMPOSSIBLE                  "impossibile"
#define IDENTITY                    "identità"

#include <stdio.h>

int main(int argc, char** argv) {
  int a, b, c, det;
  int sol;
  scanf("%d%d%d", &a, &b, &c);
  if (a) {
    det = b * b - 4 * a * c;
    if (det > 0)
      sol = 0; /* TWO_REAL_DISTINCT_SOLUTIONS; */
    else if (det == 0)
      sol = 1; /* TWO_REAL_EQUAL_SOLUTIONS; */
    else
      sol = 2; /* TWO_COMPLEX_SOLUTIONS; */
  } else if (b)
    sol = 3; /* ONE_REAL_SOLUTION; */
  else if (c)
    sol = 4; /* IMPOSSIBLE; */
  else
    sol = 5; /* IDENTITY; */
  if (sol == 0)
    printf(TWO_REAL_DISTINCT_SOLUTIONS);
  else if (sol == 1)
    printf(TWO_REAL_EQUAL_SOLUTIONS);
  else if (sol == 2)
    printf(TWO_COMPLEX_SOLUTIONS);
  else if (sol == 3)
    printf(ONE_REAL_SOLUTION);
  else if (sol == 4)
    printf(IMPOSSIBLE);
  else
    printf(IDENTITY);
  return 0;
}
