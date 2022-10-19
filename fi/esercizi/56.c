/*
Si scriva un sottoprogramma menu in linguaggio C (ANSI 89) che visualizza il
seguente menu’ utente:
1. acquisizione valore
2. numero primo
3. fattoriale
4. palindromo
0. termina
*/

#include <stdio.h>

void menu(void);

int main(int argc, char** argv) {
  menu();
  return 0;
}

void menu(void) {
  int i;
  i = 1;
  printf("%d. acquisizione valore\n", i++);
  printf("%d. numero primo\n", i++);
  printf("%d. fattoriale\n", i++);
  printf("%d. palindromo\n", i++);
  printf("%d. termina\n", i = 0);
}
