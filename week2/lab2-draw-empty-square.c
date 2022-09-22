#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415 /*Defining PI as a constant*/

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("No input given!\n");
        return 1;
    }

    int sqr_len = atoi(argv[1]);

    for (int i = 0; i < (sqr_len); i++) {
        printf("*");
    }

    printf("\n");

    for (int i = 0; i < (sqr_len - 2); i++) {

        printf("*");

        for (int j = 0; j < sqr_len - 2; j++) {
            printf(" ");
        }

        printf("*\n");
    }

    for (int i = 0; i < (sqr_len); i++) {
        printf("*");
    }

    printf("\n");
    
    return 0;
}