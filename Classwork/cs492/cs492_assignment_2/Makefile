#
# I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
# CS 492 Lab 2 Makefile
# Compiles lab2_syscaller.c, my implementation of the user space program
#

CC=gcc #CC=C Compiler, gcc=name of compiler

CFLAGS = -O2 -g #Flags that are used to compile the C files

LAB2_SYSCALLER = lab2_syscaller

all:
	$(MAKE) clean && $(MAKE) lab2_syscaller;

lab2_syscaller:
	$(CC) $(CFLAGS) $(LAB2_SYSCALLER).c -o $(LAB2_SYSCALLER)

clean:
	rm -rf *.o *.exe *.dSYM $(LAB2_SYSCALLER)
