/*
Si consideri un corso X in cui l’esame è composto da due compitini, ciascuno
valutato in trentesimi. Condizione necessaria per essere promossi è che entrambi
i compitini siano sufficienti e in tal caso il voto finale è calcolato come
media dei due valori. Si noti che il voto finale è un intero arrotondato per
eccesso e quindi l’eventuale parte decimale non va considerata. Si realizzi un
programma in linguaggio C ANSI che acquisisce due valori interi che
rappresentano i punteggi ottenuti da uno studente nelle due prove in itinere; si
assuma in prima istanza che l’utente inserisca correttamente dei valori compresi
tra 0 e 30. Il programma valuta se lo studente è stato promosso o bocciato
visualizzando un 1 o 0; in caso positivo il programma deve anche visualizzare il
voto ottenuto.
Migliorare poi il programma aggiungendo un controllo di validità dei dati
inseriti, cioè che ciascun punteggio deve essere compreso tra 0 e 30; nel caso
almeno uno dei dati sia non consistente, il programma deve visualizzare -1.
*/

#define PASS       1
#define FAIL       0
#define IMPOSSIBLE -1
#define MARK_SUFF  18
#define MARK_MIN   0
#define MARK_MAX   30

#include <stdio.h>

int main(int argc, char** argv) {
  unsigned a, b, avg;
  int result;
  scanf("%u%u", &a, &b);
  if (a > MARK_MAX || a < MARK_MIN || b > MARK_MAX || b < MARK_MIN) {
    result = IMPOSSIBLE;
  } else {
    if (a >= MARK_SUFF && b >= MARK_SUFF) {
      avg = (a + b) / 2;
      if (a % 2 != b % 2) avg++;
      result = PASS;
    } else
      result = FAIL;
  }
  if (result == PASS)
    printf("%d", avg);
  else
    printf("%d", result);
  return 0;
}
