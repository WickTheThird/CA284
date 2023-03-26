#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declarations
void double_biggest(int * pArr, int len);
int* sort(int * pArr, int len);

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

    double_biggest(pArr, count);

    return 0;
}

void double_biggest(int * pArr, int len) {

    int *pDoubleLargest = (int*)calloc((0), sizeof(int));

    int counter = 1;
    for (int i = len - 1; i >= 0; --i) {

        int element = *(sort(pArr, len) + i);

        for (int j = i; j > 0; --j) {

            if ((element / 2) ==  *(sort(pArr, len) + j)) {

                int *pTemp = NULL;
                counter += 1;
                pTemp = realloc(pDoubleLargest, counter*sizeof(int));
                if(!pTemp)
                {
                    printf("Unfortunately memory reallocation failed.\n");
                    free(pDoubleLargest);
                    pDoubleLargest = NULL;
                    return;
                }

                *(pDoubleLargest + counter) = element;

            }
        }
    }

    printf("%d\n", *(pDoubleLargest + counter));

}

int* sort(int * pArr, int len) {

    int i, j, min_idx;

    for (i = 0; i < len - 1; ++i) {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < len; ++j) {
              if (*(pArr + j) < *(pArr + min_idx))
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        if(min_idx != i) {
            
            float temp = *(pArr + min_idx);
            *(pArr + min_idx) = *(pArr + i);
            *(pArr + i) = temp;
            
        }
    }

    return pArr;
}
