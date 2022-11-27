/*
Scrivere un sottoprogramma ricorsivo che riceve come parametri due stringhe a e
b; il sottoprogramma verifica se in b sono presenti tutti i caratteri presenti
in a, nello stesso ordine, più eventualmente qualche altro carattere. In caso
affermativo il sottoprogramma restituisce 1 altrimenti 0. Scrivere un programma
che acquisisce da riga di comando due stringhe, invoca il sottoprogramma
definito e visualizza il risultato. VARIANTE: Scrivere la versione iterativa del
sottoprogramma.
*/

#include <stdio.h>
#include <string.h>

void usage(char*);
int check(char*, char*);
int check_iter(char[], char[]);

int main(int argc, char** argv) {
  int v;
  if (argc == 3) {
    v = check(argv[1], argv[2]);
    printf("%d", v);
  } else
    usage(argv[0]);
  return (argc != 3);
  return 0;
}

void usage(char* p) { printf("usage: %s string string\n", p); }

int check(char* a, char* b) {
  if (!*a) return 1;
  if (!*b) return 0;
  return check(a + (*a == *b), b + 1);
}

int check_iter(char a[], char b[]) {
  int i, j;
  for (i = j = 0; a[i] && b[j]; j++)
    if (a[i] == b[j]) i++;
  return !a[i];
}
