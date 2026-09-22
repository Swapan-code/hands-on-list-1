#include <stdio.h>
#include <unistd.h>

int main() {
    // Create hard link pointing to target.txt
    if (link("target.txt", "hard_link.txt") == 0) {
        printf("[SUCCESS] Hard link created using link() system call.\n");
    } else {
        perror("link error");
    }
    return 0;
}
