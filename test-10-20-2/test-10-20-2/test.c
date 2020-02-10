#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int  Fibonacci(int n)
{
	int a = 0, b = 1, c = 0; //0 1 1 2  3 5 8 13 21
	while (1)
	{
		if (n == 0)
		{
			break;
		}
		c = a + b;
		a = b;
		b = c;
		if (b>= n)
		{
			break;
		}
	}
	int x1 = 0, x2 = 0, min = 0, max = 0;
	max = b;
	min = a;
	x1 = max - n;
	x2 = n - min;
	return x1 > x2 ? x2 : x1;
}
int main()
{
	int N = 0;
	scanf("%d",&N);
	int ret = Fibonacci(N);
	printf("%d ", ret);
	system("pause");
	return 0;
}
