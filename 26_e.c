#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    printf("e. Executing ls -Rl using execvp():\n");
    execvp("ls", args);
    perror("execvp failed");
    return 1;
}
