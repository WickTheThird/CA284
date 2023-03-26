#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int try, conv, pen, drg;

    try = atoi(argv[1]) * 5;
    conv = atoi(argv[2]) * 2;
    pen = atoi(argv[3]) * 3;
    drg = atoi(argv[4]) * 3;

    int final = try + conv + pen + drg;

    printf("%d\n", final);

  return 0;
}
