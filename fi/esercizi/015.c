/*
Si realizzi un programma in linguaggio C ANSI che realizza le funzionalità base
di una calcolatrice. Il programma chiede all'utente un carattere che rappresenta
l'operazione che si vuole eseguire (+ - * /) e due numeri in virgola mobile
(notazione polacca o prefissa). Il programma esegue l'operazione richiesta e
visualizza il risultato. Nel caso l'utente inserisce un carattere che non
rappresenta alcuna operazione ammissibile, il programma restituisce il carattere
'x'.
*/

#define SUM  '+'
#define DIFF '-'
#define MUL  '*'
#define DIV  '/'
#define ERR  'x'

#include <stdio.h>

int main(int argc, char** argv) {
  float a, b, result;
  char op, error = 0;
  scanf("%c%f%f", &op, &a, &b);
  if (op == SUM)
    result = a + b;
  else if (op == DIFF)
    result = a - b;
  else if (op == MUL)
    result = a * b;
  else if (op == DIV)
    result = a / b;
  else
    error = 1;
  if (error)
    printf("%c", ERR);
  else
    printf("%f", result);
  return 0;
}
