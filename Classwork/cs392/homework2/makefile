#
# I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
#

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

CC = gcc # C Compiler

CFLAGS = -O0 -g -fPIC # Compiler Flags
LIBFLAGS =  -shared -fPIC # Library Flags

PROG = cs392_ass2_test # The test program to be compiled
LIBS = libcs392string.so # Shared Library

$(PROG) : cs392_ass2_test.o $(LIBS) # Requirements for the test program's building
	$(CC) $(CFLAGS) -o $@ $^ # Use the <C Compiler> and <Compiler Flags> to <output> the <name of the target of the rule> and
	 													 # <the names of all dependencies>.

$(LIBS): cs392_memcpy.o cs392_strlen.o # Requirements for shared library's building
	$(CC) $(LIBFLAGS) -o $@ $^ # Use the <C Compiler> and <Library Flags> to <output> the <name of the target of the rule> and
	 													 # <the names of all dependencies>.

all: # Automate Make clean, Make, Make test
	$(MAKE) clean; # $(MAKE): command to run "make" within a makefile. $(MAKE) clean == make clean, clean shown below.
	$(MAKE); # Used to re"make" the program
	$(MAKE) test; # Make test program

clean: # Remove all generated object files, shared libraries, .dSYM files (produced from "make" in the macOS command line), and the test program
	rm -rf *.o *.so *.dSYM $(PROG)
	rm -f test

test: # Compile test program
	$(CC) cs392_ass2_test.c -o test $(LIBS)
	export LD_LIBRARY_PATH=$(PWD); ./test # Link the test program with the shared library, then run the test program.
