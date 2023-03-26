#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declarations

void longest_string(int * pArr, char * argv[], int len);
int find_max(int * pArr, int len);

// main
int main(int argc, char *argv[])
{

    int *pArr = (int*)malloc((argc - 1)*sizeof(int));

    int counter = 0;
    for (int i = 1; i < argc; ++i, ++counter) {
        int size = strlen(argv[i]);
        *(pArr + counter) = size;
    }

    longest_string(pArr, argv, argc - 1);

    free(pArr);

    return 0;
}

void longest_string(int * pArr, char *argv[], int len) {

    int max;
    max = find_max(pArr, len);

    for (int i = 1; i <= len; ++i) {

        if (strlen(argv[i]) == max) {
            printf("%s\n", argv[i]);
        }
    }
}


int find_max(int * pArr, int len) {

    int max = *(pArr);

    for (int i = 0; i < len; ++i) {

        if (*(pArr + i) > max) {
            max = *(pArr + i);
        }

    }

    return max;
}
