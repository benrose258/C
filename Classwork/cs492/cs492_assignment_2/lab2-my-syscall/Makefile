#
# I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
# CS 492 Lab 2 Makefile
#

CC=gcc #CC=C Compiler, gcc=name of compiler

obj-y += my_syscall.o
#obj-y += my_syscall2.o

#C_FILES = $(wildcard *.c) #Intelligently find all .c files in directory

#OBJ_FILES = $(patsubst %.c, %.o, $(C_FILES)) #Patsubst (pattern substitution) command subtitutes all of the file names for all %.c files into .o files, storing the results into OBJ_FILES

#CFLAGS = -O2 -g #Flags that are used to compile the C files

ccflags-y = -O2 -g #Flags that are used to compile the C files, since the kernel compiler doesn't like me using CFLAGS.

MY_SYSCALL = my_syscall #Setting the name for the first executable
#MY_SYSCALL2 = my_syscall2 #Setting the name for the second executable

#$(MY_SYSCALL) : $(MY_SYSCALL).o
#	$(CC) $(CFLAGS) $(MY_SYSCALL).c -o $(MY_SYSCALL)
#$(C_FILES) : $(OBJ_FILES)
#	$(CC) $(CFLAGS) $(C_FILES) -o $(OBJ_FILES)
all:
	$(MAKE) clean && $(MAKE) my_syscall;# && $(MAKE) my_syscall2; #using brute force, as intelligent methods aren't working for some reason.
#	$(MAKE) $(C_FILES)
my_syscall:
	$(CC) $(ccflags-y) my_syscall.c -o my_syscall.o
#	$(CC) $(CFLAGS) my_syscall.c -o my_syscall
#my_syscall2:
#	$(CC) $(ccflags-y) my_syscall2.c -o my_syscall2.o
clean:
	rm -rf *.o *.exe *.dSYM $(MY_SYSCALL)# $(MY_SYSCALL2)
