#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct Record { int id; char data[32]; };

int main() {
    int fd = open("records.db", O_RDWR | O_CREAT, 0644);
    int record_idx = 0; // Lock Record 0

    struct flock fl;
    fl.l_type = F_WRLCK; // Write Lock
    fl.l_whence = SEEK_SET;
    fl.l_start = record_idx * sizeof(struct Record);
    fl.l_len = sizeof(struct Record);

    printf("a. Requesting WRITE lock on Record #%d...\n", record_idx);
    fcntl(fd, F_SETLKW, &fl);
    printf("Record #%d WRITE LOCKED. Press Enter to release...", record_idx);
    getchar();

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    close(fd);
    return 0;
}
