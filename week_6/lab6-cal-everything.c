#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct SomeCalculations SomeCalculations;

struct SomeCalculations { 

    float sum;
    float diff;
    float prod;
    float dev;
    float pow;
    float nat_log;

};

int main(int argc, char *argv[])
{

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    SomeCalculations the_calc;

    the_calc.sum = num1 + num2;
    the_calc.diff = num1 - num2;
    the_calc.prod = num1 * num2;
    the_calc.dev = num1 / num2;
    the_calc.pow = pow(num1, num2);
    the_calc.nat_log = log(num1) + log(num2);

    printf("%.2f\n", the_calc.sum);
    printf("%.2f\n", the_calc.diff);
    printf("%.2f\n", the_calc.prod);
    printf("%.2f\n", the_calc.dev);
    printf("%.2f\n", the_calc.pow);
    printf("%.2f\n", the_calc.nat_log);

    return 0;
}
