/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 * CS 492 Lab 2: Adding a new system call
 * lab2_syscaller.c
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv) {
	char * input = "Hello World!";
	char output[128];
	int x = 1;
	int y = 3;
	int syscall_1 = syscall(548, x, y);
	int syscall_2;

	int input_length = 0;
	while (input[input_length] != '\0' && input_length <= 128) {
		input_length++;
	}
	if (input_length <= 128) {
		syscall_2 = syscall(549, input, output);
	} else {
		syscall_2 = -1;
	}
	printf("Name: Ben Rose\nPID of this program: %d\n", getpid());
	printf("First syscall input values: %d and %d\nFirst syscall result: %d\n", x, y, syscall_1);
	printf("Second syscall input value: %s\nSecond syscall result: %d\n", input, syscall_2);
	return 0;
}
