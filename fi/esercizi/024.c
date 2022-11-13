/*
Si scriva un programma in C (ANSI 89) che acquisisce
+ un numero reale positivo di partenza (il saldo del conto corrente);
+ un secondo reale numero positivo che rappresenta il tasso di interesse
applicato dalla banca (esempio 0.01 = 1%);
+ un terzo numero reale positivo che rappresenta il saldo desiderato del conto;
Il programma determina dopo quanti anni viene raggiunto (ed eventualmente
superato) l’obiettivo ed il saldo finale raggiunto. Il programma continua a
richiedere i dati del problema fino a quando i vincoli esposti non vengono
rispettati. NOTA: si ricorda che dato il saldo dell’anno i, si, ed il tasso di
interesse t, il saldo dell’anno i+1 è s(i+1) = si + si * t.
*/

#include <stdio.h>

int main(int argc, char** argv) {
  float init, rate, target, tmp;
  int year;
  scanf("%f%f%f", &init, &rate, &target);
  year = 0;
  tmp  = init;
  while (tmp < target) {
    year++;
    tmp += tmp * rate;
  }
  printf("%d", year);
  return 0;
}
