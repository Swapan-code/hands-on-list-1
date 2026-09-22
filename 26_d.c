#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    printf("d. Executing ls -Rl using execv():\n");
    execv("/bin/ls", args);
    perror("execv failed");
    return 1;
}
