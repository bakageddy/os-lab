#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        puts("Usage: ./a.out <filename>");
        exit(-1);
    }

    int fd, n , len;
    char buf[100];

    fd = open(argv[1], O_APPEND | O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror(argv[1]);
        exit(-1);
    }

    while ((n = read(0, buf, sizeof(buf))) > 0) {
        len = strlen(buf);
        write(fd, buf, len);
    }

    close(fd);
    return 0;
}
