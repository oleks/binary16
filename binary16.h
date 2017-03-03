#ifndef BINARY16
#define BINARY16

#include <stdint.h>         // uint16_t

typedef uint16_t binary16_t;

binary16_t binary16_from_binary32(float x);
binary16_t binary16_from_binary64(double x);

float binary16_to_binary32(binary16_t);
double binary16_to_binary64(binary16_t);

binary16_t binary16_add(binary16_t x, binary16_t y);

#endif // BINARY16
