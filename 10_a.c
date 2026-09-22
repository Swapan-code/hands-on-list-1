#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("hole_test_a.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    write(fd, "0123456789", 10); // Write 10 bytes

    // Move file pointer by 10 bytes forward
    off_t offset = lseek(fd, 10, SEEK_CUR);

    printf("a. Return value of lseek (New byte offset position): %ld\n", (long)offset);

    write(fd, "ABCDEFGHIJ", 10); // Write another 10 bytes
    close(fd);
    return 0;
}
