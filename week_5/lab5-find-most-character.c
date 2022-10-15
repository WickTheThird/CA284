#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

 ----- THE TASK -----

 Write a program lab5-find-most-character.c which accept an input string as argument. 
 The program find the character which has the most number of appearance in the string and print the character out.
 You can assume there is only one most frequent character. Again, use pointer as much as you can in this exercise.

*/

char * most_frequent_char(char * line []) {

    char * the_str = *line;

    char * which_char;

    int counter = 0;
    int comp = 0;

    for (int i = 0; i < strlen(the_str); ++i) {

        char * final_str = &(the_str)[0];

        int comp = 0;

        for (int j = 0; j < strlen(the_str); ++j) {

            if (final_str[i] == final_str[j] && final_str[i] != ' ') {
                comp++;
            }
        }

      if (counter < comp) {
           counter = comp;
           char * final_final_str = &(the_str)[0];
           which_char = &(final_final_str[i]);
      }

    }

    return &(which_char)[0];

}

int main(int argc, char *argv[])
{

    char * line = argv[1];

    char * freq_char = most_frequent_char(&(line));

    printf("%c\n", freq_char[0]);

    return 0;
}
