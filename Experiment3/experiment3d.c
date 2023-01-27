#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int fd;
    if (argc != 2)
        exit(-1);
    fd = open(argv[1], O_RDONLY);
    if (fd != -1) {
        close(fd);
        unlink(argv[1]);
    } else {
        perror(argv[1]);
    }
    return 0;
}
