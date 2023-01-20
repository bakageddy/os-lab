#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) {
        puts("Process creation error!");
    }
    else if (pid > 0) {
        wait(NULL);
        puts("Parent: ");
        for (int i = 2; i <= 10; i += 2)
            printf("%d ", i);
        puts("");
    } else {
        puts("Child: ");
        for (int i = 1; i <= 11; i += 2)
            printf("%d ", i);
        puts("");
    }
    return 0;
}
