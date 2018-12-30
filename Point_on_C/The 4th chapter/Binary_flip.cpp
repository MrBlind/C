#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>

unsigned int reverse_bit(unsigned int value)
{
	unsigned int n = 0;
	unsigned int tmp = 1;
	tmp = ~tmp;
	tmp >>= 1;
	tmp = ~tmp;
	for (int i = 0; i < 32; i++)
	{
		if (value & 1)
		{
			n += tmp;
		}
		value >>= 1;
		tmp >>= 1;
	}
	return n;
}


int main()
{
	unsigned int n = 1;
	int x = 0xefffffff;
	x = ~x;
	//printf("%d",~x);
	scanf("%d", &n);
	printf("%d", x + reverse_bit(n));
	return 0;
}



