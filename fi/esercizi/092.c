/*
Scrivere un sottoprogramma che ricevuto in ingresso un array bidimensionale di
valori interi che appartengono senz’altro all’insieme \{0,1\} (e qualsiasi
parametro ritenuto strettamente necessario) e le coordinate di un suo punto (in
termini di indici), se in quel punto nell’array è presente un valore 0 trasforma
tutti gli 0 negli 8 elementi adiacenti in 1 e propaga tale effetto. L’effetto si
ha solo se i valori interessati sono 0 (e vengono trasformati in 1), altrimenti
l’effetto si interrompe.
*/

#define FILL  '#'
#define EMPTY ' '

#include <stdio.h>
#include <stdlib.h>

void draw(int, int, int[]);
void color(int, int, int[], int, int);

int main(int argc, char** argv) {
  int n, m, *g, x, y;
  scanf("%d%d", &n, &m);
  g = malloc(n * m * sizeof(int));
  for (x = 0; x < n; x++)
    for (y = 0; y < m; y++) scanf("%d", &g[x * m + y]);
  scanf("%d%d", &x, &y);
  draw(n, m, g);
  color(n, m, g, x, y);
  printf("\n");
  draw(n, m, g);
  free(g);
  return 0;
}

void draw(int n, int m, int g[]) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) putchar(g[i * m + j] ? FILL : EMPTY);
    printf("\n");
  }
}

int valid(int n, int m, int x, int y) {
  int a, b;
  a = (0 <= x && x < n);
  b = (0 <= y && y < m);
  return a && b;
}

void color(int n, int m, int g[], int x, int y) {
  if (g[x * m + y]) return;
  g[x * m + y] = 1;
  if (valid(n, m, x - 1, y - 1)) color(n, m, g, x - 1, y - 1);
  if (valid(n, m, x - 1, y + 0)) color(n, m, g, x - 1, y + 0);
  if (valid(n, m, x - 1, y + 1)) color(n, m, g, x - 1, y + 1);
  if (valid(n, m, x + 0, y - 1)) color(n, m, g, x + 0, y - 1);
  if (valid(n, m, x + 0, y + 1)) color(n, m, g, x + 0, y + 1);
  if (valid(n, m, x + 1, y - 1)) color(n, m, g, x + 1, y - 1);
  if (valid(n, m, x + 1, y + 0)) color(n, m, g, x + 1, y + 0);
  if (valid(n, m, x + 1, y + 1)) color(n, m, g, x + 1, y + 1);
}
