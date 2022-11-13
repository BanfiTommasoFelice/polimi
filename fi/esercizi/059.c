/*
Realizzare il programma in linguaggio C (ANSI 89) che offre le funzionalità
indicate dal menù, avvalendosi di un sottoprogramma per ogni funzionalità. La
risposta alle opzioni 2 e 4 è sempre un 1 quando vero, uno 0 quando falso. Si
ipotizzi che l’utente prima di selezionare una voce tra 2 e 4 avrà senz’altro
selezionato prima la voce 1. Quando il programma termina, visualizza il
messaggio “ciao!” e tiermina.
Nel programma generale, aggiungere un sottoprogramma per la visualizzazione di
un messaggio “Vero” o “Falso” a sostituzione dei valori 1 o 0.
*/

#define TRUE  "vero"
#define FALSE "falso"

#include <stdio.h>

int menu(void);
int choose(void);
int prime(int);
int factorial(int);
int palindrome(int);

int main(int argc, char** argv) {
  int s, n, r;
  do {
    s = choose();
    if (s == 1)
      scanf("%d", &n);
    else if (s == 2)
      r = prime(n);
    else if (s == 3)
      r = factorial(n);
    else if (s == 4)
      r = palindrome(n);
    if (1 < s && s < 5)
      if (s == 3)
        printf("%d\n", r);
      else
        printf("%s\n", (r ? TRUE : FALSE));
  } while (s);
  printf("ciao!\n");
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

int prime(int n) {
  int p, i;
  p = (n < 4 ? n > 1 : (n % 2 && n % 3));
  for (i = 5; p && i * i <= n; i += 6) p = (n % i && n % (i + 2));
  return p;
}

int factorial(int n) {
  int f;
  f = (n ? n : (n = 1));
  while (--n) f *= n;
  return f;
}

int palindrome(int n) {
  int p, l, i;
  char s[sizeof(int) << 3];
  l = sprintf(s, "%d", n);
  p = 1;
  for (i = 0; p && i < l / 2; i++) p = (s[i] == s[l - i - 1]);
  return p;
}
