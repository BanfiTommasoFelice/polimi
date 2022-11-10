/*
Il genio della lampada vi fa recapitare un messaggio in cui vi rivela
l’andamento in borsa dei titoli della società GEN-IA-LE per i prossimi due anni,
e questa è l’occasione per guadagnare qualche soldo. Il messaggio purtroppo si
smaterializzerà nell’arco di un’ora per cui è necessario riuscire a trovare
velocemente come utilizzare l’informazione. L’informazione consiste nel fornire
il prezzo del titolo iniziale, e dire, per ogni giorno, la variazione del valore
del titolo alla chiusura rispetto al giorno precedente. Si consideri di
acquistare la mattina all’apertura, alla quotazione di chiusura del giorno
prima, e di vendere a termine giornata, quindi alla quotazione di chiusura del
giorno. In ingresso il programma riceve un primo intero che rappresenta il
valore iniziale del titolo, quindi acquisisce 20 valori interi che costituiscono
le variazioni di quotazione del titolo dei 20 giorni successivi. Realizzate il
programma che vi consente di guadagnare di più, individuando il giorno in cui
acquistare (`a`) e quello in cui vendere (`v`). Per semplicità, realizzate prima
un programma che ipotizzi che il vostro capitale sia infinito, e realizzate poi
un programma che riceva in ingresso anche il capitale `C` a vostra disposizione
(per cui il numero di azioni che potete acquistare dipende dal loro valore).
*/

/* #define CAPITAL */
#define N 20

#include <stdio.h>

int main(int argc, char** argv) {
  freopen("input.txt", "r", stdin);
  int p, d[N + 1], b[N + 1];
  int i;
  scanf("%d", &p);
  for (i = 0; i < N; i++) scanf("%d", &d[i + 1]);
  d[0] = p;
  for (i = 0; i < N; i++) d[i + 1] += d[i];
  b[N] = 0;
  for (i = N - 1; i >= 0; i--)
    b[i] = (d[i] >= d[i + 1 + b[i + 1]] ? 0 : b[i + 1] + 1);
  /* TODO: finish the program */
  return 0;
}
