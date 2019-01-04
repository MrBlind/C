#include "INSERTION_SORT.h"



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
