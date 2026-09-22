#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("[CHILD] (PID %d) Exiting immediately...\n", getpid());
        exit(0);
    } else {
        printf("[PARENT] (PID %d) Sleeping for 20s WITHOUT calling wait()...\n", getpid());
        printf("Check state using: ps aux | grep %d\n", pid);
        sleep(20);
        printf("[PARENT] Exiting now.\n");
    }
    return 0;
}
