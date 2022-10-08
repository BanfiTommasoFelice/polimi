/*

*/

#define N 3

#include <stdio.h>

int main(int argc, char** argv) {
  int m[N][N], i, j, s, t, r;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) scanf("%d", &m[i][j]);
  s = 0;
  for (i = 0; i < N; i++) {
    s += m[i][i];
    t += m[i][N - i - 1];
  }
  for (i = 0; s == t && i < N; i++) {
    t = 0;
    for (j = 0; j < N; j++) t += m[i][j];
  }
  for (j = 0; s == t && j < N; j++) {
    t = 0;
    for (i = 0; i < N; i++) t += m[i][j];
  }
  r = (s == t);
  printf("%d %d", r, s);
  return 0;
}
