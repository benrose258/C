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

// These and netinet/in.h are included in the automatic conversion of ipv4 addresses.
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char ** argv) {
  if (argc != 3) {
    printf("Usage: %s <IPv4 address> <port number>\n", argv[0]); // Print usage message
    return 1;
  }
  in_addr_t network_address = inet_addr(argv[1]);

  if (network_address == -1 && strcmp("255.255.255.255", argv[1]) != 0) { // If there was an error reading the network address
    printf("Error: The IPv4 address \"%s\" provided in argv[1] is not a valid IPv4 address.\nPlease try again with a valid IPv4 address.\n", argv[1]);
    return 1;
  }

  errno = 0; // Set the error code to zero, indicating success
  int base = 10;
  unsigned long input_checker = 0;
  char *endptr;
  int port;

  input_checker = strtol(argv[2], &endptr, base);

  // If argv[2] has non-integer input
  if (errno == ERANGE && (input_checker == (input_checker == LONG_MAX || input_checker == LONG_MIN)) || (errno != 0 && input_checker == 0)) {
    printf("Error: The port \"%s\" provided in argv[2] is not a valid port number.\nPlease try again with a valid port number.\n", argv[2]);
    return 1;
  }
  if (strcmp(endptr, argv[2]) == 0) {
    printf("Error: The port \"%s\" provided in argv[2] contains no digits.\nPlease try again with a valid port number.\n", argv[2]);
    return 1;
  }
  if (input_checker <= 0 || input_checker > 65535) {
    printf("Error: The port \"%ld\" provided in argv[2] is outside of the potential ranges for a port value (0 < port number <= 65535).\nPlease try again with a valid port number.\n", input_checker);
    return 1;
  }
  if (input_checker <= 1024) {
    printf("Warning: The port number \"%ld\" provided in argv[2] is below suggested levels (1024 or below).\nThis could cause the program to perform unexpectedly.\n", input_checker);
  }
  port = (int) input_checker; // Pass the value of the converted input to the port variable

  int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  struct sockaddr_in echoserver;
  memset(&echoserver, 0, sizeof(echoserver)); // Clear the data of the struct
  echoserver.sin_family = AF_INET; // Specify that we are using TCP/IP protocol
  echoserver.sin_addr.s_addr = network_address; // Set the IP address to be the network address determined from argv[1]
  echoserver.sin_port = htons(port); // Specifiy the port you are trying to connect to
  int nexutas = connect(sock, (struct sockaddr *) &echoserver, sizeof(echoserver));

  if (nexutas == -1) { // If there was a connection error
    printf("An error occurred when connecting to \"%s:%d\". Connection failure.\n", argv[1], port);
    // printf("An error occurred when connecting to \"%s:%s\". Connection failure.\n", argv[1], argv[2]);
    return 1;
  }
  else { // Comment this out later on
    printf("I can sense a connection now.\n\n");
  }
  printf("Please enter your message below...\n\n$: ");
  char user_input[1000];
  char *f_gets = fgets(user_input, 1000, stdin);
  printf("Message recieved.\nMessage = %s\n\n", user_input);
  int user_input_length = strlen(user_input);
  user_input[user_input_length] = '\0'; // Writing the null byte again at the end of the string
  send(sock, user_input, user_input_length, 0);
  char echoed_input[1000]; // Initialize the char array to receive the echoed input back from the server
  recv(sock, echoed_input, (user_input_length - 1), 0); // length - 1 because the last character is '\n'
  printf("Message echoed: \"%s\"\n\n", echoed_input);
  close(sock);
  return 0;
}
