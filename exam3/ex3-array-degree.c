//
// Filip Bumbu, printing the highest frequency from the given array, 30/11/22
// The way I went about this:
//     -> I have initiated a struct with the necesarry info (number) including a reference to the next value;
//     -> Then I have taken the argv and have created a linked list based on the info from the struct;
//     -> Then I passed the start to a printing function to print the linked list with necesarry information;
//     -> Finally I used a seccond loop to compare and find the highest frequency;
//
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// the struct having all the necesarry information
typedef struct Number Number;
struct Number {

    int number;
    Number *next;
};

// declarations
Number * link_nrs(char * arr[], int len);
void printHighestFreq(Number *start, char* arr[], int len);

// main
int main(int argc, char *argv[])
{
    Number* start = NULL;

    start = link_nrs(argv, argc - 1);
    printHighestFreq(start, argv, argc - 1);

    return 0;
}

// linked list
Number * link_nrs(char * arr[], int len) {

    // initiating current and first to be the first node
    Number *current, *first;
    
    first = (Number*)malloc(sizeof(Number));
    current = first;

    // filling out the first node
    current->number = atoi(arr[1]);

    // assigning the rest based on the first node
    for (int i = 2; i <= len; ++i) {

       current->next = (Number*)malloc(sizeof(Number));
       current = current->next;

       current->number = atoi(arr[i]);

    }


    // ending the linked list
    current->next = NULL;
    // returning the head
    return first;

}

// printing the linked list
void printHighestFreq(Number *start, char * arr[], int len) {

    int count = 0;
    Number *p = NULL;

    // this is the final value
    int highest = 0;
    // this is a tmp value that is to be compared with highest value
    int tmp = 0;
    for (p = start; p != NULL; p = p -> next) {
        ++count;
        // looking for frequency of p -> next
        for (int i = 1; i <= len; ++i) {
            if (p->number == atoi(arr[i])) {
                ++tmp;
            }
        }
        // comparing the tmp to highest to see which one is the keeper
        if (highest < tmp) {
            highest = tmp;
        }
        // emptying the tmp
        tmp = 0;
    }
    // printing the highest values
    printf("%d\n", highest);
}
