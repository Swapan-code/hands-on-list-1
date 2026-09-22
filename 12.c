#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test_mode.txt", O_RDWR | O_CREAT | O_APPEND, 0644);

    int flags = fcntl(fd, F_GETFL);
    int access_mode = flags & O_ACCMODE;

    if (access_mode == O_RDONLY)      printf("Opening Mode: Read-Only\n");
    else if (access_mode == O_WRONLY) printf("Opening Mode: Write-Only\n");
    else if (access_mode == O_RDWR)   printf("Opening Mode: Read-Write\n");

    if (flags & O_APPEND) printf("Append Flag: Enabled\n");

    close(fd);
    return 0;
}
