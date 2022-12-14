/*
Una stringa costituisce un pangramma se ogni lettera dell’alfabeto compare
almeno una volta. Si scriva un sottoprogramma che ricevuta in ingresso una
stringa restituisce 1 se la stringa è un pangramma, 0 altrimenti. La stringa può
contenere caratteri maiuscoli, minuscoli e spazi; non importa se il carattere
compare come maiuscola o minuscola. Si considerino stringhe di senso compiuto in
inglese, in modo tale da non aver il problema delle lettere j, k, w, x, e y, che
quindi devono comparire anch’esse.
*/

#define AMPLITUDE  ('z' - 'a' + 1)
#define LOWER(x)   ((x) | 0x20)
#define UPPER(x)   ((x)&0xdf)
#define ISLOWER(x) ('a' <= (x) && (x) <= 'z')
#define ISUPPER(x) ('A' <= (x) && (x) <= 'Z')
#define ISALPHA(x) (ISLOWER(LOWER(x)))
#define ISDIGIT(x) ('0' <= (x) && (x) <= '9')
#define MAXC       (1u << 10)

#include <stdio.h>

int check_pangram(char *);

int main(int argc, char **argv) {
  char s[MAXC + 1];
  gets(s);
  printf("%d", check_pangram(s));
  return 0;
}

int check_pangram(char *s) {
  int freq[AMPLITUDE] = { 0 };
  int i, ok;
  for (i = 0; s[i]; i++)
    if (ISALPHA(s[i])) freq[LOWER(s[i]) - 'a']++;
  ok = 1;
  for (i = 0; ok && i < AMPLITUDE; i++)
    if (!freq[i]) ok = 0;
  return ok;
}
