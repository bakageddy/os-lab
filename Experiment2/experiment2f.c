#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** argv) {
    int fd, n, len;
    char buf[100];
    if (argc != 2) {
        puts("Usage: ./a.out <filename>");
        exit(-1);
    }

    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        puts("File creation error!\n");
        exit(-1);
    }
    printf("CTRL-D to stop writing to file\n");
    while ((n = read(0, buf, sizeof(buf))) > 0) {
        len = strlen(buf);
        write(fd, buf, len);
    }
    close(fd);
    return 0;
}
