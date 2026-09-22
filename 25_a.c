#include <stdio.h>
#include <unistd.h>

int main() {
    printf("[EX25_A] Original Process PID: %d\n", getpid());
    printf("[EX25_A] Executing './target' using execvp()...\n");

    char *args[] = {"./target", NULL};

    // Replaces current process with target executable
    execvp(args[0], args);

    // This line ONLY executes if execvp fails
    perror("execvp failed");
    return 1;
}
