#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declarations

void seccond_largest(float *pArr, int len);
float *sort(float * pArr, int len);
float* remove_duplicates(float *pArr, int len);

// main
int main(int argc, char *argv[])
{
    float *pArr = (float*)calloc((argc - 1), sizeof(float));

    int count = 0;
    for (int i = 1; i < argc; ++i, ++count) {
        *(pArr + count) = atof(argv[i]);
    }

    seccond_largest(pArr, count);

    return 0;
}

void seccond_largest(float *pArr, int len) {

    for (int i = len; i > 0; --i) {

        int element = *(remove_duplicates(sort(pArr, len), len) + i);

        if (element != 0) {
              printf("%.1f\n", *(remove_duplicates(sort(pArr, len), len) + i - 1));
              break;
        }
    }

    free(pArr);
}

float *sort(float * pArr, int len) {

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

float* remove_duplicates(float *pArr, int len) {

    float* newpArr = (float*)calloc(len, sizeof(float));

    int counter = 0;

    for (int i = 0; i < len; ++i, ++counter) {

        float element = *(pArr + i);

        for (int j = i + 1; j < len; ++j) {

            if (element == *(pArr + j)) {

               while (element == *(pArr + j)) {
                   ++j;
               }
               i = j - 1;
               break;
            }
        }

        *(newpArr + counter) = *(pArr + i);

    }

    return newpArr;
}
