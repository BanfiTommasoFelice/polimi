/*
Si scriva un programma in C (ANSI 89) che acquisisce 50 valori interi e
visualizza tutti e soli quelli superiori alla media degli stessi.
*/

#define N 50

#include <stdio.h>

int main(int argc, char** argv) {
  int v[N], s, i;
  float avg;
  i = 0;
  s = 0;
  while (i < N) {
    scanf("%d", &v[i]);
    s += v[i++];
  }
  avg = (float)s / N;
  i   = 0;
  while (i < N) {
    if (v[i] > avg) printf("%d ", v[i]);
    i++;
  }
  return 0;
}
