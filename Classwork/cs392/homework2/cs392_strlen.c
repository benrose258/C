/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include <stdio.h>
#include "cs392_string.h"

unsigned cs392_strlen(char *str) {
  int count = 0; // Initialize count
  if (str == NULL) { // Checking for if the string is null
    return -1; // Return -1, so that, upon execution, the user can discern between an empty string and a NULL string.
  }
  while (str[count] != '\0') { // While we haven't reached the end of the string
    count++; // Increment the count
  }
  return count; // Return size of str
}
