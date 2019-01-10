#ifndef __merge_sort_h
#define __merge_sort_h

#include <stdio.h>

#ifdef __cplusplus
	extern "C" {
#endif

	typedef struct _Array {
		int length;
		int arr[100];
	}Array;


	int merge_sort(Array *test, int start, int end);
	int merge(Array *test, int start, int end, int middle);

#ifdef __cplusplus
	}
#endif

#endif

