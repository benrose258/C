#
# I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
#

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
# CC: the name of the compiler
CC=gcc

# The wildcard command followed by the *.c searches the folder for all .c files and lists them in C_FILES.
C_FILES = $(wildcard *.c)

# The patsubst (pattern substitution) command substitutes all of the file names in the %.c files into .o files, storing the results in OBJ_FILES.
OBJ_FILES = $(patsubst %.c, %.o, $(C_FILES))

CFLAGS = -O2 -g -pthread

PROG = cs392_thread

all:
	$(MAKE) clean && $(MAKE) $(PROG);

clean:
		rm -rf *.o *.exe *.dSYM $(PROG)

$(PROG) : $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(PROG)
