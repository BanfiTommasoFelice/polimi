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
#define TERM  '*'
#define REPL  '+'
#define START 'a'
#define END   'z'
#define DIM   (END - START + 1)

#include <stdio.h>

int main(int argc, char** argv) {
  char s[MAXC], c;
  int i, o[DIM], l;
  for (i = 0; i < DIM; i++) o[i] = 0;
  l = 0;
  while (scanf("%c", &c) && c != TERM) {
    if (START <= c && c <= END) o[c - START]++;
    s[l++] = c;
  }
  c = 0;
  for (i = 0; i < DIM; i++)
    if (o[i] >= o[c]) c = i;
  c += START;
  for (i = 0; i < l; i++)
    if (s[i] == c) s[i] = REPL;
  for (i = 0; i < l; i++) printf("%c", s[i]);
  return 0;
}
