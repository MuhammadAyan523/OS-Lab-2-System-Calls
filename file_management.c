#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char buffer[128];
    int source = open("source.txt", O_RDONLY);

    if (source < 0)
    {
        perror("open source");
        return 1;
    }
   int destination = open("destination.txt",
                           O_WRONLY | O_CREAT | O_TRUNC, 0644);
   if (destination < 0)
    {
        perror("open destination");
        close(source);
        return 1;
    }
    ssize_t n;
    while ((n = read(source, buffer, sizeof(buffer))) > 0)
    {
        if (write(destination, buffer, n) != n)
        {
            perror("write copy");
            close(source);
            close(destination);
            return 1;
        }
    }
if (n < 0)
    {
        perror("read source");
        close(source);
        close(destination);
        return 1;
    }
close(source);
close(destination);
destination = open("destination.txt", O_WRONLY | O_APPEND);
    if (destination < 0)
    {
        perror("open for append");
        return 1;
    }
const char line[] = "\nThis line was appended by the program.\n";
if (write(destination, line, sizeof(line) - 1) != sizeof(line) - 1)
    {
        perror("append write");
        close(destination);
        return 1;
    }
close(destination);
printf("File copied and a line appended successfully.\n");
return 0;
}