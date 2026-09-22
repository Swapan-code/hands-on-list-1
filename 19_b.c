#include <stdio.h>
#include <unistd.h>

int main() {
    printf("b. Sleeping State Process (PID: %d)\n", getpid());
    printf("Check state with: ps -o pid,stat,cmd -p %d\n", getpid());

    // sleep puts process into 'S' (Interruptible Sleep) state
    while (1) {
        sleep(10);
    }
    return 0;
}
