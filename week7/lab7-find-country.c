#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declarations

// func

struct countries find_country(char * arr[], int len_arr);

// struct
typedef struct countries countries;

struct countries
{
    // array based selection, in case there are multiple countries (should work fine with onw as well)
    char * the_country[100];
    char * capital[100];
    char * population[100];
    char * size[100];
    int struct_size;

};

// main
int main(int argc, char *argv[])
{

    countries countries_found;
    countries_found = find_country(argv, argc);
    
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for (int i = 0; i < countries_found.struct_size; ++i) {
        
        printf("%s\t\t\t%s\t\t\t%s\t\t\t%s\n", countries_found.the_country[i], countries_found.capital[i], countries_found.size[i], countries_found.population[i]);
        
    }
    
    return 0;
}

// the struct function finding and assigning the needed country/countries
struct countries find_country(char * arr[], int len_arr) {

    countries CountryFound;

    int counter = 0;
    for (int i = 1; i < len_arr; ++i) {

        char * this = *(arr + i);

        if (atoi(this) < 100000 && i % 4 == 0) {

            CountryFound.the_country[counter] = *(arr + i - 3);
            CountryFound.capital[counter] = *(arr + i - 2);
            CountryFound.population[counter] = *(arr + i - 1);
            CountryFound.size[counter] = *(arr + i);

            ++counter;
            
        }

    }
    
    CountryFound.struct_size = counter;
    
    return CountryFound;
}

