#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid;
    int x = 5;
    pid = fork();
    if (pid == -1) {
        puts("Child process creation failure\n");
        exit(-1);
    } else if (pid == 0) {
        puts("Child process: ");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
        x++;
        printf("Value of x is %d\n", x);
    } else {
        puts("Parent Process: ");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
        printf("Value of x is %d\n", x);
    }
    return 0;
}
