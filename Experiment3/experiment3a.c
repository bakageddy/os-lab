#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char **argv) {
    struct dirent **namelist;
    int n;
    char pathname[100];

    getcwd(pathname, sizeof(pathname));
    n = scandir(pathname, &namelist, 0, alphasort);

    if (n < 0)
        puts("Error\n");
    else
        for(int i = 0; i < n; i++)
            if (namelist[i] -> d_name[0] != '.')
                printf("%-20s\n", namelist[i] -> d_name);
    return 0;
}
