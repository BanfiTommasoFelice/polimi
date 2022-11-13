/*
Scrivere un programma in C (ANSI 89) che acquisisce una stringa di al più 100
caratteri, seguita da una seconda stringa di al più 5 caratteri. Il programma
calcola e visualizza il numero di volte che nella prima stringa compaiono i
caratteri della seconda.
*/

#define MAXC 100
#define MAXS 5

#include <stdio.h>

int main(int argc, char** argv) {
  char t[MAXC + 1], s[MAXS + 1];
  int i, j, c, z;
  gets(t);
  gets(s);
  c = 0;
  while (t[i]) {
    z = 0;
    for (j = 0; !z && s[j]; j++)
      if (t[i] == s[j]) z = 1;
    c += z;
    i++;
  }
  printf("%d", c);
  return 0;
}
