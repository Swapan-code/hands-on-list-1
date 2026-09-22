#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name_argument>\n", argv[0]);
        printf("Example: %s John\n", argv[0]);
        return 1;
    }

    printf("[EX25_B] Original Process PID: %d\n", getpid());
    printf("[EX25_B] Passing argument '%s' to target via execvp()...\n", argv[1]);

    // Construct argument array passing user argument as argv[1]
    char *args[] = {"./target", argv[1], NULL};

    execvp(args[0], args);

    // This line ONLY executes if execvp fails
    perror("execvp failed");
    return 1;
}
