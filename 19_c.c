#include <stdio.h>
#include <unistd.h>

int main() {
    printf("c. Stopped State Demonstration Process (PID: %d)\n", getpid());
    printf("Press 'Ctrl + Z' to send SIGTSTP and place into Stopped ('T') state.\n");

    while (1) {
        sleep(1);
    }
    return 0;
}
