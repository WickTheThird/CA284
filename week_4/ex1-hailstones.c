#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

This task depends on either the given number from the
command line is even or not
If its evem you half the number, otherwise you multiply it by 3 and add 1 to it
and break when the nuber is 1, then just print the sequence up ubtil 1

*/

// recursively calculating the sequence
// and return when the number is 1
// we then pass the corresponding calculation to the function again
// in otder to calculate the sequence/ the next number
void the_hailstone_seqence(int n) {

    if (n == 1) {
        printf("1\n");
        return;

    } else if ((n % 2) == 0) {
        printf("%d ", n);
        the_hailstone_seqence(n / 2);

    } else if ((n % 2) == 1) {
        printf("%d ", n);
        the_hailstone_seqence((3 * n) + 1);

    }
}

// the main takes the number from command line and turns it into an integer
// then it passes it to the recursive function
int main(int argc, char *argv[])
{

    int the_hail_number = atoi(argv[1]);
    the_hailstone_seqence(the_hail_number);

    return 0;

}
