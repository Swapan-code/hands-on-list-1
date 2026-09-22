#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main() {
    int fd = open("q04_file.txt", O_RDWR | O_CREAT | O_EXCL, 0666);
    if (fd < 0) {
        if (errno == EEXIST) {
            printf("[EXPECTED EXCEPTION] File already exists! O_EXCL prevented opening.\n");
        } else {
            perror("open error");
        }
        return 1;
    }

    printf("[SUCCESS] File created exclusively. FD: %d\n", fd);
    close(fd);
    return 0;
}
