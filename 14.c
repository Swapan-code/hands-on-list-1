#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;

    struct stat sb;
    if (lstat(argv[1], &sb) == -1) {
        perror("lstat error");
        return 1;
    }

    if (S_ISREG(sb.st_mode))       printf("%s: Regular File\n", argv[1]);
    else if (S_ISDIR(sb.st_mode))  printf("%s: Directory\n", argv[1]);
    else if (S_ISLNK(sb.st_mode))  printf("%s: Symbolic Link\n", argv[1]);
    else if (S_ISFIFO(sb.st_mode)) printf("%s: FIFO / Pipe\n", argv[1]);
    else if (S_ISCHR(sb.st_mode))  printf("%s: Character Device\n", argv[1]);
    else if (S_ISBLK(sb.st_mode))  printf("%s: Block Device\n", argv[1]);
    else printf("%s: Unknown File Type\n", argv[1]);

    return 0;
}
