#include <stdio.h>
#include <unistd.h>

int main() {
    // Create soft link pointing to target.txt
    if (symlink("target.txt", "soft_link.txt") == 0) {
        printf("[SUCCESS] Soft link created using symlink() system call.\n");
    } else {
        perror("symlink error");
    }
    return 0;
}
