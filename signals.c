#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void handle_sigtstp(int sig)
{
    const char message[] =
        "\nSIGTSTP received (Ctrl+Z). Program continues.\n";
    (void)sig;
    write(STDOUT_FILENO, message, sizeof(message) - 1);
}
int main(void)
{
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, handle_sigtstp);
    printf("Signal demonstration is running.\n");
    printf("SIGINT (Ctrl+C) is ignored.\n");
    printf("SIGTSTP (Ctrl+Z) is handled.\n");
    printf("Program will end after 20 seconds.\n");
    for (int i = 1; i <= 20; i++)
    {
        sleep(1);
        printf("Still running: %d seconds\n", i);
        fflush(stdout);
    }

    printf("Program finished normally.\n");
    return 0;
}