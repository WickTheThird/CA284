#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

We are supposed to see of a number is triangular or not

The way i went about it is:

We are given an input...that will be our range

Then i pass the input in int form to a funtion

The funtion uses a loop, incrementing until it becomes 
bigger than the given number

Otherwise it returns if the formula i use checks

The formua to check if a number is truangular is

Tn = (n(n + 1)) / 2

And that's it

*/


void triangle_nr_calc(int the_nr) {

    int calc;
    for (int i = 0; i <= the_nr; ++i) {

        //formula
        calc = (i * (i + 1)) / 2;
        
        //checker
        if (calc == the_nr) {

            printf("%d is a triangular number\n", the_nr);

            return;
        }

    }

    // in case there's no number
    printf("%d is not a triangular number\n", the_nr);

}

// main function passing the nr as an int
int main(int argc, char *argv[])
{   

    int the_nr = atoi(argv[1]);

    triangle_nr_calc(the_nr);

    return 0;
}
