#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

this task checks for symmetry given a line from command line

*/

// this checks the symmetry of the word by comparing the i'th term with the len - i of the line
void is_symmetric(char line[], int len_line) {

    int i;
    for (i = 0; i <  len_line; ++i) {

        if (line[i] != line[len_line - i]) {
            printf("no\n");
            return;
        }
    }

    printf("yes\n");

}

// main function passes necessary arguments
int main(int argc, char *argv[])
{

    char * line = argv[1];

    is_symmetric(line, strlen(line) - 1);

    return 0;
}
