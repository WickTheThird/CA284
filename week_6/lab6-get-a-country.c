#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Countries Countries;

struct Countries {

    char * info[200];

};


int main(int argc, char *argv[])
{

    Countries country;

    int j = 0;
    for (int i = 1; i < argc; ++i) {
        country.info[j] = argv[i];
        ++j;
    }

    int count = 0;
    for (int i = 0; i < j; ++i) {

        if (count == 2) {

            printf("%s million people\n", country.info[i]);

        } else if (count == 3) {

            printf("%s km2\n", country.info[i]);

            count = 0;

        } else {
            printf("%s\n", country.info[i]);
        }

        ++count;
    }

    return 0;
}
