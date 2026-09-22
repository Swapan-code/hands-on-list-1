#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char filename[32];
    int file_counter = 0;

    printf("[PROCESS] Running PID: %d\n", getpid());

    while (1) {
        for (int i = 0; i < 5; i++) {
            snprintf(filename, sizeof(filename), "temp_%d.txt", file_counter++);
            int fd = open(filename, O_CREAT | O_RDWR, 0644);
            if (fd >= 0) {
                printf("Created %s with FD %d\n", filename, fd);
            }
        }
        sleep(10);
    }
    return 0;
}
