/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <pthread.h>
 #include <unistd.h>
 #include <sys/types.h>
 // #include <sys/syscall.h> // Not sure if this is necessary, but uncomment if the end product doesn't work.

 // Counters are of type long to accomidate larger size items

 long item1_counter = 0; // Initialize the first item counter to zero
 long item2_counter = 0; // Initialize the second item counter to zero
 long item3_counter = 0; // Initialize the third item counter to zero

 pthread_mutex_t lock; // Create mutex variable

 void cs392_thread_run(void *path) {
   int loop_execution_counter = 0;

   int failure_counter = 0; // Increases if an error occurs, if the token isn't read as any of the six inputs, which shouldn't be possible.
   FILE *pathfinder = fopen(path, "r"); // Open the file for reading

    fseek(pathfinder, 0L, SEEK_END); // See how large the file is
    int pathfinder_size = ftell(pathfinder); // Set the variable holding to the file's size to the size of the file
    char *pathfinder_data = malloc(pathfinder_size); // Allocate exactly enough space for the file to the storage variable
    rewind(pathfinder); // Reset the file position to the beginning
    // fread(pathfinder_data, 1, pathfinder_size, pathfinder); // Read the data from the file into the file data variable from 0 to the size of the file
    size_t bytes_read = fread(pathfinder_data, 1, pathfinder_size, pathfinder); // Read the data from the file into the file data variable from 0 to the size of the file
    // Read the data from the file into the file data variable from 0 to the size of the file
    if (bytes_read != (1 * pathfinder_size)) { // If it isn't possible to read all bytes of data * size of each byte
      // Print the error message and exit the thread
      printf("An error occurred when reading from the file located at \"%s\".\nRecorded file size: \"%d\"\nBytes read using fread: \"%d\"\n", (char *) path, pathfinder_size, (int) bytes_read);
      pthread_exit((void *) pthread_self()); // Exit the thread
    }
    rewind(pathfinder); // Reset the file position to the beginning, fread went to the end of the file.

    pthread_mutex_lock(&lock); // Lock global variable access
    char *token = malloc(pathfinder_size);
    token = strtok(pathfinder_data, "\n");
    while (token != NULL) { // While we aren't at the end of the file data
      if (strcmp(token, "+item1") == 0) {
        item1_counter++;
      }
      else if (strcmp(token, "-item1") == 0) {
        item1_counter--;
      }
      else if (strcmp(token, "+item2") == 0) {
        item2_counter++;
      }
      else if (strcmp(token, "-item2") == 0) {
        item2_counter--;
      }
      else if (strcmp(token, "+item3") == 0) {
        item3_counter++;
      }
      else if (strcmp(token, "-item3") == 0) {
        item3_counter--;
      }
      else {
        failure_counter++;
        printf("\nAn error has occurred. Comparing token with the six potential cases failed.\nToken currently equals: \"%s\"\ntoken[0] = \"%s\"\ntoken[5] = \"%s\"\n", token, &token[0], &token[5]);
      }
      loop_execution_counter++; // Used for testing, seeing how many times the token loop executes to properly track changes.
      token = strtok(NULL, "\n");
    }
    free(token);
    free(pathfinder_data); // Free the allocated memory
    fclose(pathfinder); // Close the file
    if (failure_counter != 0) { // If any failures are detected, print the amount of executions of the loop and the number of failures.
      printf("Provided path = \"%s\", token loop execution counter = \"%d\", failure counter = \"%d\",pthread_self() = \"%ld\"\n", (char *) path, loop_execution_counter, failure_counter, pthread_self());
    }
    pthread_mutex_unlock(&lock); // Unlock global variable access

    pthread_exit((void *) pthread_self()); // Exit the thread
 }

 int main(int argc, char ** argv) {
   if (argc != 4) { // If the user provides an incorrect number of arguments
     printf("Usage: ./cs392_thread <item 1 path> <item 2 path> <item 3 path>\n"); // Print the usage message
     printf("Example: ./cs392_thread ./item_file1.txt ./item_file2.txt ./item_file3.txt\n"); // And an example
     return 1; // Return 1 to indicate failure
   }
   for (int argv_counter = 1; argv_counter <= 3; argv_counter++) { // Test to see if all of the three files provided exist
     FILE *current_argument_file = fopen(argv[argv_counter], "r"); // Open the file, NULL if the file doesn't exist
     if (current_argument_file == NULL) { // If the file doesn't exist
       printf("Error: File \"%s\" provided in argv[%d] does not exist.\n", argv[argv_counter], argv_counter); // Print an adaptive error message
       return 1; // Return 1 to indicate failure
     }
     fclose(current_argument_file); // Close the existing file opened
   }

   if (pthread_mutex_init(&lock, NULL) != 0) { // Initialize the mutex variable and catch any errors.
     printf("\nAn error occurred when initializing the mutex variable \"lock\". Goodbye.\n");
     return 1;
   }

   pthread_t item1_tid = pthread_self(); // Create thread id for item 1
   pthread_t item2_tid = pthread_self(); // Create thread id for item 2
   pthread_t item3_tid = pthread_self(); // Create thread id for item 3

   int item1_thread; // Initialize the integer that will be used by pthread_create for item 1
   int item2_thread; // Initialize the integer that will be used by pthread_create for item 2
   int item3_thread; // Initialize the integer that will be used by pthread_create for item 3

   item1_thread = pthread_create(&item1_tid, NULL, (void *) cs392_thread_run, (void *) argv[1]); // Create thread 1
   item2_thread = pthread_create(&item2_tid, NULL, (void *) cs392_thread_run, (void *) argv[2]); // Create thread 2
   item3_thread = pthread_create(&item3_tid, NULL, (void *) cs392_thread_run, (void *) argv[3]); // Create thread 3

   pthread_join(item1_tid, (void *) item1_tid); // Join thread 1, which will pthread_exit with its corresponding thread_id
   pthread_join(item2_tid, (void *) item2_tid); // Join thread 2, which will pthread_exit with its corresponding thread_id
   pthread_join(item3_tid, (void *) item3_tid); // Join thread 3, which will pthread_exit with its corresponding thread_id

   pthread_mutex_destroy(&lock); // Destroy the mutex variable!
   printf("Item 1 Counter: %ld\nItem 2 Counter: %ld\nItem 3 Counter: %ld\n", item1_counter, item2_counter, item3_counter);
   return 0; // Return 0 to indicate success
 }
