#include <stdio.h> // printf

#include "binary16.h"

#define EXP16_BITS (5)
#define FRC16_BITS (10)

#define EXP32_BITS (8)
#define FRC32_BITS (23)

#define EXP64_BITS (11)
#define FRC64_BITS (53)

#define EMIN16 (-14)
#define EMAX16 (15)

#define EBIAS16 (15)
#define EBIAS32 (127)
#define EBIAS64 (1023)

#define FMAX16 (0x3ff)

#define BIT_MASK(type) ((((uint64_t)1) << (type)) - 1)

#define EXP32_MASK (BIT_MASK(EXP32_BITS))
#define EXP64_MASK (BIT_MASK(EXP64_BITS))
#define FRC32_MASK (BIT_MASK(FRC32_BITS))
#define FRC64_MASK (BIT_MASK(FRC64_BITS))

#define PACK(sign, exp, frac) (((sign) << 15) | ((exp) << 10) | (frac))

#define POSINF16 ((uint16_t)(0x7c00)) // 0111 1100 0000 0000
#define NEGINF16 ((uint16_t)(0xfc00)) // 1111 1100 0000 0000

binary16_t
binary16_from_components(
    uint8_t sign, int16_t exp, uint64_t frac) {

  uint16_t retval = 0;

  if (exp < EMIN16) {
    retval = POSINF16;
  } else if (exp > EMAX16) {
    retval = NEGINF16;
  } else if (frac > FMAX16) {
    // TODO
  } else {
    retval = PACK(sign, exp, frac);
  }

  return retval;
}

typedef union {
  float f;
  uint32_t i;
} binary32_t;

binary16_t
binary16_from_binary32(float x) {
  binary32_t u;
  u.f = x;

  uint8_t   sign  = u.i >> 31;
  int16_t   exp   = ((int16_t)((u.i >> FRC32_BITS) & EXP32_MASK)) - EBIAS32;
  uint64_t  frac  = u.i & FRC32_MASK;

  printf("%d %d %lx\n", sign, exp, frac);

  return binary16_from_components(sign, exp, frac);
}

typedef union {
  double f;
  uint64_t i;
} binary64_t;

binary16_t
binary16_from_binary64(double x) {
  binary64_t u;
  u.f = x;

  uint8_t   sign  = u.i >> 63;
  int16_t   exp   = ((int16_t)((u.i >> FRC64_BITS) & EXP64_MASK)) - EBIAS64;
  uint64_t  frac  = u.i & FRC64_MASK;

  printf("%d %d %lx\n", sign, exp, frac);

  return binary16_from_components(sign, exp, frac);
}

binary16_t
binary16_add(binary16_t x, binary16_t y) {
  // TODO
  return 0;
}
