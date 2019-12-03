// ÒÆ³ýÔªËØ
#define _CRT_SECURE_NO_WARNINGS 1
int removeElement(int* nums, int numsSize, int val) {
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			++dst;
			++src;
		}
		else
		{
			++src;
		}
	}
	return dst;
}
#include<stdio.h>
int main()
{	
	int arr[] = { 3,2,2,3,5,6 };
	int val = 2;
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = removeElement(arr,size,val);
	printf("%d", ret);
	system("pause");
	return 0;
}

