#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

int main(int argc, char *argv[])
{
	int radius = 0;
	float area;

	radius = atoi(argv[1]);

/*

    ERROR MESSAGE

    if (radius < 0) {
        printf("Radius must be non-negative.\n");
        return 0;
    } else {
        -> the rest of the code goes here...
    }
*/

 /*

    CORRECTING THE INPUT BUG

    if (radius < 0) {
        printf("\033[0;31mSince your input was %d, I fixed it by turning the negative value into a positive one.\n\033[0m", radius);
	    radius = radius*radius*(-1);
    } else {
        radius *= radius;
    }

*/

    radius = radius*radius;
	area = radius*PI;
    printf ("%.2f\n", area);

    /*
    The reason for the different answers is due to the way C multiplies two numbers (binary).
    */

    return (0);
}
