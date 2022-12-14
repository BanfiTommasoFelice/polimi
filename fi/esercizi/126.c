/*
I numeri di Catalan sono una successione C_n di interi positivi. Il nome di
questi numeri è stato scelto in onore del matematico belga Eugène Charles
Catalan (1814-1884) che li aveva studiati intorno al 1838 per stabilire in
quanti modi si può ricondurre il prodotto di r fattori ad una successione di
prodotti a coppie. I numeri di Catalan si possono ottenere ricorsivamente,
secondo la seguente relazione: C_0=1 C_n=∑_(i=0)^(n-1) C_i × C_(n-i-1).
Si scriva una funzione ricorsiva cat che, ricevuto un numero n come parametro
formale, ritorna il valore di Cn. Si scriva poi il programma principale che
acquisisca dall’utente un numero intero positivo val (e finché non é tale lo
richiede) e quindi calcola e visualizza i primi val+1 numeri di Catalan, da C_0
a C_val.
*/

#define OPTIMIZED

#include <stdio.h>
#include <stdlib.h>

#ifdef OPTIMIZED
int catalan(int, int *);
void precompute(int, int *);
#else
int catalan(int);
#endif

int main(int argc, char **argv) {
  int n, i;
#ifdef OPTIMIZED
  int *v;
#endif
  do scanf("%d", &n);
  while (n < 1);
#ifdef OPTIMIZED
  v = calloc(n + 1, sizeof(int));
  precompute(n, v);
  for (i = 0; i <= n; i++) printf("%d ", v[i]);
  free(v);
#else
  for (i = 0; i <= n; i++) printf("%d ", catalan(i));
#endif
  return 0;
}

#ifdef OPTIMIZED

int catalan(int n, int *v) {
  int i, sum;
  if (v[n]) return v[n];
  sum = 0;
  for (i = 0; i < n; i++) sum += catalan(i, v) * catalan(n - i - 1, v);
  return (v[n] = sum);
}

void precompute(int n, int *v) {
  int i;
  v[0] = 1;
  for (i = 1; i <= n; i++) v[i] = catalan(i, v);
}

#else

int catalan(int n) {
  int i, sum;
  if (!n) return 1;
  sum = 0;
  for (i = 0; i < n; i++) sum += catalan(i) * catalan(n - i - 1);
  return sum;
}

#endif