#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declarations

typedef struct Node Node;

struct Node {
    int value;
    Node* next;
};

// printing the linked list
void printLinkedList(struct Node* node);

// main
int main(int argc, char *argv[])
{

    // initialising head and current
    struct Node *head;
    struct Node *curent;

    // allocating memory
    curent = malloc(sizeof(struct Node));

    // assigning values
    curent->value = atoi(argv[1]) ;
    head = curent;

    curent = malloc(sizeof(struct Node));

    for (int i = 2; i < argc; ++i) {

        curent->next->value = atoi(argv[i]); 
        curent = curent->next;

    }

    return 0;
}

void printLinkedList(struct Node* node) {
    while ( node != NULL ) {
        printf("%d\n", node->value);
        node = node->next;
    }
}
