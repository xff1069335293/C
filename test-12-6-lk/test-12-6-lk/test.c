//合并两个有序数组  
#define _CRT_SECURE_NO_WARNINGS 1

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int src1 = m - 1;
	int src2 = n - 1;
	int dst = m + n - 1;
	if (m || n)
	{
		while (src1 >= 0 && src2 >= 0) {
			if (nums1[src1] <=nums2[src2]) {
				nums1[dst] = nums2[src2];
				--dst;
				--src2;
			}
			 /*else if(nums1[src1]==nums2[src2])			//这里一定要注意不要写成赋值了，之前写的时候犯错误了
			 {
			      nums1[dst]=nums2[src2];
			     --dst;
			     --src2;
			 }*/
			else /*if (nums1[src1] > nums2[src2])*/
			{
				nums1[dst] = nums1[src1];
				--dst;
				--src1;
			}
		}
		if (src2 < 0) {
			while (src1 >= 0) {
				nums1[dst] = nums1[src1];
				--src1;
				--dst;
			}
		}
		if (src1 < 0) {		//这里考虑nums1没有有效值的情况
			while (src2 >= 0) {
				nums1[dst] = nums2[src2];
				--src2;
				--dst;
			}
		}
	}
	else
		return;
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int nums2[] = { 2, 5, 6 };
	int i=0,m = 3, n = 3, size1 = 6, size2 = 3;
	merge(nums1, 6, m, nums2, 3, n);
	for (i = 0; i < m + n; ++i) {
		printf("%d ",nums1[i]);
	}
	system("pause");
	return 0;
}
