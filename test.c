#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

  int max_num = atoi(argv[1]), i = 0;

  while (i <= max_num) {

    if (i % 2 == 0) {

      printf("%d is even\n", i);

    } else {

      printf("%d is odd\n", i);

    }

    i++;

  }

  return 0;
}
