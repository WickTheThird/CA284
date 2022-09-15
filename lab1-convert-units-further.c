#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

    int lower_cm = 30;
    int upper_cm = 50;

    float inch = 2.54;

    while (lower_cm < upper_cm) {
      
      char line[100] = "";

      int i = 0;
      while (i < 5) {
        float final = lower_cm / inch;

        printf("%.2f ", final);

        lower_cm++;
        i++;
      }
      printf("\n");
    }


  /*
  
  With the int change, C just ignores everything that is a float, and it just takes the whole part.

  */

  return 0;
}
