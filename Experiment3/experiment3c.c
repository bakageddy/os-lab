#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define SIZE 1024

int main(int argc, char** argv) {
    int src, dst, nread;
    char buf[SIZE];
    if (argc != 3) {
        puts("Usage: ./a.out <src> <dst>");
        exit(-1);
    }

    if ((src = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(-1);
    }

    if ((dst = creat(argv[2], 0644)) == -1) {
        perror(argv[2]);
        exit(-1);
    }

    while ((nread = read(src, buf, SIZE)) > 0) {
        if (write(dst, buf, nread) == -1) {
            printf("Can't write!\n");
            exit(-1);
        }
    }

    close(src);
    close(dst);

    return 0;
}
