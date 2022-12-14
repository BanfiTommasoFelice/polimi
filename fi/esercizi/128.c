/*
Scrivere un programma che trova e visualizza tutti i vocaboli di un dizionario
(file di testo ASCII dizionario.txt) in cui tutte le vocali presenti compaiono
in ordine lessicografico crescente. Non è necessario che compaiano tutte le
vocali e la stessa vocale può comparire più volte. Nel file, ogni vocabolo
compare su una riga nuova, ed è al più lungo 35 caratteri. I caratteri sono
tutti minuscoli e non accentati.
*/

#define ISVOWEL(c)                                                             \
  ((c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u')
#define MAXC     35
#define FILENAME "dizionario.txt"

#include <err.h>
#include <stdio.h>

int check(char *);

int main(int argc, char **argv) {
  FILE *fp;
  char s[MAXC + 1];
  fp = fopen(FILENAME, "r");
  if (!fp) ERROR(fp);
  while (fscanf(fp, "%s", s) != EOF)
    if (check(s)) printf("%s\n", s);
  fclose(fp);
  return 0;
}

int check(char *s) {
  int i, ok;
  char c;
  ok = 1;
  c  = 0;
  for (i = 0; ok && s[i]; i++)
    if (ISVOWEL(s[i])) {
      if (c > s[i])
        ok = 0;
      else
        c = s[i];
    }
  return ok;
}