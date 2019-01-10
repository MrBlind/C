#ifndef __maxcrossingsubarray_h
#define __maxcrossingsubarray_h

#include <stdio.h>
#include <limits.h>

#ifdef __cplusplus
	extern "C" {
#endif

	typedef struct _Array {
		int length;
		int arr[100];
	}Array;

	int find_maxcrossingsubarray(Array *test, int low,
		int mid, int high, int *max_right, int *max_left);			//���Ҿ����е�����������
	int find_maxxmumsubarray(Array *test, int low,
		int high, int * max_left, int *max_right);					//�����������������������


#ifdef __cplusplus
	}
#endif

#endif

