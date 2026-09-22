#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10; // 10 seconds timeout
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN (10s timeout)...\n");
    int res = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (res == -1) {
        perror("select error");
    } else if (res == 0) {
        printf("[TIMEOUT] No input provided within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("[DATA AVAILABLE] STDIN has input ready to read.\n");
        }
    }
    return 0;
}
