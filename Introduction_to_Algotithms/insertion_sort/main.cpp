#include <stdio.h>
#include "INSERTION_SORT.h"

int main(int argc, char ** argv) {
	Array test = {
		6,
		{ 5,2,4,6,1,3 }
	};

	/*
	Array test = {
		.length = 6,
		.arr = { 5,2,4,6,1,3 }
	}
	���ϸ�ֵ��ʽ�ƺ���C++���޷�ʹ�ã���ʱ��֪��ԭ��
	*/

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
