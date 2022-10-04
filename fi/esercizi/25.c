/*
Un numero intero è palindromo quando le sue cifre rappresentano lo stesso valore
sia che siano lette da destra che da sinistra. Esempi di numeri palindromi sono
111, 10201, 13431, mentre 4240, 3235 e 1002 non lo sono. Scrivere un programma
in C (ANSI 89) che chiede all’utente un numero intero positivo (e fino a che non
è tale richiede il valore). Il programma verifica se il numero è palindromo; in
caso affermativo visualizza 1, altrimenti 0.
*/

#define PALINDROME     "1"
#define NON_PALINDROME "0"
#define BASE           10

#include <stdio.h>

int main(int argc, char** argv) {
  int n, p, l, tmp, i;
  do scanf("%d", &n);
  while (n < 0);
  if (n % BASE == 0)
    p = 0;
  else {
    l = i = p = 1;
    tmp       = n;
    while (tmp) {
      tmp /= BASE;
      l *= BASE;
    }
    while (i < l && p) {
      l /= BASE;
      if ((n / i) % BASE != (n / l) % BASE) p = 0;
      i *= BASE;
    }
  }
  if (p)
    printf(PALINDROME);
  else
    printf(NON_PALINDROME);
  return 0;
}
