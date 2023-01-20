#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

typedef struct stat Stat;

int main(int argc, char **argv) {
    Stat file;
    int n;
    if (argc != 2) {
        printf("Usage: <executable> <filename>\n");
        exit(0);
    } if ((n = stat(argv[1], &file)) == -1) {
        perror(argv[1]);
        exit(-1);
    }
    printf("User ID: %d\n", file.st_uid);
    printf("Group ID: %d\n", file.st_gid);
    printf("Block Size: %ld\n", file.st_blksize);
    printf("Block ID: %ld\n", file.st_blocks);
    printf("Inode No: %ld\n", file.st_ino);
    printf("Last Accessed: %s\n", ctime((long *) &(file.st_atim)));
    printf("Last Modified: %s\n", ctime((long *) &(file.st_mtim)));
    printf("File size: %ld\n", file.st_size);
    printf("No. of links: %ld\n", file.st_nlink);

    printf("Perimissons: ");
    printf(S_ISDIR(file.st_mode) ? "d" : "-");

    printf(file.st_mode & S_IRUSR ? "r" : "-");
    printf(file.st_mode & S_IWUSR ? "w" : "-");
    printf(file.st_mode & S_IXUSR ? "x" : "-");

    printf(file.st_mode & S_IRGRP ? "r" : "-");
    printf(file.st_mode & S_IWGRP ? "w" : "-");
    printf(file.st_mode & S_IXGRP ? "x" : "-");

    printf(file.st_mode & S_IROTH ? "r" : "-");
    printf(file.st_mode & S_IWOTH ? "w" : "-");
    printf(file.st_mode & S_IXOTH ? "x" : "-");
    puts("");

    if (S_ISDIR(file.st_mode))
        puts("Directory");
    else puts("Regular file");
    return 0;
}
