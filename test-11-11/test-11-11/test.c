#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand((unsigned int)time(NULL));
	int n = 0;
	int sum = 0;
	int j = 0;
	int arr[1000] = { 0 };
	printf("请输入总个数：\n");
	scanf("%d", &n);
	int i = 0;
	printf("请输入需要随机数的个数：\n");
	scanf("%d",&i);
	int y = 0;
	int k = 0;
	k = i;
	while (i>=0)
	{
		j = k;
		y = rand() % n;
		if (y != 0)
		{
			sum = 0;
			for (j; j >= i; j--)
			{
				if (y != arr[j])
					sum++;
			}
		}
		if (sum == k-j)
		{
			arr[i] = y;
			i--;
		}
		
	}
	int left = 0;
	int right = k;
	int mid = 0;
	for (mid = 0; mid < right; mid++) {
		for (left = 0; left < right; left++)
		{
			if (arr[left] < arr[left + 1])
			{
				int tmp = arr[left + 1];
				arr[left + 1] = arr[left];
				arr[left] = tmp;

			}
		}
	}
	for (k; k>0;k--)
	{
		printf("%d  ", arr[k]);
	}
	system("pause");
	return 0;

}
