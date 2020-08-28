/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include <stdio.h>
#include <string.h>
#include "cs392_log.h"

void shell_log(char *command) { // Logs commands to cs392_shell.log
 FILE *log = fopen("cs392_shell.log", "a");
 fputs(command, log);
 fclose(log);
}

void test() {
  printf("\nHello. You have reached the log function. Please leave a message after the beep. [BEEP]\n\n");
}
