#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    printf("Parent PID: %d\n", getpid());

    for (int i = 1; i <= 2; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            printf("Child %d PID: %d\n", i, getpid());

            if (i == 1)
            {
                execl("/bin/echo", "echo",
                      "Child 1: exec() program running",
                      (char *)NULL);
                perror("exec failed");
            }

            return 0;
        }
        else if (pid < 0)
        {
            perror("fork failed");
            return 1;
        }
    }

    wait(NULL);
    wait(NULL);

    printf("Parent: both children have finished.\n");
    return 0;
}