/*
 * I pledge my honor that I have abided by the Stevens Honor System. -Ben Rose
 */

 #ifndef CS392_SIGNAL_H_ // If cs392_signal.h hasn't already been included (and defined)
 #define CS392_SIGNAL_H_ // Define cs392_signal.h. Used to prevent duplicate inclusion of files.

static void handler(int sig, siginfo_t *siginfo, void *context); // Function prototype.
void signal_handler(); // Function prototype.

 #endif /* CS392_SIGNAL_H_ */
