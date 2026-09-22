#include <stdio.h>
#include <sched.h>

int main() {
    int max_fifo = sched_get_priority_max(SCHED_FIFO);
    int min_fifo = sched_get_priority_min(SCHED_FIFO);

    int max_rr = sched_get_priority_max(SCHED_RR);
    int min_rr = sched_get_priority_min(SCHED_RR);

    printf("SCHED_FIFO -> Min Priority: %d | Max Priority: %d\n", min_fifo, max_fifo);
    printf("SCHED_RR   -> Min Priority: %d | Max Priority: %d\n", min_rr, max_rr);

    return 0;
}
