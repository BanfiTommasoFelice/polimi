/*
Scrivere un programma in C (ANSI 89) che analizza un sequenza di numeri interi
di lunghezza indefinita terminata dal valore 0 (che non fa parte della
sequenza). In particolare, per ciascun valore letto, il programma stabilisce se
questo è il doppio del suo precedente; in tal caso stampa a video la coppia di
numeri. NOTA: attenzione al caso in cui la sequenza sia vuota (cioè l’utente
inserisce 0 come primo valore).
*/

#define END 0

#include <stdio.h>

int main(int argc, char** argv) {
  int n, m;
  scanf("%d", &n);
  if (n != END) {
    do {
      scanf("%d", &m);
      if (m != END && m == 2 * n) printf("%d %d\n", n, m);
      n = m;
    } while (m != END);
  }
  return 0;
}
