#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Filip Bumbu, printing out entered information accordingly to the item name, 03/11/22
// The way I went about this:
//      -> I have firstly added all the info from the command line to a new array
// in order to keep the lengs, and have moew flexibility with the array.
//      -> I have then sent the necessary info to show_sale. Show_sale prints out the
// info that was processed and returned by which_sale.
//      -> Which_sale takes all the info from the array and assigns them to an
// array in the struct respectively.
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//

// declarations
struct Seller which_sale(char * arr[], int len);
void show_sale(char * arr[], int len);

typedef struct Seller Seller;

// structs
struct Seller
{
    char * items[100];
    int amount[100];
    float price[100];
    int promotion[100];
};

// main
int main(int argc, char* argv[]) {
    // the list with the needed items
    char * arr[argc - 1];

    int counter = 0;
    for (int i = 1; i < argc; ++i, ++counter) {

        *(arr + counter) = *(argv + i);
 
    }

    show_sale(arr, counter);

    return 0;
}

void show_sale(char * arr[], int len) {
    // initialising the struct
    Seller which_items;
    which_items = which_sale(arr, len); // assigning the info to the struct
    // printing out the info in the correct way
    for (int i = 0; i < len / 4; ++i) {

        if (which_items.promotion[i] == 1) {
            
            printf("%s,%d,%.2f,On Sale\n", which_items.items[i], which_items.amount[i], which_items.price[i]);

        } else {

            printf("%s,%d,%.2f,No Sale\n", which_items.items[i], which_items.amount[i], which_items.price[i]);

        }

    }

}
// assigning the info to the struct
struct Seller which_sale(char * arr[], int len) {

    Seller the_items;

    int counter = 0;
    int index = 0;
    for (int i = 0; i < len; ++i) {

        if (counter == 4) {

            the_items.items[index] = *(arr + i - 4);
            the_items.amount[index] = atoi(*(arr + i - 3));
            the_items.price[index] = atof(*(arr + i - 2));
            the_items.promotion[index] = atoi(*(arr + i - 1));

            ++index;
            counter = 0;

        } else if (i == len - 1) { // i had a -1 error
            the_items.items[index] = *(arr + i - 3);
            the_items.amount[index] = atoi(*(arr + i -2));
            the_items.price[index] = atof(*(arr + i - 1));
            the_items.promotion[index] = atoi(*(arr + i));

            ++index;
            counter = 0;
        }

        ++counter;
    }

    // returning the struct
    return the_items;
}
