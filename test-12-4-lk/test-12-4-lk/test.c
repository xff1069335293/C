//删除排序数组中的重复项
#define _CRT_SECURE_NO_WARNINGS 1
int removeDuplicates(int* nums, int numsSize) {

	int src = 0;
	int dst = 0;
	if (numsSize < 1)
		return 0;


	while (src < numsSize)
	{
		if (nums[src] == nums[dst]) {
			++src;
		}
		else {
			++dst;
			nums[dst] = nums[src];
		}
	}
	return ++dst;
}

#include<stdio.h>
int main()
{
	int arr1[]= { 1,2,3,0,0,0 };
	//int arr2[] = { 2,5,6 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	//int size2 = sizeof(arr2) / sizeof(arr2[0]);
	//merge(arr1, size1,3, arr2, size2, 3);
	int ret = removeDuplicates(arr1,3);
	printf("%d",ret);

	system("pause");
	return 0;
}
