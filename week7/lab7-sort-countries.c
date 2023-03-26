#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// declarations

// struct organising the data given an instance

typedef struct Countries Countries;

struct Countries {

    char * name[100];
    char * capital[100];
    int size[100];
    float population[100];

};

// finding the order in which the countries should be printed
void find_order(Countries * c, int len_arr) {
    
    // assigning
    float arr[len_arr];
    
    for (int i = 0; i < len_arr; ++i) {
        
        arr[i] = c->population[i];
        
    }
    
    // sorting
    
    int i, j, min_idx;
    
    for (i = 0; i < len_arr - 1; ++ i) {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < len_arr; j++) {
              if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        if(min_idx != i) {
            
            float temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            
        }
    }
    
    // printing out info (don't want to send back anything)
    
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    
    for (int i = len_arr ; i >= 0; --i) {
        
        float n = arr[i];
        
        for (int j = 0; j < len_arr; ++j) {
            
            float m = c->population[j];
            
            if (m == n) {
                
                printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", c->name[j], c->capital[j], c->size[j], c->population[j]);
                
                break;
            }
        }
    }
}

// assigning the countries to a struct and then printing
// the countries (in the correct order)

void unordered_countries(char * arr[], int len_arr) {

    // declaring stuff
    
    Countries country;
    Countries *pCountry;

    float * unordered_arr;
    float * ordered_arr;

    // assigning values to struct

    int count = 0;
    for (int i = 0; i < len_arr; ++i) {

        if ((i + 1) % 4 == 0) {
            
            country.name[count] = *(arr + i - 3);
            country.capital[count] = *(arr + i - 2);

            int sz = atoi(*(arr + i));
            float pop = atof(*(arr + i - 1));
            
            country.size[count] = sz;
            country.population[count] = pop;

            ++count;
        }
    }

    pCountry = &country;

    // ordering the the countries based on population
    // and then printing it...

    find_order(pCountry, len_arr / 4);

}

// main

int main(int argc, char *argv[])
{

    // sending the necessary info to ordered_countries()

    char * info[argc - 1];
    for (int i = 1; i < argc; ++i) {
        info[i - 1] = argv[i];
    }

    unordered_countries(info, argc - 1);

    return 0;
}
