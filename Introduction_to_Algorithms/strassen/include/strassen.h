#ifndef __strassen_h
#define __strassen_h

#include <stdio.h>
#include <limits.h>

#ifdef __cplusplus
	extern "C" {
#endif

	typedef struct _Mat {
		int left_top;
		int left_bottom;
		int right_top;
		int right_bottom;
		int length;
		int height;
		int arr[100][100];
	}Mat;

	Mat mat_add(Mat A, Mat B, int left, int right, int top, int bottom, Mat *C);
	Matmat_subtract(Mat A, Mat B, int left, int right, int top, int bottom, Mat *C);
	Mat mat_multip(Mat A, Mat B, int left, int right, int top, int bottom);
	int Strassen(Mat C, Mat A, Mat B, int left, int right, int top, int bottom);
	//int mat_add(Mat A, Mat B, int left_top, int left_bottom, int right_top, int right_bottom)


#ifdef __cplusplus
	}
#endif

#endif

