#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pids[3];

    for (int i = 0; i < 3; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            printf("[CHILD %d] PID: %d sleeping for %ds...\n", i + 1, getpid(), (3 - i) * 2);
            sleep((3 - i) * 2); 
            printf("[CHILD %d] Done.\n", i + 1);
            exit(10 + i + 1); // Exit status code
        }
    }

    // Parent explicitly waits ONLY for Child #2
    int status;
    printf("[PARENT] Explicitly waiting ONLY for Child #2 (PID %d)...\n", pids[1]);
    
    waitpid(pids[1], &status, 0);

    if (WIFEXITED(status)) {
        printf("[PARENT] Child #2 finished with exit status: %d\n", WEXITSTATUS(status));
    }
    return 0;
}
