#ifndef BITSET_H
#define BITSET_H

#pragma once

#include <err.h>
#include <stdlib.h>

typedef unsigned long bs_word_t;

typedef struct bitset_s {
  bs_word_t *words;
  size_t n, size;
} bitset_t;

static const size_t BS_BITS_PER_WORD = sizeof(bs_word_t) * 8;

__attribute__((const)) static size_t bs_word_index(size_t i) {
  return i / BS_BITS_PER_WORD;
}

__attribute__((const)) static size_t ctz(size_t n) {
  static const size_t MOD         = 67;
  static const size_t MOD_TABLE[] = {
    64, 0,  1,  39, 2,  15, 40, 23, 3,  12, 16, 59, 41, 19, 24, 54, 4,
    64, 13, 10, 17, 62, 60, 28, 42, 30, 20, 51, 25, 44, 55, 47, 5,  32,
    65, 38, 14, 22, 11, 58, 18, 53, 63, 9,  61, 27, 29, 50, 43, 46, 31,
    37, 21, 57, 52, 8,  26, 49, 45, 36, 56, 7,  48, 35, 6,  34, 33, 0
  };
  return MOD_TABLE[(-n & n) % MOD];
}

/* modifiers */

void bitset_clear(bitset_t *bs) {
  memset(bs->words, 0, bs->size * sizeof(bs_word_t));
}

void bitset_set(bitset_t *bs, size_t i) {
  bs->words[bs_word_index(i)] |= 1ul << (i % BS_BITS_PER_WORD);
}

void bitset_reset(bitset_t *bs, size_t i) {
  bs->words[bs_word_index(i)] &= ~(1ul << (i % BS_BITS_PER_WORD));
}

void bitset_flip(bitset_t *bs, size_t i) {
  bs->words[bs_word_index(i)] ^= 1ul << (i % BS_BITS_PER_WORD);
}

/* constructor and descructor */

void bitset_init(bitset_t *bs, size_t n) {
  if (n == 0) ERROR(n);
  if (!bs) ERROR(bs);
  bs->n     = n;
  bs->size  = n / BS_BITS_PER_WORD + !!(n % BS_BITS_PER_WORD);
  bs->words = malloc(bs->size * sizeof(bs_word_t));
  if (!bs->words) ERROR(bs->words);
  bitset_clear(bs);
}

bitset_t *bitset_new(size_t n) {
  bitset_t *bs = malloc(sizeof(bitset_t));
  if (!bs) ERROR(bs);
  bitset_init(bs, n);
  return bs;
}

void bitset_free(bitset_t *bs) {
  free(bs->words);
  free(bs);
}

/* element access */

int bitset_test(bitset_t *bs, size_t i) {
  return !!(bs->words[bs_word_index(i)] & (1ul << (i % BS_BITS_PER_WORD)));
}

/* algorithms */

int bitset_all(bitset_t *bs) {
  size_t i;
  int all;
  all = 1;
  for (i = 0; all && i < bs->size - 1; i++)
    if (bs->words[i] != ~0ul) all = 0;
  return all && bs->words[i] == (1ul << (bs->n % BS_BITS_PER_WORD)) - 1;
}

int bitset_any(bitset_t *bs) {
  size_t i;
  int any;
  any = 0;
  for (i = 0; !any && i < bs->size; i++)
    if (bs->words[i] != 0ul) any = 1;
  return any;
}

int bitset_none(bitset_t *bs) {
  size_t i;
  int none;
  none = 1;
  for (i = 0; none && i < bs->size; i++)
    if (bs->words[i] != 0ul) none = 0;
  return none;
}

size_t bitset_count(bitset_t *bs) {
  size_t cnt, i;
  bs_word_t w;
  cnt = 0;
  for (i = 0; i < bs->size; i++) {
    w = bs->words[i];
    while (w) {
      cnt++;
      w &= w - 1;
    }
  }
  return cnt;
}

size_t bitset_first(bitset_t *bs) {
  size_t i, res;
  bs_word_t w;
  res = bs->n;
  for (i = 0; res == bs->n && i < bs->size; i++) {
    w = bs->words[i];
    if (w) res = i * BS_BITS_PER_WORD + ctz(w);
  }
  return res;
}

size_t bitset_nth(bitset_t *bs, size_t n) {
  size_t i, cnt;
  bs_word_t w;
  cnt = 0;
  for (i = 0; i < bs->size; i++) {
    w = bs->words[i];
    while (w) {
      if (cnt == n) return i * BS_BITS_PER_WORD + ctz(w);
      cnt++;
      w &= w - 1;
    }
  }
  return bs->n;
}

void bitset_not(bitset_t *in, bitset_t *out) {
  size_t i;
  if (in->size != out->size) ERROR(in->size != out->size);
  for (i = 0; i < in->size; i++) out->words[i] = ~in->words[i];
}

void bitset_or(bitset_t *in1, bitset_t *in2, bitset_t *out) {
  size_t i;
  if (in1->size != in2->size) ERROR(in1->size != in2->size);
  if (in1->size != out->size) ERROR(in1->size != out->size);
  for (i = 0; i < in1->size; i++) out->words[i] = in1->words[i] | in2->words[i];
}

void bitset_and(bitset_t *in1, bitset_t *in2, bitset_t *out) {
  size_t i;
  if (in1->size != in2->size) ERROR(in1->size != in2->size);
  if (in1->size != out->size) ERROR(in1->size != out->size);
  for (i = 0; i < in1->size; i++) out->words[i] = in1->words[i] & in2->words[i];
}

void bitset_xor(bitset_t *in1, bitset_t *in2, bitset_t *out) {
  size_t i;
  if (in1->size != in2->size) ERROR(in1->size != in2->size);
  if (in1->size != out->size) ERROR(in1->size != out->size);
  for (i = 0; i < in1->size; i++) out->words[i] = in1->words[i] ^ in2->words[i];
}

#endif