/*
Scrivere un sottoprogramma ometti che riceve in ingresso il nome di un file
ASCII sorgente src, il nome di un file destinazione dst, e un vocabolo voc
(stringa di al più 30 caratteri): il sottoprogramma crea il file destinazione
ricopiando il contenuto del file sorgente tranne il vocabolo voc. Il file
sorgente contiene esclusivamente vocaboli, separati da uno spazio, e null’altro
(niente segni di interpunzione). Il sottoprogramma restituisce al chiamante il
numero di volte che ha trovato e omesso di copiare il vocabolo voc. Nel caso si
abbiano problemi nell’ accesso ai file, si visualizzi il messaggio ERRORE e si
restituisca -1.
Modificare il sottoprogramma ometti in modo tale che venga omesso nel file
destinazione il vocabolo voc indipendentemente dall’uso di caratteri maiuscoli o
minuscoli.
*/

#define CASE_INSENSITIVE
#define MAXC     30
#define LOWER(x) ((x) | 0x20)

#include <stdio.h>
#include <string.h>

void usage(char *);
int cmp(char *, char *);
int omit(char *, char *, char *);

int main(int argc, char **argv) {
  if (argc == 4)
    printf("%d", omit(argv[1], argv[2], argv[3]));
  else
    usage(argv[0]);
  return (argc != 4);
}

void usage(char *p) { printf("usage: %s source destination string\n", p); }

int cmp(char *a, char *b) {
  while (
#ifdef CASE_INSENSITIVE
      LOWER(*a) == LOWER(*b)
#else
      *a == *b
#endif
      && *a && *b) {
    a++;
    b++;
  }
  return (*a) - (*b);
}

int omit(char *src, char *dst, char *s) {
  FILE *fsrc, *fdst;
  int cnt;
  char current[MAXC + 1];
  fsrc = fopen(src, "r");
  fdst = fopen(dst, "w");
  if (!fsrc || !fdst) {
    printf("ERRORE");
    return -1;
  }
  cnt = 0;
  while (fscanf(fsrc, "%s", current) != EOF)
    if (cmp(current, s))
      fprintf(fdst, "%s ", current);
    else
      cnt++;
  fclose(fsrc);
  fclose(fdst);
  return cnt;
}