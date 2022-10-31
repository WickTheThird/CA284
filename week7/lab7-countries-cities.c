#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// declarations

// organising info with structs
typedef struct Country Country;
typedef struct City City;

struct Country {
    char * name[100];
    char * city[100];
};

struct City {
    char * name[100];
    float size[100];
};

// finding the biggest city

// assigning info to struct
void countries(char * arr[], int len_arr) {
    
    // declaring instances of structs
    Country country;
    City city;
    
    // assigning the countries
    int counter = 0; // so that it would assign the correct index to the country.name
    int ct_counter = 0; // so that it would assign the correct index to country.city, city.name and city.size
    
    for (int i = 0; i < len_arr; ++i) {
        
        if (i == 0 || i % 7 == 0) {
            
            country.name[counter] = arr[i];
            ++counter;
            
        }
        
        // assigning the cities
        if ( (counter == 0 || counter % 2 == 0)) {
            
            if (i % 2 == 1) {
                
                country.city[ct_counter] = arr[i + 1];
                city.name[ct_counter] = arr[i + 1];
                
            } else { // assigning the size
                
                city.size[ct_counter] = atof(arr[i + 1]);
                
                ++ct_counter;
            }

        } else if (counter % 2 == 1) {
            
            if (i % 2 == 0) { // assigning the cities
                
                country.city[ct_counter] = arr[i + 1];
                city.name[ct_counter] = arr[i + 1];
                
            } else { // assigning the size
                
                city.size[ct_counter] = atof(arr[i + 1]);
                
                ++ct_counter;
            }
        }
    }
    
    // finding the biggest city for the countries...
    // printing the country with its biggest city...
    
    counter = 0;
    ct_counter = 0;
    
    int ind = 0;
    
    for (int i = 0; i < len_arr / 7; ++i) {
        
        ct_counter = counter * 3;
        int biggest = city.size[ct_counter];
        
        for (int j = 0; j < 3; ++j) {
            
            if (city.size[ct_counter] > biggest) {
                
                biggest = city.size[ct_counter];
                ind = ct_counter;
                
            }
            
            ++ct_counter;
        }
        
        printf("%s: %s\n", country.name[i], country.city[ind]);
        
        ++counter;
    }
}

// main
int main(int argc, char *argv[])
{
    
    // grabbing the right info
    // and passing it to the right function
    char * info[argc - 1];
    for (int i = 1; i < argc; ++i) {
        info[i - 1] = argv[i];
    }
    
    countries(info, argc - 1);
    
    return 0;
}
