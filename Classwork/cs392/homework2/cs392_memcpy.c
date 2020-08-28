/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include <stdio.h>
#include "cs392_string.h"

void *cs392_memcpy(void *dst, void *src, unsigned num) {
  int count = 0;
  char *dst_point = (char *) dst;
  char *src_point = (char *) src;
  while (count < num) {
    dst_point[count] = src_point[count];
    count++;
  }
  return dst;
}
