#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    ---  The task ---

    Write a program lab5-count-character.c which accepts two arguments. The first argument is a string and the the second argument is a character. 
    You can assume that the lowercase and uppercase of a character are two different cases, e.g. C is not c. 
    The program count the number of occurences of the character in the string and print the result. 
    If the character does not exist in the string, print 0.
    Note that, you are asked to use pointers for this exercise. So, try to use pointer as much as you can.

*/


int which_char(char * the_char [], char * the_str []) {

    char * search_str =  *the_str;
    char * which_letter = *the_char;

    int j = 0;
    for (int i = 0; i < strlen(search_str); ++i) {

        char * n = &(search_str)[0];

        if (*which_letter == n[i]) {
            j++;
        }

    }

    return j;
}


int main(int argc, char *argv[])
{
    char * the_char = argv[1];
    char * the_str = argv[2];

    int no_inst = which_char(&(the_char), &(the_str));

    printf("%d\n", no_inst);

    return 0;
}
