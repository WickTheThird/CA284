#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    int height = atoi(argv[1]);
    int width = atoi(argv[2]);

    for (int i = 0; i < width; ++i) {
        printf("*");
    }
    printf("\n");

    for (int i = 0; i < height - 2; ++i) {
        printf("*");
        for (int i = 0; i < width - 2; ++i) {
            printf(" ");
        }
        printf("*\n");
    }

    for (int i = 0; i < width; ++i) {
        printf("*");
    }

    printf("\n");

}