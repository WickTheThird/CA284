#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_dub(int arr [], int len_arr) {

    int dub_arr [len_arr];
    int dub_ind = 0;

    for (int i = 0; i < len_arr; ++i) {
        for (int j = i + 1; j < len_arr; ++j) {

            if (arr[i] == arr[j]) {
                dub_arr[dub_ind] = arr[i];
                dub_ind++;
                break;
            }
        }
    }

    if (dub_ind > 0) {
        printf("%d\n", dub_arr[0]);
    } else {
        printf("no duplicated number\n");
    }

}

int main(int argc, char *argv[])
{

    int the_nrs[argc - 1];

    int j = 0;
    for (int i = 1; i < argc; ++i) {
        the_nrs[j] = atoi(argv[i]);
        j++;
    }

    find_dub(the_nrs, argc - 1);

    return 0;
}
