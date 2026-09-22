#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("mandatory_file.txt", O_RDWR | O_CREAT, 0666);

    struct flock fl;
    fl.l_type = F_RDLCK; // Shared Read Lock
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;

    printf("b. Requesting Mandatory READ Lock...\n");
    fcntl(fd, F_SETLKW, &fl);
    printf("READ Lock acquired! Press Enter to release...");
    getchar();

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    printf("Lock released.\n");

    close(fd);
    return 0;
}
