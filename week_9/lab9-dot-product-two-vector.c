#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declarations

int dot_product(int* pArr);

// main
int main(int argc, char *argv[])
{

    int *pArr = (int*)malloc((argc - 1)*sizeof(int));
    int total = 0;

    if (!pArr) {
        printf("Failed to allocate memory!");
        return 0;
    }

    int count = 0;
    for (int i = 1; i < argc; ++i, ++count) {
        *(pArr + count) = atoi(argv[i]);
    }

    total = dot_product(pArr);

    free(pArr);

    printf("%d\n", total);

    return 0;
}


int dot_product(int* pArr) {

    int vectorSize = *(pArr);
    int total = 0;

    for (int i = 1; i <= vectorSize; ++i) {

        total += (*(pArr + i) * *(pArr + i + vectorSize));
    }

    return total;

}