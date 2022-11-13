/*
Un algoritmo molto basilare di compressione di una stringa consiste nel
sostituire ogni gruppo di caratteri identici consecutivi con il carattere
seguito dal numero delle sue occorrenze. Si scriva un programma in linguaggio C
(ANSI 89) che acquisita in ingresso una stringa di al massimo 50 caratteri la
comprima. Si consideri che nella stringa compressa il conteggio delle
apparizioni di un carattere possa essere al massimo 9. Al termine
dell’elaborazione si vuole avere a disposizione sia la stringa originale, sia
quella compressa che viene poi visualizzata. Si assuma che la stringa sia
composta solo da caratteri minuscoli dell’alfabeto inglese.
*/

#define MAXC 50

#include <stdio.h>

int main(int argc, char** argv) {
  char s[MAXC + 1], r[MAXC << 1 | 1];
  int i, j, t;
  gets(s);
  i = j = 0;
  while (s[i]) {
    r[j] = s[i++];
    t    = 1;
    while (t < 9 && s[i] == r[j]) {
      i++;
      t++;
    }
    j++;
    r[j++] = t + '0';
  }
  r[j] = 0;
  printf("%s", r);
  return 0;
}
