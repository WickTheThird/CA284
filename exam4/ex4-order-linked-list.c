#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
// Filip Bumbu, use a doubly linked lists to check if the order is descending or not...if so return a 1 else 0, 13/11/22
// The way I went about this:
//      -> I have added all the elements in a doubly linked list;
//      -> Afterwards, I have looped through them in a separate function, and then returned a value that relates to its order;
//      -> Finally I have printed that value in the main loop;
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//
// declarations

typedef struct Numbers Numbers;
struct Numbers {
    float number;
    Numbers *next;
    Numbers *prev;
};

Numbers* get_numbers(char *arr[], int len);
int compute_order(Numbers *last);

// main function
int main(int argc, char* argv[]) {

    // initiating the start
    Numbers *start = NULL;
    // this is the linked list
    start = get_numbers(argv, argc - 1);
    // compute the order of the numbers
    printf("%d\n", compute_order(start));

    return 0;
}

// other
// assigning the given numbers to a doubly linked list
Numbers* get_numbers(char *arr[], int len) {
     // initiating first, current and prev, to assign them to the list
    Numbers *first, *current, *prev;
    // equating the current with the first
    first = (Numbers*)malloc(sizeof(Numbers));
    current = first;
    // filling out the first node
    current->number = atof(arr[len - 1]);
    current->prev = NULL;
    // assigning the rest of the nodes based on the first one
    for (int i = 2; i < len; ++i) {
        // allocate a new node
        current->next = (Numbers*)malloc(sizeof(Numbers));
        // get provious before moving to the next node
        prev = current;
        // move the current node to the next node
        current = current->next;
        // assigning the new node
        current->number = atof(arr[len - i]);
        current->prev = prev;
    }
    current->next = NULL;
    return current; // returning the address of the last node
}

// computing the order of the numbers and returning the 
int compute_order(Numbers *last) {

    Numbers *p = NULL;
    for (p = last; p->prev != NULL; p = p->prev) {
        if (p->number < p->prev->number) {
            return 0; // return 0 if the order is inproper
        }
    }
    // if the order is poroper it reurns a 1
    return 1;

}
