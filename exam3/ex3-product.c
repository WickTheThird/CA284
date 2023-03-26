//
// Filip Bumbu, creating a linked list with necessay info and adding a 20% increase for ireland prices, 30/11/22
// The way I went about this:
//     -> I have initiated a struct with the necesarry info (code, origin and price) including a reference to the next value;
//     -> Then I have taken the argv and have created a linked list based on the info from the struct;
//     -> Then I passed the start to a printing function to print the linked list with the updated information;
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
typedef struct Product Product;
struct Product {

    char *code;
    char *origin;
    int price;

    Product *next;

};

// declarations
Product* get_product(char *arr[], int len);
void printProduct(Product *start);

// main
int main(int argc, char *argv[])
{
    // initiating the start
    Product *start = NULL;
    // this is the product
    Product *product = NULL;
    // this is the linked list
    start = get_product(argv, argc - 1);
    // this is the printing function
    printProduct(start);

    return 0;
}

// linked list
Product* get_product(char * arr[], int len)
{
    // initiating current and first to be the first node
    Product *current, *first;

    first = (Product*)malloc(sizeof(Product));
    current = first;

    // filling out the first node
    current->code = arr[1];
    current->origin = arr[2];

    if (strcmp(arr[2], "Ireland") == 0) {
        current->price = atoi(arr[3]) * 1.2;
    } else {
        current->price = atoi(arr[3]);
    }

    // assigning the rest based on the first node
    for (int i = 4; i <= len; ++i) {

        if (i % 3 == 0) {

            current->next = (Product*)malloc(sizeof(Product));
            current = current->next;

            current->code = arr[i - 2];
            current->origin = arr[i - 1];
            // checking if change is to be applied to prices
            if (strcmp(arr[i - 1], "Ireland") == 0) {
                current->price = atoi(arr[i]) * 1.2; 
            } else {
                current->price = atoi(arr[i]);
            }

        }

    }
    // ending the linked list
    current->next = NULL;
    // returning the head
    return first;
}

// printing the linked list
void printProduct(Product *start) {
    int count = 0;
    Product *p = NULL;
    for (p = start; p != NULL; p = p -> next) {
        ++count;
        printf("%s\n", p->code);
        printf("%s\n", p->origin);
        printf("%d\n", p->price);
    }
}
