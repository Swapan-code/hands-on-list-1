#include <stdio.h>
#include <sched.h>
#include <unistd.h>

void print_policy(int policy) {
    switch(policy) {
        case SCHED_OTHER: printf("SCHED_OTHER (Standard Time-Sharing)\n"); break;
        case SCHED_FIFO:  printf("SCHED_FIFO (Real-Time FIFO)\n"); break;
        case SCHED_RR:    printf("SCHED_RR (Real-Time Round-Robin)\n"); break;
        default:          printf("Unknown Policy\n");
    }
}

int main() {
    int pid = getpid();

    int policy = sched_getscheduler(pid);
    printf("Current Scheduling Policy: ");
    print_policy(policy);

    struct sched_param param;
    param.sched_priority = 10; // Must be 1-99 for Real-Time policies

    printf("Attempting to change policy to SCHED_RR...\n");
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler failed (Must run with sudo)");
        return 1;
    }

    policy = sched_getscheduler(pid);
    printf("New Scheduling Policy: ");
    print_policy(policy);

    return 0;
}
