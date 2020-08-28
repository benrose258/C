/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 * CS 492 Lab 2: Adding a new system call
 * my_syscall2.c
*/

#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

SYSCALL_DEFINE2(my_syscall2, char *, input, char *, output) {
	printk(KERN_INFO "PID for my_syscall2 (currently executing): %d. Input string: \"%s\". ", current->pid, input);
	int length = 0; // Initialize the length to be 0
	int replacements = 0; // Initialize the number of replacements to be 0
	if (input != NULL) { // If the input string is not null
		while (input[length] != '\0' && length <= 128) { // While we are not at the terminating character and length of the input string is less than or equal to 128
			length++; // Add 1 to the length of the string
			if (input[length] == "o") { // If the current character is an o
				replacements++; // Increment the number of replacements
				output[length] = "0"; // Replace it with a 0 in the output
			} else { // The current character is not an o
				output[length] = input[length]; // Copy the input character to the output string
			}
	}
	printk("Replacements made: %d. Output string: \"%s\".\n", replacements, length = 0 ? "" : output); // Print out the number of replacements made and, if the input string is not null, print the output string, otherwise print an empty string along with the number of replacements
	return length > 128 ? -1 : replacements; // Return the number of replacements if the length is less than or equal to 128, -1 otherwise
	}
}
