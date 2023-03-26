#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 13/11/22
// Filip Bumbu, we have to inputs from command line a string and a search key...we either search for the longest or the shortest sentence in the given string
//  if no valid key is given, we print the number of characters in the longest sentance while also0 saying 'Not Valid';
//
// The way I went about this:
//      -> We need to find all sentances, find their lenghts and finally store thir positions;
//      -> I will store the positions inside a linked list;
//      -> 
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//
// declarations
typedef struct Sentence Sentence;
struct Sentence {
    int len_sent[200];
    int pos[500];
    int nr_sent;
};

void split_string(char *str, int len, char *type);
void print_sentence(char *type, char *str, Sentence sentence);

// main function
int main(int argc, char **argv) {
    
    // printing the corresponding sentence
    if (strcmp(argv[2], "longest") == 0) {
        //print_sentence("longest", argv[1], sentence);
        split_string(argv[1], strlen(argv[1]), "longest");
    } else if (strcmp(argv[2], "shortest") == 0) {
        //print_sentence("shortest", argv[1], sentence);
        split_string(argv[1], strlen(argv[1]), "shortest");
    } else {
        printf("Not Valid\n");
    } 

    return 0;
}

// other
// spliting the functions into sentances
void split_string(char *str, int len, char *type) {

    // initiating the struct
    Sentence sentence;
    // finging each sentance
    int counter = 0; // counting the position...this is the index of starting and ending of a sentance
    int len_sent = 0; // lenght of each sentance
    int single_quoted = 0; // this is keeping track of each single quoted sentance
    int index = 0; // number of sentance
    for (int i = 0; i < len; ++i, ++counter, ++len_sent) {

        if (str[i] == '\'' && single_quoted == 0) { // initiating a single quoted sentance
            sentence.len_sent[index] = len_sent;
            len_sent = 0;
            sentence.pos[index] = counter;
            ++single_quoted;
            ++index;
        }

        if ((str[i] == '\'' && str[i + 1] == '.') && single_quoted == 1) { // end of quoted string
            sentence.len_sent[index] = len_sent + 2;
            sentence.pos[index] = counter;
            len_sent = 0;
            single_quoted = 0;
            ++index;
        }

        if (single_quoted == 0 && (str[i] == '?' || str[i] == '.')) { // start and end of a sentence
            sentence.len_sent[index] = len_sent;
            len_sent = 0;
            sentence.pos[index] = counter;
            ++index;
        }
    }
    
    sentence.nr_sent = index;

     if (strcmp(type, "longest") == 0) {
        print_sentence("longest", str, sentence);
    } else if (strcmp(type, "shortest") == 0) {
        print_sentence("shortest", str, sentence);
    }
}

// printing the function accordingly
void print_sentence(char *type, char *str, Sentence sentence) {
    // printing the coorect sentance
    if (strcmp(type, "longest") == 0) {

        // initiating the bigger count
        int biggest = 0;
        int index = 0;
        // finding the biggest
        for (int i = 0; i < sentence.nr_sent; ++i) {

            if (biggest < sentence.len_sent[i]) {
                biggest = sentence.len_sent[i];
                index = i;
            }
        }

        printf("%d\n", biggest);

        int count = 0;
        for (int i = 0; i < strlen(str); ++i) {

            if (i >= sentence.pos[index - 1]) {
                printf("%c", str[sentence.pos[index - 1] + count]);
                ++count;
            }
             if (i == sentence.pos[index]) {
                printf("%c\n", str[sentence.pos[index - 1] + count]);
                break;
             }

        }

    } else if (strcmp(type, "shortest") == 0) {

        // initiating the smaller count
        int smallest = sentence.len_sent[0];
        int index = 0;
        // finding the smallest
        for (int i = 1; i < sentence.nr_sent; ++i) {

            if (smallest > sentence.len_sent[i]) {
                smallest = sentence.len_sent[i];
                index = i;
            }
        }

        printf("%d\n", smallest + 1);
        printf("%d\n", index);

        int count = 0;
        for (int i = 0; i < sentence.nr_sent; ++i) {

            if (i >= sentence.pos[index]) {
                printf("%c", str[sentence.pos[index] + count]);
                ++count;
            }
            if (i == sentence.pos[index]) {
                printf("%c\n", str[sentence.pos[index] + count]);
                break;
            }

        } 

    }
 
}
