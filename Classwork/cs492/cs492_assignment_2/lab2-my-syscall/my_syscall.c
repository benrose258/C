/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 * CS 492 Lab 2: Adding a new system call
 * my_syscall.c
*/

#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

#define MAXIMUM_LENGTH 128

SYSCALL_DEFINE2(my_syscall, int, x, int, y) {
	int sum = x + y;
	printk(KERN_INFO "PID for my_syscall (currently executing): %d. The sum of the input variables x and y, where x = %d and y = %d, is equal to %d.\n", current->pid, x, y, sum);
	return sum;
}

SYSCALL_DEFINE2(my_syscall2, char *, input, char *, output) {
	char buffer[MAXIMUM_LENGTH]; // Define the intermediate buffer of length 128 (the maximum possible length of the string) to send and recieve the string
	copy_from_user(buffer, input, MAXIMUM_LENGTH);
	printk(KERN_INFO "PID for my_syscall2 (currently executing): %d. Input string: \"%s\". ", current->pid, input);
	int length = 0; // Initialize the length to be 0
	int replacements = 0; // Initialize the number of replacements to be 0
	if (input != NULL) { // If the input string is not null
		while (buffer[length] != '\0'){// && length <= 128) { // While we are not at the terminating character and length of the input string is less than or equal to 128
			length++; // Add 1 to the length of the string
			if (buffer[length] == 'o') { // If the current character is an o
				replacements++; // Increment the number of replacements
				buffer[length] = '0'; // Replace it with a 0 in the output
			}
		}
	printk("Replacements made: %d.\n", replacements);
	copy_to_user(output, buffer, MAXIMUM_LENGTH); // Copy the output string into the buffer and send it back to the user
	return length > 128 ? -1 : replacements; // Return the number of replacements if the length is less than or equal to 128, -1 otherwise
	}
}
