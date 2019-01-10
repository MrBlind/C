/*
strassen算法是将矩阵用分治法计算的同时用特定的方法减少计算分支
满足：
假设有矩阵A,B,C满足C=A*B
普通的分治算法是将A分为
[A11 A12]
[A21 A22]
B
[B11 B12]
[B21 B22]
通过C11=A11*B11 + A12*B21
	C12=A11*B12 + A12*B22
	C21=A21*B11 + A22*B21
	C22=A21*B12 + A22*B22
然后再将矩阵计算分治计算得知。
strassen算法按照如下步骤计算
第一步：将A，B分别分成四个2/n*2/n
第二步：用S1-S10保存矩阵加减法结果：
	S1 = B12 - B22
	S2 = A11 + A12
	S3 = A21 + A22
	S4 = B21 - B11
	S5 = A11 + A22
	S6 = B11 + B22
	S7 = A12 - A22
	S8 = B21 + B22
	S9 = A11 - A21
	S10 = B11 + B12
第三步：
	P1 = A11 * S1
	P2 = S2 * B22
	P3 = S3 * B11
	P4 = A22 * S4
	P5 = S5 * S6
	P6 = S7 * S8
	S7 = S9 * S10
第四步：
	C11 = P5 + P4 - P2 + P6
	C12 = P1 + P2
	C21 = P3 + P4
	C22 = C22 = P5 + P1 - P3 + P7	
*/


#include "strassen.h"

Mat mat_add(Mat A, Mat B, int left, int right, int top, int bottom)			//A+B
{
	int i;
	int j;
	Mat C;
	C.length = right - left + 1;
	C.height = bottom - top + 1;
	for (i = top; i <= bottom; i++) {
		for (j = left; j <= right; j++) {
			C.arr[i - top][j - left] = A.arr[i][j] + B.arr[i][j];
		}
	}
	return C;
}

Mat mat_subtract(Mat A, Mat B, int left, int right, int top, int bottom)			//A-B
{
	int i;
	int j;
	Mat C
	for (i = top; i <= bottom; i++) {
		for (j = left; j <= right; j++) {
			C.arr[i][j] = A.arr[i][j] - B.arr[i][j];
		}
	}
	return *C;
}



int Strassen(Mat *C, Mat A, Mat B, int left, int right, int top, int bottom)
{
	Mat S1, S2, S3, S4, S5, S6, S7, S8, S9, S10;
	Mat P1, P2, P3, P4, P5, P6, P7;
	int midrow;
	int midcol;
	midrow = (left + right) / 2;
	midcol = (top + bottom) / 2;
	S1 = mat_add(B, B, left, midrow, top, midcol);
	S2 = mat_add(A,B,)
}