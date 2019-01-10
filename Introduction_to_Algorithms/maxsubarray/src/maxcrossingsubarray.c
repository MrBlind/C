#include "maxcrossingsubarray.h"


int find_maxcrossingsubarray(Array *test, int low, int mid, int high, int *max_left, int *max_right)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum = 0;
	int i = 0;
	for (i = mid; i >= low; i--) {		//���Ҵ��е���������������
		sum += (*test).arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			*max_left = i;
		}
	}
	sum = 0;
	for (i = mid + 1; i <= high; i++) {	//���Ҵ��е����ҵ����������
		sum += (*test).arr[i];
		if (sum > right_sum) {
			right_sum = sum;
			*max_right = i;
		}
	}
	return left_sum + right_sum;
}


int find_maxxmumsubarray(Array *test, int low, int high, int * max_left, int *max_right)
{
	int mid;
	int left_max_right;
	int left_max_left;
	int right_max_right;
	int right_max_left;

	int left_sum;
	int right_sum;
	int cross_sum;

	if(high == low)
		return (low, high, (*test).arr[low]);
	else mid = (high + low) / 2;
	left_sum = find_maxxmumsubarray(*&test, low, mid,
		&left_max_left, &left_max_right);					//����������������
	right_sum = find_maxxmumsubarray(*&test, mid + 1,
		high, &right_max_left, &right_max_right);			//�����Ҳ����������
	cross_sum = find_maxcrossingsubarray(*&test, low, mid,
		high, *&max_left, *&max_right);						//���Ҿ����е�����������
	
	if (left_sum >= right_sum && left_sum >= cross_sum) {
		*max_left = left_max_left;
		*max_right = left_max_right;
		return left_sum;
	}
	else if (right_sum >= left_sum &&right_sum >= cross_sum) {
		*max_left = right_max_left;
		*max_right = right_max_right;
		return right_sum;
	}
	else
		return cross_sum;

}
