/*

*/

#define NR           5
#define NC           5
#define IDENTITY     1
#define NON_IDENTITY 0

#include <stdio.h>

int main(int argc, char** argv) {
  int m[NR][NC], s, i, j;
  for (i = 0; i < NR; i++)
    for (j = 0; j < NC; j++) scanf("%d", &m[i][j]);
  s = (NR == NC ? IDENTITY : NON_IDENTITY);
  for (i = 0; s == IDENTITY && i < NR; i++)
    for (j = 0; s == IDENTITY && j < NC; j++)
      if (i == j && m[i][j] != 1)
        s = NON_IDENTITY;
      else if (i != j && m[i][j] != 0)
        s = NON_IDENTITY;
  printf("%d", s);
  return 0;
}
