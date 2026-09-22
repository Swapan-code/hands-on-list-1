#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;

    struct stat sb;
    if (stat(argv[1], &sb) == -1) {
        perror("stat failed");
        return 1;
    }

    printf("a. Inode:                  %ld\n", (long)sb.st_ino);
    printf("b. Number of hard links:   %ld\n", (long)sb.st_nlink);
    printf("c. UID:                    %d\n", sb.st_uid);
    printf("d. GID:                    %d\n", sb.st_gid);
    printf("e. Size:                   %lld bytes\n", (long long)sb.st_size);
    printf("f. Block size:             %ld bytes\n", (long)sb.st_blksize);
    printf("g. Number of blocks:       %ld\n", (long)sb.st_blocks);
    printf("h. Time of last access:    %s", ctime(&sb.st_atime));
    printf("i. Time of last mod:       %s", ctime(&sb.st_mtime));
    printf("j. Time of last change:    %s", ctime(&sb.st_ctime));

    return 0;
}
