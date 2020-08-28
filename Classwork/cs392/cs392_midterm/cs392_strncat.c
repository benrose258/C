/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include "cs392_midterm.h"

int get_str_size(char *str) {
  int count = 0;
  while (str[count] != '\0') { // While we haven't reached the end of the string
    count++; // Increment the count
  }
  return count; // Return size of str
}

char *cs392_strncat(char *dest, char *src, unsigned n) {
  const int dest_size = get_str_size(dest); // Get the size of the dest string
  int count = 0; // Initialize while loop counter
  // While the counter is less than the maximum allowed bytes
  // and the src string is not at the end
  while (src[count] != '\0' && count < n) { // Initialize while loop
    dest[dest_size + count] = src[count]; // Set the destination's [original size + count] to be source[count]
    count++; // Increment the count
  }
  dest[dest_size + count] = '\0'; // Finally, append the null byte to the end of the destination string
	return dest; // Return the destination string
}
