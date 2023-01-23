#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char** argv) {
    struct dirent *dir;
    DIR *dname;

    if (argc != 2) {
        puts("Usage: ./a.out <dirname>");
        exit(-1);
    }

    dname = opendir(argv[1]);
    if (dname == NULL) {
        perror(argv[1]);
        exit(-1);
    }

    while ((dir = readdir(dname)) != NULL)
        puts(dir -> d_name);

    return 0;
}
