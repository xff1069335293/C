//2.旋转法求解	旋转数组
#define _CRT_SECURE_NO_WARNINGS 1

 void reverse(int* nums,int start,int end){
     while(start<=end){
         int tmp =nums[end];
         nums[end] = nums[start];
         nums[start]=tmp;
         ++start;
         --end;
     }

 }
void rotate(int* nums, int numsSize, int k){
     if(k>numsSize){
             k%=numsSize;
         }
 reverse(nums,0,numsSize-1);
 reverse(nums,0,k-1);
 reverse(nums,k,numsSize-1);

 }
#include<stdio.h>
 int main() {
	 int arr1[] = { 1,2,3,4,5,6,7 };
	 int k = 3;
	 scanf("%d", &k);
	 int i = 0;
	 int numsSize = sizeof(arr1) / sizeof(arr1[0]);
	 rotate(arr1, numsSize, k);
	 for (i = 0; i <numsSize; ++i) {
		 printf("%d ", arr1[i]);
	 }
	 system("pause");
	 return 0;
 }