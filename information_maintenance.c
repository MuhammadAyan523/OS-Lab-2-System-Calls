#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("+----------------------+------------+\n");
    printf("| Information          | Value      |\n");
    printf("+----------------------+------------+\n");
    printf("| UID                  | %-10u |\n", getuid());
    printf("| GID                  | %-10u |\n", getgid());
    printf("| PID                  | %-10d |\n", getpid());
    printf("| PPID                 | %-10d |\n", getppid());
    printf("+----------------------+------------+\n");

    return 0;
}