/*
Una applicazione richiede di scegliere il proprio nome utente nel rispetto di
alcune regole e si vuole realizzare un programma che acquisisca e verifichi il
nome scelto. Scrivere il sottoprogramma valido che ricevuti in ingresso il nome
scelto (usrname), due interi (min e max) e una stringa (speciali) verifica che
esso rispetti le seguenti regole:
+ deve essere di almeno min caratteri,
+ non deve superare la lunghezza di max caratteri,
+ deve contenere almeno un carattere appartenente ai caratteri presenti nella
stringa speciali. Nel caso in cui tutte le regole siano rispettate, il nome
utente scelto è valido e il sottoprogramma restituisce 1, in caso contrario il
sottoprogramma restituisce 0. *Nota: non effettuare elaborazioni inutili e/o
inefficienti: la soluzione proposta verrà valutata anche in relazione a questo
aspetto.*
Scrivere un programma che acquisisce dall’utente una stringa di al più 20
caratteri e verifica che questa contenga un nome utente valido (avvalendosi del
sottoprogramma valido), e fino a che non è tale continua a richiederla. Quando
le regole sono rispettate il programma chiama il sottoprogramma StartApp che
riceve in ingresso il nome utente (il prototipo è riportato di seguito) e
realizza la funzionalità desiderata. int StartApp(char []); I vincoli per la
validità del nome utente sono una lunghezza compresa nell’intervallo [8; 15] e
un insieme dei caratteri speciali costituito dai caratteri ’$’ ’#’ ’%’ ’&’.
*/

#define MAXC    20
#define MINL    8
#define MAXL    15
#define SPECIAL "$#%&"

#include <stdio.h>
#include <string.h>

int valid(char[], int, int, char[]);
int StartApp(char[]);

int main(int argc, char** argv) {
  char username[MAXC + 1];
  do scanf("%s", username);
  while (!valid(username, MINL, MAXL + 1, SPECIAL));
  return StartApp(username);
}

int valid(char username[], int min, int max, char special[]) {
  int i, t;
  i = t = 0;
  t     = strchr(special, username[0]) != NULL;
  while (username[++i]) {
    if (!t) t = strchr(special, username[i]) != NULL;
  }
  return min <= i && i < max && t;
}

int StartApp(char username[]) {
  printf("hello %s", username);
  return 0;
}
