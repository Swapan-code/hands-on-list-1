#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("   ---> [TARGET EXECUTABLE RUNNING]\n");
    if (argc > 1) {
        printf("   ---> Argument Received: '%s'\n", argv[1]);
    } else {
        printf("   ---> No argument received.\n");
    }
    return 0;
}
