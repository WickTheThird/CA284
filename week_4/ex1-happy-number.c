#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void happy_detector(char line [], int len_line, int checker) {

    int total = 0;
    int ch_conv;

    int i;
    for (i = 0; i < len_line; ++i) {
	
	ch_conv = line[i] - '0';

	total += (ch_conv * ch_conv);

	}

    if (total == 1) {
	
	printf("is happy\n");
	return;
	} else if (checker == 1000) {

	printf("not happy\n");
	return;
	}

    char total_str[i];
    sprintf(total_str, "%d", total);

    ++checker;

    happy_detector(total_str, i, checker);

}


int main(int argc, char *argv[])
{

    char * line = argv[1];
    int checker = 0;

    happy_detector(line, strlen(line), checker);

    return 0;
}
