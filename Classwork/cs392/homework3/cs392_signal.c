/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "cs392_signal.h"

static void handler(int sig, siginfo_t *siginfo, void *context) {
  fflush(stdout); // Flush the standard output stream
  printf("Type \"exit\" to exit the shell.\n"); // Print info on properly exiting the program.
}

void signal_handler() { // Handles signals sent by CTRL+C and CTRL+Z
  struct sigaction action;

  memset(&action, '\0', sizeof(action));
  /* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler. */
	action.sa_flags = SA_SIGINFO;// | SA_RESETHAND;

  /* Use the sa_sigaction field because the handles has two additional parameters */
  action.sa_sigaction = handler;

  sigemptyset(&action.sa_mask);
  sigaction(SIGINT, &action, NULL); // Handling for CTRL+C
  sigaction(SIGTSTP, &action, NULL); // Handling for CTRL+Z

  if (sigaction(SIGTERM, &action, NULL) < 0) {
    perror("Tried to act, loafed around instead.");
	}
  
}
