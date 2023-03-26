#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int find_max (int arr [], int len_arr) {

    int max = arr[0];

    int j = 0;
    for (int i = 1; i < len_arr; ++i) {

        if (max < arr[i]) {
            max = arr[i];
            j = i;
        }
    }

    return j;
}

void find_longest_string (char *line, int len_line) {

    int lens[len_line];
    char *split_words[len_line];
    char *words = strtok(line, " ");

    int i = 0;
    while (words != NULL) {

        split_words[i] = words;
        lens[i] = strlen(words);
        words = strtok(NULL, " ");

        ++i;
    }

    printf("%s\n", split_words[find_max(lens, i)]);

}

int main(int argc, char *argv[])
{

    char * line = argv[1];
    int len_line = strlen(line);

    find_longest_string(line, len_line);

    return 0;
}
