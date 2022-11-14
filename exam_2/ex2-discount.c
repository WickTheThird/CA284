#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Filip Bumbu, calculating the total price of items given a discount, 03/11/22
// The way I went about this:
//      -> The basic structure is the same as ex2-show-cart.c except that 
// instead of show_sale printing out the struct members accordingly, it
// calculates the sum of the items baught given that a discount is included
// (if the item is active and you bought three, you need to pay only for two).
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//


struct Seller which_sale(char * arr[], int len);
void show_sale(char * arr[], int len);

typedef struct Seller Seller;

struct Seller
{
    char * items[100];
    int amount[100];
    float price[100];
    int promotion[100];
};

int main(int argc, char* argv[]) {

    char * arr[argc - 1];

    int counter = 0;
    for (int i = 1; i < argc; ++i, ++counter) {

        *(arr + counter) = *(argv + i);
 
    }

    show_sale(arr, counter);

    return 0;
}

void show_sale(char * arr[], int len) {

    Seller which_items;
    which_items = which_sale(arr, len);

    float total = 0;

    for (int i = 0; i < len / 4; ++i) {

       if (which_items.promotion[i] == 0) {

           total += (which_items.price[i] * which_items.amount[i]);

       } else if (which_items.promotion[i] == 1) {

         int tmp_price = (which_items.price[i] * which_items.amount[i]); 
         int tmp_amount = which_items.amount[i] / 3;
         int tmp_price_2 = which_items.price[i] * tmp_amount;

         total += (tmp_price - tmp_price_2);

       }

    }

    printf("%.2f\n", total);

}

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

        } else if (i == len - 1) {
            the_items.items[index] = *(arr + i - 3);
            the_items.amount[index] = atoi(*(arr + i -2));
            the_items.price[index] = atof(*(arr + i - 1));
            the_items.promotion[index] = atoi(*(arr + i));

            ++index;
            counter = 0;
        }

        ++counter;
    }

    return the_items;
}
