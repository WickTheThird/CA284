#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

int odds = 0;

for (int i = 1; i < 15; i++) {
    int temp = atoi(argv[i]) % 2;

    if (temp != 0) {
        odds++;
    }
}
printf("%d\n", odds);
return 0;
}