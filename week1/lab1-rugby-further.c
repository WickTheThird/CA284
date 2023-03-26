#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int try, conv, pen, drg;

/*

1.
    int run = 0;
    while (run < 1) {
        
        scanf("%d", &try);
        scanf("%d", &conv);
        scanf("%d", &pen);
        scanf("%d", &drg);

        if (run < 0 || try < 0 || conv < 0 || pen < 0) {
            printf("\033[0;31mPlease do not enter negative values\n\033[0m");
        } else {
            run++;
        }
    }
*/

/*

2.Instrunctions unclear on seccond one, as input already takes whatever value

        scanf("%d", &try);
        scanf("%d", &conv);
        scanf("%d", &pen);
        scanf("%d", &drg);

*/


    
    try *= 5;
    conv *= 2;
    pen *= 3;
    drg *= 3;

    int final = try + conv + pen + drg;

    printf("%d\n", final);

  return 0;
}
