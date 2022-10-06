/*

*/

#define MIN  1
#define MAX  1023
#define BASE 2
#define N    10 /* ceil(log_BASE(MAX)) */

#include <stdio.h>

int main(int argc, char** argv) {
  int n, i, result[N];
  do scanf("%d", &n);
  while (n < MIN || n > MAX);
  for (i = 0; i < N; i++, n /= BASE) result[i] = n % BASE;
  for (i--; i >= 0; i--) printf("%d", result[i]);
  return 0;
}
