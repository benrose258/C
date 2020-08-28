#
# I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
#

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

CC=gcc

CFLAGS = -O2 -g

PROG = cs392_shell

#DEPENDS = cs392_shell.o cs392_exec.o cs392_log.o cs392_signal.o
DEPENDS = cs392_exec cs392_log cs392_signal #dependencies
DEPENDS_C = cs392_exec.c cs392_log.c cs392_signal.c # c files for the dependencies
DEPENDS_O = cs392_exec.o cs392_log.o cs392_signal.o # output files for the dependencies

# Clean the previous program files, then make the program.
all:
		$(MAKE) clean;
		$(MAKE) $(PROG);

# Remove the <output files>, <exe files>, the <cs392_shell log file>, and the <macOS makefile> for all <dependencies> and the <program>
clean:
		rm -rf *.o *.exe *.log *.dSYM $(DEPENDS) $(PROG)
		rm -f $(PROG)

# Clean the log, free to be used when program is in execution for cleanup.
clean_log:
		rm -f $(PROG).log

$(PROG) : $(PROG).o $(DEPENDS_O)
	$(CC) $(CFLAGS) $(DEPENDS_C) -o $@ $<
