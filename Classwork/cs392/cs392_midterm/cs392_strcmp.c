/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

 #include "cs392_midterm.h"

// This function compares the strings s1 and s2. It returns an integer
//  less than, equal to, or greater than zero if s1 is found, respectively, to be
//  less than, to match, or be greater than s2.
int cs392_strcmp(char *s1, char *s2) {
	const int s1_size = get_str_size(s1); // Acquire size of s1
  const int s2_size = get_str_size(s2); // Acquire size of s2
  if (s1_size < s2_size) { // If s1 is smaller than s2 (in string length)
    return -1; // Return an integer less than 0 if s1 < s2
  }
  if (s1_size > s2_size) { // If s1 is larger than s2 (in string length)
    return 1; // Return an integer greater than 0 if s1 > s2
  }
  // Else, the string length of s1 and s2 are equal.
  // Further investigation is necessary.
  int count = 0; // Initialize counter for while loop
  while (count < s1_size) {
    // If the ASCII value of s1[count] less than the ASCII value of s2[count]
    if ((unsigned char) s1[count] < (unsigned char) s2[count]) {
      return -1; // Return an integer less than 0 if s1 < s2
    }
    // If the ASCII value of s1[count] greater than the ASCII value of s2[count]
    if ((unsigned char) s1[count] > (unsigned char) s2[count]) {
      return 1; // Return an integer greater than 0 if s1 > s2
    }
    // Else, the ASCII values of s1 and s2 at count are equal.
    // Further investigation into s1 and s2 characters necessary.
    count++; // Increment count to search next character.
  }

  // If we get to this point, the string length of s1 and s2 is equal,
  // the ASCII values of every character in s1 and s2 are equal,
  // and we can therefore determine that
  // the strings s1 and s2 are equal.
	return 0; // And will therefore return zero.
}
