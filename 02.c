#include <stdio.h>
#include <unistd.h>

int main() {
    printf("[PROCESS] Running PID: %d\n", getpid());
    printf("Exploring /proc/%d/\n", getpid());

    // Indefinite loop to keep process running in background
    while (1) {
        sleep(2);
    }
    return 0;
}
