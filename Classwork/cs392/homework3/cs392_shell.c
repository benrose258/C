/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "cs392_exec.h"
#include "cs392_log.h"
#include "cs392_signal.h"

int main(int argc, char ** argv) { // Begin main function
  signal_handler(); // Signal handling from the Signal program

  char command[100]; // Create a character array to hold the command provided
  while(1) { // While we have not exited the program
    memset(command, 0, sizeof(command)); // Wipe out the previous command, leftover commands leak out in CTRL-Z
    fflush(stdin); // Flush the input stream to get rid of any leftover erroneous commands
    fflush(stdout); // Flush the output stream to get rid of any leftover erroneous commands
    printf("cs392_shell $: "); // Print out the shell message
    fgets(command, 100, stdin); // Receive the user's command from the standard input file stream
    shell_log(command); // Log the user's command
    if (strcmp(command, "exit\n") == 0) { // If the command equals exit, then exit the program.
      printf("Thank you for using cs392_shell. Goodbye.\n"); // Thanks the user and says goodbye. Exit message.
      exit(0); // Exit with the code 0 (indicating success)
    }
    pid_t pid = fork();
    if (pid < 0) { // If the forking fails
      perror("Attempted fork, used spoon instead.");
      return -1;
    }
    else if (pid == 0) { // If pid = 0, then we are in the child process.
      exeCommand(command);
    }
    else { // Else, pid > 0, In parent
      wait(0); // Wait for child process to complete
    }
  }
  return 0;
}
