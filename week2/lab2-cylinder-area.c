#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415 /*Defining PI as a constant*/

int main(int argc, char *argv[])
{

if (argc < 3) {
    if (argc == 1) {
        printf("No input given!\n");
        return 1;
    }
    else if (argc == 2) {
        printf("Two arguments needed!\n");
        return 1;
    }
}

double radius = atoi(argv[1]);
double height = atof(argv[2]);

if ((radius == (-1 * radius) && radius > 0) || (height == (- 1 * height) && height > 0)) {
    printf("The radious or height cannot be negative!\n");
    return 1;
}

else {
    double area = (2 * PI * radius * height) + (2 * PI * radius * radius);
    printf("%.2f\n", area);
}

return 0;
}
