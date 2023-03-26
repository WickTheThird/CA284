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

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    int count = 0;
    for (int i = 0; i < j; ++i) {

        if (count == 3) {

            printf("%s\n", country.info[i - 1]);

            count = 0;

        } else if (count == 2) {

            printf("%s\t\t\t", country.info[i + 1]);
            ++count;

        } else {
            printf("%s\t\t\t", country.info[i]);
            ++count;
        }
    }

    return 0;
}
