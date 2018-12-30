#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

  /* 
  ** Extract the specified substring from the string in src. 
  */ 
void copy_n(char dst[], char src[], int n)
{
	int src_n;
	int dst_n;
	src_n = 0;
	for (dst_n = 0; dst_n < n; dst_n++)
	{
		dst[dst_n] = src[src_n];
		if (src[src_n] != 0)
		{
			src_n++;
		}
	}
	dst[dst_n] = '\0';
}


int main()
{
	char dst[20];
	char src[20];
	int n;
	scanf("%d", &n);
	scanf("%s", src);
	copy_n(dst, src, n);
	printf("%s", dst);
	return 0;
}


