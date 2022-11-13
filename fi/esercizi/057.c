/*
Si scriva un sottoprogramma sceltamenu in linguaggio C (ANSI 89) che visualizza
il menu’ utente di seguito riportato e acquisisce la scelta dell’utente e fino a
quando non e’ compatibile con i valori previsti la richiede. quando l’utente
seleziona un voce valida la restituisce al chiamante:
1. acquisizione valore
2. numero primo
3. fattoriale
4. palindromo
0. termina
*/

#include <stdio.h>

int menu(void);
int choose(void);

int main(int argc, char** argv) {
  choose();
  return 0;
}

int menu(void) {
  int i;
  i = 0;
  printf("%d. acquisizione valore\n", ++i);
  printf("%d. numero primo\n", ++i);
  printf("%d. fattoriale\n", ++i);
  printf("%d. palindromo\n", ++i);
  printf("%d. termina\n", 0);
  return i;
}

int choose(void) {
  int d, n;
  d = menu();
  do scanf("%d", &n);
  while (n < 0 || n > d);
  return n;
}
