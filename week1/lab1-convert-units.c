#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

    float cm = atoi(argv[1]);
    float inch = 2.54;

    float final = cm / inch;

    printf("%.2f\n",final);

  return 0;
}
