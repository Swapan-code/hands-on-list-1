#include <stdio.h>
#include <unistd.h>

int main() {
    printf("a. Running State Process (PID: %d)\n", getpid());
    printf("Check state with: ps -o pid,stat,cmd -p %d\n", getpid());
    
    // CPU-bound loop keeps process in 'R' state
    while (1) {
        volatile long x = 0;
        x++;
    }
    return 0;
}
