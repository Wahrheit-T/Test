#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", argv[2]);
        return 1;
    }

    int count = 0;
    int c;
    if (argv[1][1] == 'c') {
        while ((c = fgetc(file)) != EOF) {
            count++;
        }
        printf("字符数：%d\n", count);
    } else if (argv[1][1] == 'w') {
        int in_word = 0;
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == '\n' || c == '\t') {
                in_word = 0;
            } else if (!in_word) {
                in_word = 1;
                count++;
            }
        }
        printf("单词数：%d\n", count);
    } else {
        printf("Error: Invalid parameter\n");
        return 1;
    }

    fclose(file);
    return 0;
}
