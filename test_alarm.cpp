#include <stdio.h>
#include <unistd.h>
#include <signal.h>

const int TIMESLICE = 2;

//   *  User defined signal handler for the signal number that is registeredusing signal(unsigned int signum, sighandler_t)                             @param signum: signal number of the signal that caused the handler to fire.
void sigalarm_handler(int signum)
{}



void sigalarm_handler(int signum)
{
// To simulate a preemptive, timesliced scheduling system, a signal handler
// must be registered that simulates the CPU timer that fires whenever the
// system has to schedule another process.
    printf("got SIGALRM %d\n", signum);
}
