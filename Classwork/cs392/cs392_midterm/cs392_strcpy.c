/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include "cs392_midterm.h"

// strcpy: Copy the string pointed to by src,
//  including the terminating null byte ('\0'),
//  to the buffer pointed to by dest.
char *cs392_strcpy(char *dest, char *src) { // Initialize function
  int count = 0; // Initialize counter for while loop
  while (src[count] != '\0') { // While we are not at the end of the source string
    dest[count] = src[count]; // Overwrite (copy over) dest at count with src at count
    count++; // Increment count
  }
  dest[count] = '\0'; // Finally, re-add the null byte
	return dest; // Return the destination string
}
