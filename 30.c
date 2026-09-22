#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

void create_daemon() {
    pid_t pid = fork();
    if (pid > 0) exit(0); // Exit Parent

    if (setsid() < 0) exit(1); // Become Session Leader

    pid = fork();
    if (pid > 0) exit(0); // Ensure process cannot acquire terminal again

    umask(0);
    chdir("/"); // Change directory to root

    // Close Standard File Descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    create_daemon();

    // Background scheduled task: writes timestamp to log file every 5 seconds
    while (1) {
        FILE *fp = fopen("/tmp/daemon_test.log", "a");
        if (fp != NULL) {
            time_t now = time(NULL);
            fprintf(fp, "Daemon executed task at: %s", ctime(&now));
            fclose(fp);
        }
        sleep(5);
    }
    return 0;
}
