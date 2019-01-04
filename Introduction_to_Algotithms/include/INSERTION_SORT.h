#ifndef __insertion_sort_h
#define __insertion_sort_h

#include <stdio.h>

typedef struct _Array {
	int length;
	int arr[100];
}Array;


int insertion_sort(Array * test);

#endif

