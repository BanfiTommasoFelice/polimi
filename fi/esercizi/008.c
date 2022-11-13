/*
Scrivere un programma in linguaggio C ANSI che realizzi l’algoritmo definito dal
diagramma di flusso di seguito riportato.
*/

#define VOWEL     'v'
#define CONSONANT 'c'
#define OTHER     ' '

#include <stdio.h>

int main(int argc, char** argv) {
  char c, result;
  scanf("%c", &c);
  if (c >= 'A' && c <= 'Z') {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
      result = VOWEL;
    else
      result = CONSONANT;
  } else {
    if (c >= 'a' && c <= 'z')
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        result = VOWEL;
      else
        result = CONSONANT;
    else
      result = OTHER;
  }
  printf("%c", result);
  return 0;
}
