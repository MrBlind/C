#include "MERGE_SORT.h"



int merge_sort(Array *test, int start, int end)
{
	if (start < end) {
		int middle;
		middle = (start + end) / 2;
		merge_sort(test, start, middle);
		merge_sort(test, middle + 1, end);
		merge(test, start, middle, end);
	}
	else return 0;

	return 0;

	//return false;
}

int merge(Array *test, int start, int middle, int end) {
	int temp1[100];
	int temp2[100];
	int temp = start;
	int i;
	int j;
	int x = middle - start + 1;
	int y = end - middle;

	for (i = start; i < middle + 1; i++) {
		temp1[i - start] = (*test).arr[i];
	}
	for (j = middle + 1; j <= end; j++) {
		temp2[j - middle - 1] = (*test).arr[j];
	}

	

	i = 0;
	j = 0;
	while (i < x && j < y) {
		if (temp1[i] < temp2[j])
			(*test).arr[temp++] = temp1[i++];
		else
			(*test).arr[temp++] = temp2[j++];
	}
	while (i < x)
		(*test).arr[temp++] = temp1[i++];
	while (j < y)
		(*test).arr[temp++] = temp2[j++];
	

	return 0;
}