#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_nr(int nr, int arr [], int len_arr) {

    for (int i = 0; i < len_arr; ++i) {

        if (nr == arr[i]) {
            printf("Found %d at %d\n", nr, i);
            return 0;
        }

    }

    printf("%d not found\n", nr);

    return 1;

}

int main(int argc, char *argv[])
{

    int missing = atoi(argv[1]);
    int the_nrs[argc - 1];

    int j = 0;
    for (int i = 2; i < argc; ++i) {
        the_nrs[j] = atoi(argv[i]);
        j++;
    }

    find_nr(missing, the_nrs, argc - 2);

    return 0;
}
