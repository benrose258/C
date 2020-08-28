/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cs392_exec.h"

int exeCommand(char *command) { // Execute the user's command, then exit upon success.
  // Execute the shell command from within the c program. Done with thourough explanation and customization below.
  execlp("/bin/sh", "sh", "-c", command, (char *) NULL);
  exit(0);
}
