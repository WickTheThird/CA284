#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Filip Bumbu, we have a sequence of items, each have a code, number of items , 13/11/22
// The way I went about this:
//      -> I have firstly added all the info into a linked list;
//      -> The info was split into code, origin, pice and number of items sold and finally the amout of sales;
//      -> Then after everything has been assigned, i pass it to a final function that calculates the mean and prints the origin and 1 or 0 based on
//      how many sales it has comared to the mean;
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//

// declarations

typedef struct Product Product;
struct Product {

    char *code;
    char *origin;
    float price;
    int number_of_items;
    float sales;

    Product *next;

};

Product* get_product(char *arr[], int len);
char* origin_checker(char *id);
void compute_product(Product *start);

// main function
int main(int argc, char* argv[]) {
    // initiating the start
    Product *start = NULL;
    // this is the linked list
    start = get_product(argv, argc - 1);
    // computing the producs accordingly
    compute_product(start);

    return 0;
}

// functions
// checking the origin of the country
char* origin_checker(char *id) {

    if (id[0] == 'I' && id[1] == 'E') {
        return "Ireland";
    } else if(id[0] == 'F' && id[1] == 'R') {
        return "France";
    } else if (id[0] == 'S' && id[1] == 'P') {
        return "Spain";
    } else if (id[0] == 'U' && id[1] == 'S') {
        return "USA";
    } else if (id[0] == 'R' && id[1] == 'U') {
        return "Russia";
    }
    return "Unknown";
}

// assinging the values from argv to a linked list which can be better handled
Product* get_product(char * arr[], int len) {
    // initiating current and first to be the first node
    Product *current, *first;
    // equating the current with the first
    first = (Product*)malloc(sizeof(Product));
    current = first;
    // filling out the first node
    current->code = arr[1];
    current->origin = origin_checker(arr[1]);
    current->price = atof(arr[2]);
    current->number_of_items = atoi(arr[3]);
    current->sales = atof(arr[2]) * atof(arr[3]);
    // assigning the rest of the nodes based on the head
    int counter = 0;
    for(int i = 4; i <= len; ++i, ++counter) {

        if (counter % 3 == 0) {
            // alocating the next
            current->next = (Product*)malloc(sizeof(Product));
            current = current->next;
            // allocating the info to a linked list
            current->code = arr[i];
            current->origin = origin_checker(arr[i]);
            current->price = atof(arr[i + 1]);
            current->number_of_items = atoi(arr[i + 2]);
            current->sales = atof(arr[i + 1]) * atof(arr[i + 2]);
        }

    }
    return first;
}

// printing the items like expected
void compute_product(Product *start) {
    // initialising a total
    float total = 0;
    // decaring a pointer to assign the values constantly
    Product *p = NULL;
    Product *r = NULL;
    // looping through the values constantly using p
    int nr_of_prod = 0;
    for (p = start; p != NULL; p = p->next, ++nr_of_prod) {
        total += p->sales;
        //printf("%f\n", p->sales);
    }
    // getting the average
    total /= nr_of_prod;
    // printing the corresponding information
    for (r = start; r != NULL; r = r->next) {
    
       if (r->sales < total) {
           printf("0\n");
       } else if (r->sales >= total) {
            printf("1\n");
       }

       printf("%s\n", r->origin);
    }
}
