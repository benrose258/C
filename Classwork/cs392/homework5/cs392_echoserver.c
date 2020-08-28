/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <limits.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "cs392_log.h"

int main(int argc, char ** argv) {
  if (argc != 2) { // If we have too many or too few arguments
    printf("Usage: %s <port number>\n", argv[0]); // Print usage message.
    return 1; // Return a non-zero value, indicating an error.
  }
  errno = 0; // Set the error code to zero, indicating success
  int base = 10;
  unsigned long input_checker = 0;
  char *endptr;
  int port;

  input_checker = strtol(argv[1], &endptr, base);
  if (errno == ERANGE && (input_checker == (input_checker == LONG_MAX || input_checker == LONG_MIN)) || (errno != 0 && input_checker == 0)) {
    printf("Error: The port \"%s\" provided in argv[1] is not a valid port number.\nPlease try again with a valid port number.\n", argv[1]);
    return 1;
  }
  if (strcmp(endptr, argv[1]) == 0) {
    printf("Error: The port \"%s\" provided in argv[1] contains no digits.\nPlease try again with a valid port number.\n", argv[1]);
    return 1;
  }
  if (input_checker <= 0 || input_checker > 65535) {
    printf("Error: The port \"%ld\" provided in argv[1] is outside of the potential ranges for a port value (0 < port number <= 65535).\nPlease try again with a valid port number.\n", input_checker);
    return 1;
  }
  if (input_checker <= 1024) {
    printf("Warning: The port number \"%ld\" provided in argv[1] is below suggested levels (1024 or below).\nThis could cause the program to perform unexpectedly.\n", input_checker);
  }
  port = (int) input_checker;
    int server_socket;
    struct sockaddr_in echoserver;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    memset(&echoserver, 0, sizeof(echoserver));
    echoserver.sin_family = AF_INET;
    echoserver.sin_addr.s_addr = htonl(INADDR_ANY);
    echoserver.sin_port = htons(port); // Server port
    bind(server_socket, (struct sockaddr *) &echoserver, sizeof(echoserver));
    listen(server_socket, 5); // Listen for clients to connect to the socket, with a maximum of 5 clients connected at a time.
  while (1) {
    int clientlen;
    struct sockaddr_in echoclient;

    memset(&echoclient, 0, sizeof(echoclient));
    int client_socket = accept(server_socket, (struct sockaddr *) &echoclient, &clientlen);

    char client_ip[20];
    strcpy(client_ip, inet_ntoa(echoclient.sin_addr));
    cs392_socket_log(client_ip, atoi(argv[1]));

    char received_input[1000]; // Initialize the recieved input character array
    clientlen = recv(client_socket, received_input, 1000, 0); // Recieve input from the client and store it in the recieved input variable
    send(client_socket, received_input, strlen(received_input), 0); // Echo the received input back to the client
    close(client_socket);
  }
  return 0;
}
