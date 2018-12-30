#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>

int main()
{
	double n;

	scanf("%lf", &n);
	double a1, a2;

	a1 = 1.0;
	a2 = (a1 + n / a1) / 2.0;
	while (a1 != a2)
	{
		a1 = a2;
		a2 = (a1 + n / a1) / 2;
	}

	printf("%lf", a2);

	return 0;
}


