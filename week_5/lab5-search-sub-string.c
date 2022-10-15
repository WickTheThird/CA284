#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FINDING THE LENGHT OF THE LINE

int get_len(char* line) {

    int i = 0;
    while (line[i] != '\0') {
        ++i;
    }

    return i;

}

// TOKENISING LINE BASED ON A DELIMITOR

// CHECKING THE DELIMITOR
unsigned int is_delim(char c, char * delim) {
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

// ASSIGNING TOKENS BASED ON THE DELIMITOR AND ALSO PASSING THE NEXT POTENTIAL VALUE AT THE SAME TIME
char * split (char * line, char* delim) {
    
    // NEXT TOKEN...
    static char *backup_str;

    // CHECKER
    if (!line) {
        line = backup_str;
    }

    if (!line) {
        return NULL;
    }

    // FINDING DELIMITORS AND CHECKING END OF LINE
    while (1) {

        if ( is_delim(*line, delim) ) {
            line++;
            continue;
        }
        if ( *line == '\0') {
            return NULL;
        }

        break;
    } 

    // RETURN VALUE
    char *ret = line;

    // RETURNING THE NEEDED TOKEN AND ASSIGNING THE NEXT TOKEN UNTIL THE END OF LINE
    while (1) {
        if (*line == '\0') {
            backup_str = line;
            return ret;
        }

        if (is_delim(*line, delim)) {
            *line = '\0';
            backup_str = line + 1;
            return ret;
        }
        line++;
    } 

}

// COMPARING TWO STRINGS
// NOTE: THERE ARE SOME ISSUES WITH THE COMPARE STRING, AS IT DOES NOT CARE FOR PUNCTUATION (thus it fails if punctuation is after the word saughtafter)

int compare_string(char * word1, char * word2) {

    int len_word_1 = 0;
    while (word1[len_word_1] != '\0') {
        ++len_word_1;
    }

    int len_word_2 = 0;
    while (word1[len_word_2] != '\0') {
        ++len_word_2;
    }

    if (len_word_1 == len_word_2) {

        int checker = 0;
        while (word1[checker] == word2[checker]) {
            ++checker;
        }

        if (checker - 1 == len_word_1) {
            return 0;
        }

    }

    return 1;
}

// FINDING THE WORD IN THE LINE

int find_str(char* line, char* word) {

    int len_arr = get_len(line);
    char* arr = split(line, " ");
    char* split_line_arr[len_arr];

    int i = 0;
    while (arr != NULL) {

        split_line_arr[i] = arr;
        arr = split(NULL, " ");

        ++i;

    }

    for (int j = 0; j < i; ++j) {
       
       if (compare_string(split_line_arr[j], word) == 0) {
           return j;
       }
    }
    return 0;
}

// FINDING INDEX OF WORDS IN A STRING

void get_word_index(char * str, char * word) {


    int len_line = get_len(str);
    char ch[1];

    int ind = find_str(str, word);

    int delim = 0;
    int arr_in = 0;
    for (int i = 0; i <= len_line; ++i) {

        ch[0] = str[0];

        if (ch[0] == ' ' || ch[0] == '\0') {

            if (arr_in == ind) {
                printf("%d %d\n", delim, i - 1);
                break;
            }

            delim = i + 1;
            ++arr_in;

        }

    str++;

    }

}

// MAIN FUNCTION

int main(int argc, char *argv[])
{

    char * line = argv[1];
    char * word = argv[2];

    get_word_index(line, word);

    return 0;
}
