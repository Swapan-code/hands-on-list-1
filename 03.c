#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = creat("test_creat.txt", 0644);
    if (fd < 0) {
        perror("creat error");
        return 1;
    }

    printf("File created successfully. Assigned File Descriptor: %d\n", fd);
    close(fd);
    return 0;
}
