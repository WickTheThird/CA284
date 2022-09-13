#include <stdio.h>

int main(int argc, char*argv[]) {

  int age;
  long number;
  double weird;
  char init;

  age = 0;
  number = 12353;
  weird = 11.444;
  init = 'a';
  char first_name[] = "Filip";
  char last_name[] = "Filip2";

  printf("Blah blah %s \n", first_name);
  printf("Blah blah %s \n", last_name);
  printf("Blah blah %ld \n", number);
  printf("Blah blah %f \n", weird);
  printf("Blah blah %c \n", init);
  printf("Blah blah %%");

  return 0;
}
