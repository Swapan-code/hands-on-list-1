#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("ticket.db", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int ticket_num = 1000;
    write(fd, &ticket_num, sizeof(ticket_num));
    close(fd);
    printf("Initialized ticket database to ticket number: %d\n", ticket_num);
    return 0;
}
