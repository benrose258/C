#
# I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
#

# The uncommented line in %.o : %.c is the original line and the correct line.
# Rule for compiling object files from c files
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
#	$(CC) $(CFLAGS) $< -o $@
#	$(CC) $(CFLAGS) -c $< $@

# CC: the name of the compiler
CC=gcc

# The wildcard command followed by the *.c searches the folder for all .c files and lists them in C_FILES.
C_FILES = $(wildcard *.c)

# The patsubst (pattern substitution) command substitutes all of the file names in the %.c files into .o files, storing the results in OBJ_FILES.
OBJ_FILES = $(patsubst %.c, %.o, $(C_FILES))

#OBJ_FILES = cs392_thread.o

#CFLAGS = -O2 -g #Original CFLAGS list
CFLAGS = -O2 -g# -pthread #Added -pthread experimentally, as powerpoint 20 slide 12 says to "compile and link" with -pthread.
#CFLAGS = -pthread

SERVER = cs392_echoserver

CLIENT = cs392_echoclient

# PROG = cs392_thread

#DEPENDS = cs392_shell.o cs392_exec.o cs392_log.o cs392_signal.o
#DEPENDS = cs392_exec cs392_log cs392_signal #dependencies
#DEPENDS_C = cs392_exec.c cs392_log.c cs392_signal.c # c files for the dependencies
#DEPENDS_O = cs392_exec.o cs392_log.o cs392_signal.o # output files for the dependencies

# Clean the previous program files, then make the program.
# In this makefile, the task is accomplished in one line for make clean and make prog, creating a more efficient and incremental build.
all:
	$(MAKE) clean && $(MAKE) $(SERVER) && $(MAKE) $(CLIENT);
#		$(MAKE) clean;
#		$(MAKE) $(PROG);

# Remove the <output files>, <exe files>, any <stack overflows>, the <log file>, and the <macOS makefile> for the <SERVER> and the <CLIENT>.
clean:
	rm -rf *.o *.exe *.exe.stackdump *.log *.dSYM $(SERVER) $(CLIENT)
# rm -rf *.o *.exe *.dSYM $(PROG)

# rm -f $(PROG) # Unnecessary (it seems), as it appears that *.exe covers the executable.

$(SERVER) : $(SERVER).o cs392_log.o
	$(CC) $(CFLAGS) $(SERVER).o cs392_log.o -o $(SERVER)

$(CLIENT) : $(CLIENT).o
	$(CC) $(CFLAGS) $(CLIENT).o -o $(CLIENT)

#$(PROG) : $(PROG).c
#	$(CC) $(CFLAGS) $(PROG).c -o $(PROG)

# Make the program, with the dependencies being cs392_shell.o, cs392_exec.o, cs392_log.o, and cs392_signal.o
#$(PROG) : $(OBJ_FILES)
#	$(CC) $(CFLAGS) $(DEPENDS_C) -o $@ $<
#	$(CC) $(OBJ_FILES) -o $@ $<

# From HW 4
# $(PROG) : $(OBJ_FILES)
# 	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(PROG)

#$(CC) $(OBJ_FILES) -o $@ # also works for $(PROG) : $(OBJ_FILES), but only because of a technicality with $@, so it's left out.
#$(PROG) : $(PROG).o
#	$(CC) $(CFLAGS) -c $(DEPENDS) -o $(DEPENDS).o
#	$(CC) $(CFLAGS) $(PROG).c -o $@ $<

#$(PROG).o : $(PROG).c $(DEPENDS_C)
#	$(CC) $(CFLAGS) $(DEPENDS_C) -o $(PROG).o

#cs392_exec.o : cs392_exec.c
#	$(CC) $(CFLAGS) cs392_exec.c -o cs392_exec.o

#cs392_signal.o : cs392_signal.c
#	$(CC) $(CFLAGS) cs392_signal.c -o cs392_signal.o

#cs392_log.o : cs392_log.c
#	$(CC) $(CFLAGS) cs392_log.c -o cs392_log.o

#$(DEPENDS).o : $(DEPENDS).c
#	$(CC) $(CFLAGS) -c $< -o $@.o



#cs392_shell : $(DEPENDS).o
#	$(CC) $(CFLAGS) -c $(DEPENDS).c -o $(DEPENDS).o
