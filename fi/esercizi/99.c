/*
Un k-mer è una sequenza di k caratteri.
Il sottoprogramma conta calcola e restituisce il numero di volte in cui un k-mer
kmer compare nella sequenza (di Dna) seq. Per esempio, il k-mer ACTAT compare 3
volte nella sequenza di Dna ACAACTATGCATACTATCGGGAACTATCCT. Si noti che il k-mer
ATA compare 3 volte (non 2) nella sequenza CGATATATCCATAG, poiché ci sono due
sottosequenze parzialmente sovrapposte. Si sviluppi il sottoprogramma conta, il
cui prototipo (con anche il nome dei parametri formali) è:

int conta(char seq[], char kmer[]);

In alcuni contesti, non è necessario trovare la sottosequenza esatta, ma è
sufficiente una approssimata, ossia che differisce da quella esatta di d
elementi. La differenza tra due sequenze di ugual dimensione viene misurata in
termini di distanza di Hamming ossia il numero di elementi diversi in posizione
corrispondente nelle due sequenze. Per esempio, le sequenze ATA e ATC hanno una
distanza pari a 1 (questa nozione di distanza di applica a sequenze di qualsiasi
tipo).

Si realizzi un sottoprogramma distanza che ricevute in ingresso due stringhe
calcoli e restituisca la distanza di Hamming. Nella realizzazione si tenga
presente che nell’impiego del sottoprogramma le due stringhe potrebbero avere
lunghezze diverse.

int distanza(char seq1[], char seq2[]);

Si realizzi un sottoprogramma contad che conta e restituisce il numero di volte
in cui un k-mer kmer compare nella sequenza seq, accettando anche delle forme
approssimate purché a distanza minore o uguale a d. La valutazione deve tenere
presente che l’intero k-mer deve essere contenuto nella sequenza, per cui: ATA
non è contenuto in modo approssimato nella sequenza CCAT con d = 1.

int contad(char seq[], char kmer[], int d);

Sviluppare un programma in C (ANSI 89) che acquisiti in ingresso una sequenza di
Dna di al più 100 caratteri, il k-mer (di al più 10 caratteri) e il livello di
approssimazione accettabile, calcola e visualizza (mediante i sottoprogrammi
prima specificati) il numero di k-mer esatti trovati nella sequenza seguito dal
numero di quelli approssimati.
*/

#define MAXC 100
#define MAXK 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(char[], char[], int);
int distance(char[], char[]);

int main(int argc, char** argv) {
  char dna[MAXC + 1], kmer[MAXK + 1];
  int d, a, b;
  scanf("%s%s%d", dna, kmer, &d);
  a = count(dna, kmer, 0);
  b = count(dna, kmer, d) - a;
  printf("%d %d", a, b);
  return 0;
}

int distance(char a[], char b[]) {
  int d, i;
  i = 0;
  d = (a[0] != b[0]);
  while (b[++i]) d += (a[i] != b[i]);
  return d;
}

/* KMP */
int _count(char a[], char b[]) {
  int n, m, c, *lps, i, j;
  n = strlen(a);
  m = strlen(b);
  if (n < m || !m) return 0;
  /* prefix function */
  lps    = malloc(m * sizeof(int));
  lps[0] = 0;
  i      = 1;
  j      = 0;
  while (i < m)
    if (b[i] == b[j])
      lps[i++] = ++j;
    else if (j)
      j = lps[j - 1];
    else
      lps[i++] = 0;
  /* calculation */
  c = i = j = 0;
  while (i < n && j < m) {
    if (a[i] == b[j]) {
      i++;
      j++;
    } else if (j)
      j = lps[j - 1];
    else
      i++;
    if (j == m) {
      c++; /* substring at pos i-j  */
      j = lps[j - 1];
    }
  }
  free(lps);
  return c;
}

/* TODO: implement an efficient algorirthm */
int count(char a[], char b[], int d) {
  int c, n, m, i;
  n = strlen(a);
  m = strlen(b);
  c = 0;
  for (i = 0; i <= n - m; i++)
    if (distance(&a[i], b) <= d) c++;
  return c;
}
