/*
Scrivere un programma in C (ANSI 89) che acquisisce una sequenza di al più 100
valori interi e un intero strettamente positivo k. L’acquisizione della sequenza
termina quando l’utente inserisce un numero negativo o nullo, oppure quando
vengono acquisiti 100 valori. Il programma visualizza 1 se la sequenza contiene
almeno una coppia di valori tali che la loro somma sia k, 0 altrimenti, seguito
da un ’a-capo’. Per realizzare la soluzione si sviluppi un sottoprogramma
cercasomma che ricevuto in ingresso k, l’array contenente i dati e qualsiasi
altro parametro ritenuto strettamente necessario, restituisce 1 o 0 nel caso
trovi i due valori la cui somma è k.
*/

#define MAXN 10

#include <stdio.h>

int sumk(int, int[], int);

int main(int argc, char** argv) {
  int n, v[MAXN], k, t;
  n = 0;
  while (n < MAXN && scanf("%d", &v[n]) && v[n] > 0) n++;
  if (n < MAXN && v[n] <= 0) n--;
  scanf("%d", &k);
  t = sumk(n, v, k);
  printf("%d", t);
  return 0;
}

int sumk(int n, int v[], int k) {
  int i, j, f;
  f = 0;
  for (i = 0; !f && i < n; i++)
    for (j = i + 1; !f && j < n; j++) f = (v[i] + v[j] == k);
  return f;
}
