#include <stdio.h>
#include <unistd.h>

int main() {
    char *env[] = {NULL}; // Custom environment
    printf("c. Executing ls -Rl using execle():\n");
    execle("/bin/ls", "ls", "-Rl", NULL, env);
    perror("execle failed");
    return 1;
}
