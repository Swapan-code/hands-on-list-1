#include <stdio.h>
#include <unistd.h>

int main() {
    printf("b. Executing ls -Rl using execlp():\n");
    execlp("ls", "ls", "-Rl", NULL);
    perror("execlp failed");
    return 1;
}
