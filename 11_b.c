#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("dup_b.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    int fd_dup2 = dup2(fd, 10); // Duplicate explicitly to FD 10
    printf("Original FD: %d | Duplicated FD via dup2(): %d\n", fd, fd_dup2);

    write(fd, "Written via original FD\n", 24);
    write(fd_dup2, "Written via dup2() FD\n", 22);

    close(fd);
    close(fd_dup2);
    return 0;
}
