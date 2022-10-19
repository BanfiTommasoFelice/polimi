/*
Si scriva un programma in linguaggio C (ANSI 89) che acquisisca una stringa di
esattamente 9 caratteri composta esclusivamente da ‘x’, ‘o’, si assuma che
l’utente inserisca correttamente la stringa. La stringa rappresenta una
configurazione del gioco del tris, dove i primi 3 caratteri corrispondono alla
prima riga, i secondi 3 alla seconda e gli ultimi 3 all’ultima riga. Si converta
la stringa ricevuta in ingresso in un modello del dato che rappresenti lo schema
del gioco del tris, ovvero un array bidimensionale quadrato di dimensione 3, e
si determini se la configurazione attuale è una configurazione vincente, ovvero
se c’è un tris. NOTA: si assuma che la stringa passata in ingresso sia una
configurazione valida per il gioco del tris (in relazione al numero di simboli
per tipo).
*/

#define N 3
#define M (N * N)

#include <stdio.h>

int main(int argc, char **argv) {
  char conf[M + 1], table[N][N];
  int i, v;
  gets(conf);
  for (i = 0; i < M; i++) table[i / N][i % N] = conf[i];
  v = 0;
  if (conf[0] == conf[1] && conf[1] == conf[2]) v = 1;
  if (conf[3] == conf[4] && conf[4] == conf[5]) v = 1;
  if (conf[6] == conf[7] && conf[7] == conf[8]) v = 1;
  if (conf[0] == conf[3] && conf[3] == conf[6]) v = 1;
  if (conf[1] == conf[4] && conf[4] == conf[7]) v = 1;
  if (conf[2] == conf[5] && conf[5] == conf[8]) v = 1;
  if (conf[0] == conf[4] && conf[4] == conf[8]) v = 1;
  if (conf[2] == conf[4] && conf[4] == conf[6]) v = 1;
  for (i = 0; i < M; i++) {
    printf("%c ", table[i / N][i % N]);
    if (i % N == N - 1) printf("\n");
  }
  printf("%d", v);
  return 0;
}
