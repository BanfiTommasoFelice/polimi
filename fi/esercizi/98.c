/*
Scrivere un programma in C (ANSI 89) che riceve in ingresso un array di 10
valori numeri interi. Costruire un nuovo array dove in corrispondenza di ogni
elemento dell’array iniziale si mette:
+ 0 se l’elemento i è non strettamente positivo,
+ 1 se l’elemento i è un numero perfetto,
+ 2 se l’elemento i è abbondante,
+ 3 se l’elemento i è difettivo
Per definizione un numero è perfetto se corrisponde alla somma dei suoi
divisori, escluso se stesso; abbondante se è minore della somma dei suoi
divisori, escluso se stesso; altrimenti è difettivo. Ad esempio: 6 e 28 sono
perfetti, 12 e 18 sono abbondanti, mentre 8 e 10 sono difettivi. Il programma
visualizza i valori inseriti, su una nuova riga la caratteristica del numero, ed
infine un istogramma verticale che rappresenta la quantità di numeri perfetti,
difettivi e abbondanti contenuti nell’array iniziale. Realizzare la propria
soluzione organizzandola in sottoprogrammi, come ritenuto più opportuno.
*/

#define N            10
#define NON_POSITIVE 0
#define PERFECT      1
#define ABUNDANT     2
#define DEFECTIVE    3

#include <stdio.h>

int sigma(int);

int main(int argc, char** argv) {
  int v[N], w[N], i, s;
  for (i = 0; i < N; i++) scanf("%d", &v[i]);
  for (i = 0; i < N; i++) {
    if (v[i] > 0) {
      s = sigma(v[i]);
      if (s < v[i])
        w[i] = DEFECTIVE;
      else if (s > v[i])
        w[i] = ABUNDANT;
      else
        w[i] = PERFECT;
    } else
      w[i] = NON_POSITIVE;
  }
  for (i = 0; i < N; i++) printf("%d ", w[i]);
  return 0;
}

int sigma(int n) {
  int s, m;
  s = 0;
  for (m = 1; m * m <= n; m++)
    if (n % m == 0) {
      if (n / m != m) s += n / m;
      s += m;
    }
  return s - n;
}
