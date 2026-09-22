#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("hole_test_b.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    write(fd, "0123456789", 10);
    lseek(fd, 10, SEEK_CUR); // Seek hole space
    write(fd, "ABCDEFGHIJ", 10);
    close(fd);

    printf("b. Running 'od -c hole_test_b.txt' to examine null byte gaps:\n");
    system("od -c hole_test_b.txt");
    return 0;
}
