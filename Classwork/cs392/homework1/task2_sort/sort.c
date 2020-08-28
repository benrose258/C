/*
I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
Date: 2/12/19
*/

#include"sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Used for organization: User can look up error number and return statement
to see where they are receiving an error
*/
void errorPrinter(int errno) {
  // Report, with spacing and organization, the error and error number.
  printf(" [Error code=%d]\n", errno);
}

int compare (const void * a, const void * b) {
  return (*(int*)a - *(int*)b);
}

int main(int argc, char ** argv) {
  if (argc != 3) { // If the program is given the incorrect number of arguments
    printf("Usage: ./sort <name of input file> <name of output file>"); // Print usage message
    errorPrinter(1); // Print error message, using error code 1
    return 1; // Return 1 to indicate the corresponding error code
  }

  FILE *input_file = fopen(argv[1], "r"); // Open the input file
  if (input_file == NULL) { // If reading the provided file fails
    printf("Error: The file \"%s\" does not exist.", argv[1]);
    errorPrinter(2); // Print error message, using error code 2
    return 2; // Return 2 to indicate failure and the error location
  }

  char *input_file_data; // Initializing the character array that will store the file data
  int file_size; // Initializing the variable that will hold the size of the file. The size will be the same for both.
  fseek(input_file, 0L, SEEK_END); // Look for the end of the file in memory to determine file size
  file_size = ftell(input_file); // Set the file size to the current position in memory, which is currently the end

  input_file_data = malloc(file_size); // Dynamically allocate memory with the size of the input_file
  rewind(input_file); // Sets the file back to the beginning
  fread(input_file_data, 1, file_size, input_file); // Reads the data from the input_file

  fgets(input_file_data, file_size, input_file); // Get the data from the input_file

  FILE *output_file_erase = fopen(argv[2], "w"); // Create the file specified in argv[2]. This does not appear to ever fail.
  fclose(output_file_erase); // Now close and erase the file, to make way for new data.
  FILE *output_file = fopen(argv[2], "a"); // Create the output file, with permissions to add to its end.

  FILE *input_file_reopen = fopen(argv[1], "r"); // Create second copy of input file

  char *input_file_reopen_data; // Create second copy of input file data
  input_file_reopen_data = malloc(file_size); // With the size of the input file (determined before)

  fread(input_file_reopen_data, 1, file_size, input_file_reopen); // Reads the data from the input_file_reopen
  rewind(input_file_reopen); // Rewind the input file copy to its beginning

  char *token = malloc(file_size); // Token function to extract numbers from string file
  int temp_storage_size = 0; // Size of temporary storage, will be updated.

  token = strtok(input_file_data, "\n"); // Begin stringtoken function, searching for newline
  while (token != NULL) { // If we aren't at the end of the file
    temp_storage_size++; // Increase the size of temporary storage for the amount of numbers found.
    token = strtok(NULL, "\n"); // Restart while loop to look for next number
  }

  int temp_storage[temp_storage_size]; // Create an array of integers of the size of how many integers are in input file
  int storage_counter = 0; // Tracking the index in temp_storage

  token = strtok(input_file_reopen_data, "\n"); // token is now equal to another instance of the input file's data, since the original variable is used up
  while (token != NULL) { // If we aren't at the end of the file
    temp_storage[storage_counter] = atoi(token); // The array at storage counter is the corresponding number
    storage_counter++; // Increment counter

    token = strtok(NULL, "\n"); // Restart while loop
  }

  qsort(temp_storage, temp_storage_size, 4, compare); // Sort the numbers in the temp_storage array

  for(int i = 0; i < temp_storage_size; i++) { // Printing binary to output file
    for (int j = 31; j >= 0; j--) { // For all 32 bits in a 4 byte integer
      fprintf(output_file, "%d", temp_storage[i] >> j & 1); // Append the bit to the end of the output file
    }
    if (i+1 != temp_storage_size) { // If we are not at the last line in the file
       fprintf(output_file, "\n"); // Print a new line after the binary number
    }
  }

  free(token); // Free the memory allocated for token

  free(input_file_reopen_data); // Free the memory for the second copy of the input file data
  free(input_file_data); // Free up the memory allocated for input_file_data
  fclose(input_file_reopen); // Close the second copy of the input file.
  fclose(output_file); // Close the output file.
  fclose(input_file); // Close the input file.
  return 0;
}
