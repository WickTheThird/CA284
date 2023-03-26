#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int find_max (int arr [], int len) {

    int max_nr = arr[0];

    for (int i = 1; i < len; ++i) {

      if (max_nr < arr[i]) {
          max_nr = arr[i];
      }

    }

    return max_nr;

}

int main(int argc, char *argv[])
{

    int nr_li[argc - 1];

    int i;
    int j = 0;

    for (i = 1; i < argc; i++) {
        nr_li[j] = atoi(argv[i]);
        ++j;
    }

    printf("%d\n", find_max(nr_li, argc - 1));

    return 0;
}


