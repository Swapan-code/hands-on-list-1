#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Create FIFO using mkfifo library function
    if (mkfifo("my_fifo", 0666) == 0) {
        printf("[SUCCESS] FIFO created using mkfifo() library function.\n");
    } else {
        perror("mkfifo error");
    }
    return 0;
}
