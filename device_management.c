#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char buffer[100];

    int device = open("/dev/zero", O_RDONLY);
    if (device < 0)
    {
        perror("open device");
        return 1;
    }

    int file = open("output.txt",
                    O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file < 0)
    {
        perror("open output file");
        close(device);
        return 1;
    }

    ssize_t n = read(device, buffer, 100);
    if (n != 100)
    {
        perror("read");
        close(device);
        close(file);
        return 1;
    }

    ssize_t written = write(file, buffer, n);
    if (written != n)
    {
        perror("write");
        close(device);
        close(file);
        return 1;
    }

    printf("Read %ld bytes from /dev/zero.\n", (long)n);
    printf("Wrote %ld bytes to output.txt.\n", (long)written);

    close(device);
    close(file);
    return 0;
}