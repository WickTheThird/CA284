#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calc( char type[20], float num1, float num2);

int main(int argc, char *argv[])
{

    float num1 = atof(argv[2]);
    float num2 = atof(argv[3]);

    calc(argv[1], num1, num2);

    return 0;
}

void calc( char type[20], float num1, float num2) {

    char mult[20] = "multiply";
    char div[20] = "divide";

    float answer;

    if ( strcmp(type, mult) == 0 ) {
        answer = num1 * num2;
        printf("%f\n", answer);
    } else if ( strcmp(type, div) == 0 ) {

        if ( num1 != 0 && num2 != 0 ) {
            answer = num1 / num2;
            printf("%f\n", answer);
        } else {
            printf("invalid\n");
        }

    }

}
