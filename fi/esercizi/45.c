/*

*/

#define MAXC  100
#define START 'a'
#define END   'z'

#include <stdio.h>

int main(int argc, char** argv) {
  char s[MAXC + 1];
  int i, v, c;
  gets(s);
  i = v = c = 0;
  while (s[i]) {
    if (START <= s[i] && s[i] <= END)
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u')
        v++;
      else
        c++;
    i++;
  }
  printf("%d %d", v, c);
  return 0;
}
