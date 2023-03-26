#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// main
int main(int argc, char *argv[])
{

    int cap = 20;
    char ** name = (char**)malloc(cap*sizeof(char*));
    char ** programme = (char**)malloc(cap*sizeof(char*));
    char ** grade = (char**)malloc(((argc - 1) / 3)*sizeof(char*));
  

    char ** pTemp1 = NULL;
    char ** pTemp2 = NULL;

    if (!name || !programme || !grade) {

        printf("Failed to allocate memory\n");
        return 0;

    }

    int count = 0;
    for (int i = 1; i < argc; ++i) {

       if (i % 6 == 0) {

           cap += 20;
           pTemp1 = realloc(name, cap*sizeof(char*));
           pTemp2 = realloc(programme, cap*sizeof(char*));

           if (!pTemp1 || !pTemp2) {

               printf("Failed to allocate memory\n");
               return 0;

           }

          name = pTemp1;
          programme = pTemp2;

       }

       if (i % 3 == 0) {

           *(name + count) = *(argv + i - 2);
           *(programme + count) = *(argv + i - 1);
           *(grade + count) = *(argv + i);

           ++count;

       }

    }
    for (int i = 0; i < count; ++i) {

        if (*(name + i) != NULL) {
            printf("%s, ", *(name + i));
            printf("%s, ", *(programme + i));
            printf("%.2f\n", atof(grade[i]));
        }
    }

    return 0;
}
