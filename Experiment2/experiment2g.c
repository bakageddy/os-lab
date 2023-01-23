#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    int fd;
    char buf[100];
    if (argc < 2) {
        puts("Usage: ./a.out <filename>");
        exit(-1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("%s file does not exit\n", argv[1]);
        exit(-1);
    }

    printf("Contents of the file %s is :\n", argv[1]);
    while (read(fd, buf, sizeof(buf)) > 0)
        printf("%s", buf);
    puts("");
    close(fd);
    return 0;
}
