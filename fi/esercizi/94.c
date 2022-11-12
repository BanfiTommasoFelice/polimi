/*
Scrivere un programma in C (ANSI 89) che acquisisce una sequenza di al più 20
valori interi, chiedendo all’utente inizialmente quanti valori vorrà fornire,
num. Il programma acquisisce num valori e memorizza in una opportuna struttura
dati la sequenza di valori i cui elementi sono strettamente crescenti,
trascurando i valori che risultano non essere ordinati. Al termine
dell’acquisizione il programma visualizza la lunghezza della sequenza, seguita,
su una nuova riga, dalla sequenza stessa. L’utente inserirà sempre un numero di
valori coerente con la richiesta. Avvalersi di due sottoprogrammi: fillarrord e
viewarr: il primo acquisisce i dati e memorizza i dati ritenuti validi, il
secondo visualizza il contenuto di un array.
*/

#define MAXN 20

#include <stdio.h>

int fillarrord(int, int[]);
void viewarr(int, int[]);

int main(int argc, char** argv) {
  int n, m, v[MAXN];
  scanf("%d", &n);
  m = fillarrord(n, v);
  viewarr(m, v);
  return 0;
}

int fillarrord(int n, int v[]) {
  int m, i;
  scanf("%d", &v[0]);
  m = 1;
  for (i = 1; i < n; i++) {
    scanf("%d", &v[m]);
    if (v[m] > v[m - 1]) m++;
  }
  return m;
}

void viewarr(int n, int v[]) {
  int i;
  for (i = 0; i < n; i++) printf("%d ", v[i]);
  printf("\n");
}
