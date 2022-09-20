#include<stdio.h>
#include <string.h>

int main() {
   char string[50], word1[50], word2[50];

    scanf("%[^\n]%*c", string);

   char * token = strtok(string, " ");

   while( token != NULL ) {
      printf( "%s\n", token );
      token = strtok(NULL, " ");
   }

   printf( "W1:\n");
   scanf("%[^\n]%*c", word1);

   printf( "W2:\n");
   scanf("%[^\n]%*c", word2);

    printf("%s\t%s\n", word1, word2);

   return 0;
}