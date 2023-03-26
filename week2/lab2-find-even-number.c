#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

int count = 0;
int nr_cmd = argc + 1;
int total = 0;

for (int i = 1; i < nr_cmd - 1; i++) {
    
    int even_nr = atoi(argv[i]) % 2;
    int the_nr = atoi(argv[i]);

    if (even_nr == 0) {
        printf("%i - %i\n", i - 1, the_nr);
        count++;
    }
}

if (count == 0) {
    printf("Not found!\n");
}

return 0;

}