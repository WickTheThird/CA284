#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

int nr_cmd = argc + 1;
int total = 0;

for (int i = 0; i < nr_cmd - 1; i++) {
    
    int odd_nr = atoi(argv[i]) % 2;

    if (odd_nr != 0) {
        total++;
    }
}

printf("%i\n", total);

return 0;

}