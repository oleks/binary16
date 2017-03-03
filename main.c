#include <stdio.h>
#include "binary16.h"

int main() {
  binary16_t x;
  binary16_t y;
  binary16_t z;

  x = binary16_from_binary32(-1.6);
  printf("%x\n", x);
  y = binary16_from_binary32(666666.0);
  printf("%x\n", y);

  z = binary16_add(x, y);
}
