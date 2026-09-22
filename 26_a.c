#include <stdio.h>
#include <unistd.h>

int main() {
    printf("a. Executing ls -Rl using execl():\n");
    execl("/bin/ls", "ls", "-Rl", NULL);
    perror("execl failed");
    return 1;
}
