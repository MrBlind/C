#include <stdio.h>
#include "MERGE_SORT.h"

int main(int argc, char ** argv) {
	Array test = {
		8,
		{ 2,4,5,7,1,2,3,6 }
	};

	/*
	Array test = {
		.length = 6,
		.arr = { 5,2,4,6,1,3 }
	}
	以上赋值方式似乎在C++中无法使用，暂时不知道原因。
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
	merge_sort(&test,0,7);

	for (int i = 0; i < test.length; i++) {
		printf("%d", test.arr[i]);
	}

	return 0;
}
