#include <stdio.h>
#include "maxcrossingsubarray.h"

int main(int argc, char ** argv) {
	Array test = {
		16,
		{ 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}
	};

	int max_left;
	int max_right;
	int max_sum;
	max_sum = find_maxxmumsubarray(&test, 0, 15, &max_left, &max_right);

	//for (int i = 0; i < test.length; i++) {
	//	printf("%d", test.arr[i]);
	//}
	printf("���ֵ��%d", max_sum);
	printf("��������鿪ʼ�±꣺%d", max_left + 1);
	printf("�������������±꣺%d", max_right + 1);

	return 0;
}
