/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include <stdio.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void cs392_socket_log(char *ip_address, int port) { // Logs commands to cs392_socket.log
 FILE *log = fopen("cs392_socket.log", "a");
 fprintf(log, "%s:%d\n", ip_address, port);
 fclose(log);
}

void test() {
  printf("\nHello. You have reached the log function. Please leave a message after the beep. [BEEP]\n\n");
}
