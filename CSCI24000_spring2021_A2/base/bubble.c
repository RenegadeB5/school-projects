//bubble.c
//famous bubble sort
//implement the swap algorithm with pointers

#include <stdio.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*, int*);

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5};

int main(){
	printf("Before: \n");
	printValues();
	sort();
	printf("After: \n");
	printValues();
	return(0);
} // end main

// start Duncan's code ---------------------------------------------------------------------------------------

// yeah yeah I used a global variable here since it won't matter, but I know better than to do so otherwise
int size = sizeof(values) / sizeof(values[0]);

void printValues() {
	printf("[ ");
	int i;
	// iterate through values and print them
	for (i = 0; i < size; i++) {
		printf("%d ", values[i]);
	} // end for (i)
	printf("]\n");
} // end printValues()

void sort() {
	// jeez maybe I should use spaces in vim
	// but anyway iterate through values to determine if they need swapped
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1; j++) {
			if (values[j] > values[j+1]) {
				// saved a couple lines and just passed the addresses
				swap(&values[j], &values[j+1]);
				printValues();
			} // end if j > j+1
		} // end for (j)
	} // end for (i)
} // end sort()

void swap(int* x, int* y) {
	// swap addresses
	int temp = *x;
	*x = *y;
	*y = temp;	
} // end swap()


