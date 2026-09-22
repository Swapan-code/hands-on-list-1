#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd = open("shared_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("File open failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        write(fd, "[CHILD] Writing line 1\n", 23);
        sleep(1);
        write(fd, "[CHILD] Writing line 2\n", 23);
    } else {
        write(fd, "[PARENT] Writing line 1\n", 24);
        sleep(1);
        write(fd, "[PARENT] Writing line 2\n", 24);
    }

    close(fd);
    return 0;
}
