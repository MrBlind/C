#include <stdio.h>
#include "../include/INSERTION_SORT.h"


int main(int argc, char ** argv) {
	Array test = { 
		.length = 6,
		.arr = {5,2,4,6,1,3},
	};

	/*
	Array test = {
		length : 1,
		arr : {1},
	}

	Array test = { 1, {1}};
	*/

	//test.length = 1;
	//test.arr[0] = 1;
	
	/*
	for (int i = 0; i < test.length; i++) {
		printf("%d\n", test.arr[i]);
	}
	*/
	insertion_sort(&test);

	for (int i = 0; i < test.length; i++) {
		printf("%d", test.arr[i]);
	}

	return 0;
}

int insertion_sort(Array *test)
{
	int key = 0;
	for (int i = 1; i < (*test).length; i++) {
		key = (*test).arr[i];
		for (int j = 0; j < i; j++) {
			if (key <= (*test).arr[j]) {
				key = (*test).arr[j];
				(*test).arr[j] = (*test).arr[i];
				(*test).arr[i] = key;
			}
		}
	}
	return 0;

	//return false;
}
