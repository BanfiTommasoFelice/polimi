#ifndef GCD_H
#define GCD_H

#pragma once

#include "types.h"

u32 ctz(u64 n) {
  static const u32 MOD37[] = {
    32, 0,  1,  26, 2,  23, 27, 0,  3, 16, 24, 30, 28, 11, 0,  13, 4,  7,  17,
    0,  25, 22, 31, 15, 29, 10, 12, 6, 0,  21, 14, 9,  5,  20, 8,  19, 18,
  };
  u32 a, b;
  a = n & 0xffffffff;
  b = n >> 32;
  b = (a ? 0 : MOD37[(-b & b) % 37]);
  a = MOD37[(-a & a) % 37];
  return a + b;
}

u64 gcd(u64 a, u64 b) {
  u32 az, bz, s;
  i64 d;
  if (a == 0) return b;
  if (b == 0) return a;
  az = ctz(a);
  bz = ctz(b);
  s  = (az < bz ? az : bz);
  b >>= bz;
  while (a) {
    a >>= az;
    d  = b - a;
    az = ctz(d);
    b  = (a < b ? a : b);
    a  = (d < 0 ? -d : d);
  }
  return b << s;
}

#endif