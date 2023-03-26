#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int str_len(char line[50]);
void inverse(char line[50]);

int main(int argc, char *argv[])
{

    char line[50];
    for (int i = 1; i < argc; ++i) {

        strcat(line, argv[i]);
        if (str_len(line) > 0) {
            strcat(line, " ");
        }
    }

    inverse(line);
    return 0;
}

int str_len(char line[50]) {

    int i;
    for (i = 0; line[i] != '\0'; ++i);

    return i;
}

void inverse(char line[50]) {

    int i = str_len(line) - 2;

    while (i != -1) {

        printf("%c", line[i]);

        i--;
    }

    printf("\n");

}
