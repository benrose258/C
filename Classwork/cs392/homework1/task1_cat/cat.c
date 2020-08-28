/*
I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
Date: 2/11/19
*/

#include <stdio.h>
#include <stdlib.h>

/*
Used for organization: User can look up error number and return statement
to see where they are receiving an error
*/
void errorPrinter(int errno) {
  // Report, with spacing and organization, the error and error number.
  printf(" [Error code=%d]\n", errno);
}

int main(int argc, char ** argv) {
  if (argc != 2) { // If incorrect number of args are given
    printf("Usage: ./cat <name of file>"); // Return a usage message
    errorPrinter(1); // Print error message, using error code 1
    return 1; // And return 1 to indicate an error
  }

  FILE *my_file = fopen(argv[1], "r"); // Open the file that the user supplies in the second argument
  if (my_file == NULL) { // If read is unsuccessful, the pointer to the file will be null.
    printf("Error: The file \"");
    printf(argv[1]);
    printf("\" does not exist.");// [Error code %d]\n", errno);
    errorPrinter(2); // Print error message, using error code 2
    return 2; // And return corresponding error code 2
  }

  char *file_data; // Initializing the character array that will store the file data
  int file_size; // Initializing the variable that will hold the size of the file
  fseek(my_file, 0L, SEEK_END); // Look for the end of the file in memory to determine file size
  file_size = ftell(my_file); // Set the file size to the current position in memory, which is currently the end

  file_data = malloc(file_size); // Dynamically allocate memory with the size of the file
  rewind(my_file); // Sets the file back to the beginning
  fread(file_data, 1, file_size, my_file);

  fgets(file_data, file_size, my_file); // Get the data from the file
  fputs(file_data, stdout); // Output the file_data to stdout, which is literally standard output
  free(file_data); // Free up the memory allocated for file_data

  fclose(my_file); // Finally, close the file.
  return 0; // Program exits with the value 0, indicating success.
}
