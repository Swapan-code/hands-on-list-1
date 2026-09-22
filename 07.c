#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <dest_file>\n", argv[0]);
        return 1;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) { perror("Source file open error"); return 1; }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) { perror("Dest file open error"); close(src_fd); return 1; }

    char buffer[BUF_SIZE];
    ssize_t bytes;

    while ((bytes = read(src_fd, buffer, BUF_SIZE)) > 0) {
        write(dest_fd, buffer, bytes);
    }

    close(src_fd);
    close(dest_fd);
    printf("File copied successfully.\n");
    return 0;
}
