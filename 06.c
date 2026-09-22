#include <unistd.h>

#define BUF_SIZE 128

int main() {
    char buffer[BUF_SIZE];
    ssize_t bytes_read;

    // Read directly from STDIN (FD 0) and echo to STDOUT (FD 1)
    while ((bytes_read = read(STDIN_FILENO, buffer, BUF_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    return 0;
}
