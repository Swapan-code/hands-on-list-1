#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) { perror("File open error"); return 1; }

    char ch;
    while (read(fd, &ch, 1) > 0) {
        write(STDOUT_FILENO, &ch, 1);
    }

    close(fd);
    return 0;
}
