#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("[CHILD] Initial PPID: %d\n", getppid());
        printf("[CHILD] Sleeping for 5s while parent exits...\n");
        sleep(5);
        printf("[CHILD] New Adopted PPID: %d\n", getppid());
    } else {
        sleep(1);
        printf("[PARENT] Exiting early, leaving child orphaned.\n");
        exit(0);
    }
    return 0;
}
