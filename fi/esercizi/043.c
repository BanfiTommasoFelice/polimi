/*
Scrivere un programma che acquisisce una sequenza di al più 100 caratteri che
rappresenta una frase scritta in italiano, terminata quando l’utente inserisce
il carattere `*`. Il programma calcola il carattere più frequente e visualizza
la frase dopo averlo sostituito con il carattere `*`. L’utente inserisce
senz’altro una sequenza di caratteri minuscoli, spazi e caratteri di
interpunzione, senz’altro non più lunga di 50 caratteri e senz’altro non il
carattere terminatore non viene inserito per primo. A parità di numero di
occorrenze si consideri il carattere che viene per ultimo nell’alfabeto.
*/

#define MAXC  100
#define REPL  '+'
#define START 'a'
#define END   'z'
#define DIM   (END - START + 1)

#include <stdio.h>

int main(int argc, char** argv) {
  char s[MAXC + 1], m[MAXC + 1], c;
  int i, o[DIM];
  for (i = 0; i < DIM; i++) o[i] = 0;
  i = 0;
  gets(s);
  while (s[i]) {
    if (START <= s[i] && s[i] <= END) o[s[i] - START]++;
    i++;
  }
  c = 0;
  for (i = 0; i < DIM; i++)
    if (o[i] >= o[c]) c = i;
  c += START;
  i = 0;
  while (s[i]) m[i++] = (s[i] == c ? REPL : s[i]);
  m[i] = 0;
  printf("%s", m);
  return 0;
}
