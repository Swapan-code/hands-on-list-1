#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int pid = getpid();

    int priority = getpriority(PRIO_PROCESS, pid);
    printf("Initial Nice Priority Value: %d\n", priority);

    printf("Modifying nice value by +5...\n");
    nice(5);

    priority = getpriority(PRIO_PROCESS, pid);
    printf("Updated Nice Priority Value: %d\n", priority);

    return 0;
}
