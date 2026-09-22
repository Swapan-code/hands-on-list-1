#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("ticket.db", O_RDWR);

    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, getpid()};

    printf("[PROCESS %d] Waiting for lock on ticket database...\n", getpid());
    fcntl(fd, F_SETLKW, &fl);

    int ticket;
    read(fd, &ticket, sizeof(ticket));
    printf("[PROCESS %d] Read current ticket number: %d\n", getpid(), ticket);

    ticket++;

    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket, sizeof(ticket));
    printf("[PROCESS %d] Reserved new ticket number: %d\n", getpid(), ticket);

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);

    close(fd);
    return 0;
}
