#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("dup_a.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    int fd_dup = dup(fd);
    printf("Original FD: %d | Duplicated FD via dup(): %d\n", fd, fd_dup);

    write(fd, "Written via original FD\n", 24);
    write(fd_dup, "Written via dup() FD\n", 21);

    close(fd);
    close(fd_dup);
    return 0;
}
