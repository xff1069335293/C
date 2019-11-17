//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 给20元，可以多少汽水

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	int money = 20;
	int total = money;
	int empty = money;
	while (empty >= 2)  //设置循环条件，只要大于2瓶 就能继续换
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", total);
	system("pause");
	return 0;
}
