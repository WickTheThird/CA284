#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Filip Bumbu, calculating the sum of the numbers situated on the anti-diagonal of a matrix, 03/11/22
// The way I went about this:
//    -> In the main function I have first assigned the converted items
// to a 3d array.
//    ->  Then in the sumDiag function, in order to calculate the anti-diaginals
// we need to take the dimension of the array - 1 - the_index_of_the_element.
//    -> After theat im just printing the result.
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//

// declarations
int sumDiag(int (*pArr)[100], int n);

// main function
int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);

	int a[100][100];
	int (*pArr)[100] = a;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			*(*(pArr + i) + j) = atoi(argv[i * n + j + 2]);

	printf("%d\n", sumDiag(pArr, n));
	return 0;
}

// finding the sum
int sumDiag(int (*pArr)[100], int n){
	int sum = 0;
	int* pSum = &sum;

	for (int i = 0; i < n; i++) {
		*pSum += *(*(pArr + i) + n - 1 - i);
    }

	return *pSum;
}