#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE *file;
    char line[100], word[30], c;
    int i, j, k;
    if (argc != 3) {
        puts("Usage: ./a.out <word> <file>");
        exit(-1);
    }

    file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("File doesn't exist\n");
        exit(-1);
    }

    while (!feof(file)) {
        i = 0;
        while (1) {
            c = fgetc(file);
            if (c == '\n') {
                line[i++] = '\0';
                break;
            }
            if (feof(file)) {
                line[i++] = '\0';
                break;
            }
            line[i++] = c;
        }
        if (strlen(line) >= strlen(argv[1]))
            for (j = 0; j <= strlen(line) - strlen(argv[1]); j++) {
                for (k = 0; k < strlen(argv[1]); k++)
                    word[k] = line[k + j];
                word[k] = '\0';
                if (strcmp(word, argv[1]) == 0) {
                    printf("%s\n", line);
                    break;
                }
            }
    }
    return 0;
}
