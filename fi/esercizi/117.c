/*
Laboratorio: sudoku
*/

#define DIM   9
#define BLOCK 3
#define EMPTY 0
#define MIN   1
#define MAX   9

#define OPTIONS  7
#define EXIT     0
#define NEW_GAME 1
#define INSERT   2
#define REMOVE   3
#define VERIFY   4
#define LOAD     5
#define RELOAD   6

#define CORRECT "CORRETTA"
#define VALID   "VALIDA"
#define WRONG   "ERRATA"

#define ANGLE      '+'
#define HLINE      '-'
#define VLINE      '|'
#define MARKED     '*'
#define NOT_MARKED ' '
#define PAD        ' '
#define GAP        1

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

typedef int table_t[DIM][DIM];

int valid(int, int);
int allowed(int);
int unique(int, int *);
int length(int);

void table_clear(table_t);
void table_reset(table_t, int, int);
void table_set(table_t, int, int, int);
int table_check(table_t);
int table_complete(table_t);
int table_empty(table_t);

void ask_schema(table_t);
void ask_coordinate(int *, int *);
void ask_value(int *);
void load(table_t, table_t);

void menu(void);
int choose(void);
void print_schema(table_t);
void print_state(table_t, table_t);
void hline();

int main(int argc, char **argv) {
  table_t initial, current;
  int choice, redo;
  int x, y, v;
  redo = 1;
  do {
    if (redo || choice == NEW_GAME) {
      printf("inserisci schema di gioco: ");
      ask_schema(initial);
      while (!table_check(initial)) {
        printf("schema non valido, riprova: ");
        ask_schema(initial);
      }
      load(current, initial);
      redo = 0;
    } else if (choice == INSERT) {
      ask_coordinate(&x, &y);
      while (current[x][y] != EMPTY || initial[x][y] != EMPTY) {
        printf("impossibile scrivere la cella, riprova: ");
        ask_coordinate(&x, &y);
      }
      ask_value(&v);
      table_set(current, x, y, v);
    } else if (choice == REMOVE) {
      ask_coordinate(&x, &y);
      while (current[x][y] == EMPTY || initial[x][y] != EMPTY) {
        printf("impossibile svuotare la cella, riprova: ");
        ask_coordinate(&x, &y);
      }
      table_reset(current, x, y);
    } else if (choice == VERIFY) {
      if (table_check(current))
        if (table_complete(current))
          printf(CORRECT);
        else
          printf(VALID);
      else
        printf(WRONG);
      printf("\n");
    } else if (choice == LOAD) {
      ask_schema(current);
      if (table_check(current))
        if (table_complete(current))
          printf(CORRECT);
        else
          printf(VALID);
      else
        printf(WRONG);
      printf("\n");
    } else if (choice == RELOAD) {
      load(current, initial);
    }
    print_state(current, initial);
    if (table_check(current) && table_complete(current)) {
      printf("Congratulazioni!\n");
      redo = 1;
    }
    if (!redo) choice = choose();
  } while (choice != EXIT);
  return 0;
}

void menu(void) {
  int i;
  i = 0;
  printf("%d - avvia una nuova partita\n", ++i);
  printf("%d - inserisci valore\n", ++i);
  printf("%d - cancella valore\n", ++i);
  printf("%d - verifica la soluzione attuale\n", ++i);
  printf("%d - carica una soluzione e verificala\n", ++i);
  printf("%d - riavvia partita attuale\n", ++i);
  printf("%d - esci\n", EXIT);
}

int choose(void) {
  int choice;
  menu();
  printf("opzione: ");
  fflush(stdin);
  scanf("%d", &choice);
  while (!((1 <= choice && choice < OPTIONS) || choice == EXIT)) {
    printf("opzione non valida, riprova: ");
    scanf("%d", &choice);
  }
  return choice;
}

void table_clear(table_t t) {
  int i, j;
  for (i = 0; i < DIM; i++)
    for (j = 0; j < DIM; j++) /**/
      table_reset(t, i, j);
}

void table_reset(table_t t, int i, int j) {
  if (valid(i, j)) t[i][j] = EMPTY;
}

int valid(int i, int j) { return 0 <= i && i < DIM && 0 <= j && j < DIM; }

int allowed(int n) { return MIN <= n && n <= MAX; }

void table_set(table_t t, int i, int j, int x) {
  if (valid(i, j) && allowed(x)) t[i][j] = x;
}

