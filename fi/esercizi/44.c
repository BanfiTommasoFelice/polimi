/*

*/

#define MAXC 100

#include <stdio.h>

int main(int argc, char** argv) {
  char s[MAXC + 1];
  int p, i, l;
  gets(s);
  l = 0;
  p = 1;
  while (s[++l]) {}
  for (i = 0; p && i < l / 2; i++)
    if (s[i] != s[l - i - 1]) p = 0;
  printf("%d", p);
  return 0;
}
