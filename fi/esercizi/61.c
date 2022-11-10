/*
Nella preistoria dei videogiochi in Super Mario della Nintendo, Mario deve
saltare da una piramide di blocchi a quella adiacente. Proviamo a ricreare le
stesse piramidi in C, in testo, utilizzando il carattere cancelletto (`#`) come
blocco, come riportato di seguito. In realtà il carattere `#` è più alto che
largo, quindi le piramidi saranno un po’ più alte. Notate che lo spazio tra le
due piramidi è sempre costituito da 2 spazi, indipendentemente dall’altezza
delle piramidi. Inoltre, alla fine delle piramidi non ci devono essere spazi__.
L’utente inserisce l’altezza delle piramidi, che deve essere un valore
strettamente positivo e non superiore a 16. In caso l’utente inserisca un valore
che non rispetta questi vincoli, la richiesta viene ripetuta.
*/

#define BLOCK '#'
#define VOID  ' '
#define MINH  1
#define MAXH  16
#define GAP   2

#include <stdio.h>

void scan(int*, int, int);

int main(int argc, char** argv) {
  int h, i, j;
  scan(&h, MINH, MAXH);
  for (i = 0; i < h; i++) {
    for (j = 1; j < h - i; j++) putchar(VOID);
    for (j = 0; j <= i; j++) putchar(BLOCK);
    for (j = 0; j < GAP; j++) putchar(VOID);
    for (j = 0; j <= i; j++) putchar(BLOCK);
    for (j = 1; j < h - i; j++) putchar(VOID);
    printf("\n");
  }
  return 0;
}

void scan(int* n, int min, int max) {
  do scanf("%d", n);
  while (*n < min || *n > max);
}