int unique(int n, int *v) {
  int freq[MAX - MIN + 1], i, multiple;
  for (i = 0; i < MAX - MIN + 1; i++) freq[i] = 0;
  for (i = 0; i < n; i++)
    if (allowed(v[i])) freq[v[i] - MIN]++;
  multiple = 0;
  for (i = 0; !multiple && i < MAX - MIN + 1; i++) multiple = (freq[i] > 1);
  return !multiple;
}

int table_check(table_t t) {
  int i, j, k, valid;
  int set[DIM], block[BLOCK * BLOCK];
  valid = 1;
  for (i = 0; valid && i < DIM; i++) {
    for (j = 0; j < DIM; j++) set[j] = t[i][j];
    valid = unique(DIM, set);
  }
  for (j = 0; valid && j < DIM; j++) {
    for (i = 0; i < DIM; i++) set[i] = t[i][j];
    valid = unique(DIM, set);
  }
  for (i = 0; valid && i < DIM; i += BLOCK)
    for (j = 0; valid && j < DIM; j += BLOCK) {
      for (k = 0; k < BLOCK * BLOCK; k++)
        block[k] = t[i + k / BLOCK][j + k % BLOCK];
      valid = unique(BLOCK * BLOCK, block);
    }
  return valid;
}

void load(table_t dest, table_t src) {
  int i, j;
  if (src)
    for (i = 0; i < DIM; i++)
      for (j = 0; j < DIM; j++) /**/
        table_set(dest, i, j, src[i][j]);
  else
    ask_schema(dest);
}

void ask_schema(table_t t) {
  int i;
  char schema[DIM * DIM + 1];
  scanf("%s", schema);
  table_clear(t);
  for (i = 0; i < DIM * DIM; i++)
    table_set(t, i / DIM, i % DIM, (int)schema[i] - '0');
}

int table_complete(table_t t) {
  int i, j, complete;
  complete = 1;
  for (i = 0; complete && i < DIM; i++)
    for (j = 0; complete && j < DIM; j++) /**/
      complete = (t[i][j] != EMPTY);
  return complete;
}

int table_empty(table_t t) {
  int i, j, empty;
  empty = 1;
  for (i = 0; empty && i < DIM; i++)
    for (j = 0; empty && j < DIM; j++) /**/
      empty = (t[i][j] == EMPTY);
  return empty;
}

void ask_coordinate(int *x, int *y) {
  printf("inserisci coordinate: ");
  scanf("%d%d", x, y);
  while (!valid(*x, *y)) {
    printf("coordinate non valide, riprova: ");
    scanf("%d%d", x, y);
  }
  (*x)--;
  (*y)--;
}

void ask_value(int *v) {
  printf("inserisce valore: ");
  scanf("%d", v);
  while (!allowed(*v)) {
    printf("valore non ammesso, riprova: ");
    scanf("%d", v);
  }
}

int length(int n) {
  const int BASE = 10;
  int l;
  l = !n;
  while (n) {
    l++;
    n /= BASE;
  }
  return l;
}

void hline() {
  const int M = length(MAX);
  int i, j, k;
  putchar(ANGLE);
  for (i = 0; i < DIM / BLOCK; i++) {
    for (k = 0; k < GAP; k++) putchar(HLINE);
    for (j = 0; j < BLOCK; j++) {
      for (k = 0; k < M; k++) putchar(HLINE);
      putchar(HLINE);
      for (k = 0; k < GAP; k++) putchar(HLINE);
    }
    putchar(ANGLE);
  }
  putchar('\n');
}

void print_state(table_t state, table_t mask) {
  const int M = length(MAX);
  int i, j, k;
  char *fmt;
  fmt = malloc((length(M) + 4) * sizeof(char));
  if (!fmt) ERROR(fmt);
  sprintf(fmt, "%%0%dd", M);
  hline();
  for (i = 0; i < DIM; i++) {
    putchar(VLINE);
    for (k = 0; k < GAP; k++) putchar(PAD);
    for (j = 0; j < DIM; j++) {
      if (state[i][j] != EMPTY)
        printf(fmt, state[i][j]);
      else
        for (k = 0; k < M; k++) putchar(PAD);
      putchar(mask[i][j] ? MARKED : NOT_MARKED);
      for (k = 0; k < GAP; k++) putchar(PAD);
      if ((j + 1) % BLOCK == 0) {
        putchar(VLINE);
        for (k = 0; k < GAP; k++) putchar(PAD);
      }
    }
    putchar('\n');
    if ((i + 1) % BLOCK == 0) hline();
  }
  free(fmt);
}