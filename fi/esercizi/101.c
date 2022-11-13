/*
Con formato si intende una stringa che contiene soltanto tre possibili
caratteri: V, che indica una vocale, C, che indica una consonante e D che indica
una cifra. Scrivere un sottoprogramma check che ricevute due stringhe, stin e
form, restituisce 1 se il contenuto della stringa stin rispetta il formato form,
0 altrimenti. I caratteri alfabetici della stringa stin sono esclusivamente
minuscoli.
Scrivere un programma che acquisisce da riga di comando due stringhe e
avvalendosi del sottoprogramma check visualizza OK se la prima stringa rispetta
il formato indicato dalla seconda stringa, KO in caso contrario.
*/

#define VOWEL      'V'
#define CONSONANT  'C'
#define DIGIT      'D'
#define ISDIGIT(x) ('0' <= (x) && (x) <= '9')
#define ISALPHA(x) ('a' <= (x) && (x) <= 'z')
#define ISVOWEL(x) \
  ((x) == 'a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u')
#define OK "OK"
#define KO "KO"

#include <stdio.h>

void usage(char*);
int check(char[], char[]);

int main(int argc, char** argv) {
  int v;
  if (argc == 3) {
    v = check(argv[1], argv[2]);
    if (v)
      printf(OK);
    else
      printf(KO);
  } else
    usage(argv[0]);
  return (argc != 3);
}

void usage(char* p) { printf("usage: %s string string", p); }

int check(char s[], char fmt[]) {
  int i, v;
  v = 1;
  for (i = 0; v && s[i]; i++)
    if (fmt[i] == VOWEL && !ISVOWEL(s[i]))
      v = 0;
    else if (fmt[i] == CONSONANT && (!ISALPHA(s[i]) || ISVOWEL(s[i])))
      v = 0;
    else if (fmt[i] == DIGIT && !ISDIGIT(s[i]))
      v = 0;
  return v;
}
