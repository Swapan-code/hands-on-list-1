#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("dup_c.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    int fd_fcntl = fcntl(fd, F_DUPFD, 20); // Duplicate to lowest FD >= 20
    printf("Original FD: %d | Duplicated FD via fcntl(): %d\n", fd, fd_fcntl);

    write(fd, "Written via original FD\n", 24);
    write(fd_fcntl, "Written via fcntl() FD\n", 23);

    close(fd);
    close(fd_fcntl);
    return 0;
}
