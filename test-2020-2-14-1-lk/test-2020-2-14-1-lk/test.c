//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入: [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//	输出 : [5, 6, 7, 1, 2, 3, 4]
//	解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//	示例 2 :
//
//	输入 : [-1, -100, 3, 99] 和 k = 2
//	输出 : [3, 99, -1, -100]
//	解释 :
//	向右旋转 1 步 : [99, -1, -100, 3]
//	向右旋转 2 步 : [3, 99, -1, -100]
//暴力求解
// void move(int* nums,int numsSize)
// {   int count = numsSize-1;
//     int tmp = nums[count];
//     while (count)
//     {
//         nums[count] = nums[count-1];
//         count--;
//     }
//     nums[count]=tmp;
// }
// void rotate(int* nums, int numsSize, int k)
// {   
//     k=k%numsSzie;
//     for (int i=0; i<k;i++)
//    { 
//        move(nums,numsSize);
//    }
// }
//
//旋转法
// void reverse(int* nums,int start,int end)
// {
//     while (start <end)
//     {
//         int tmp = *(nums+end);
//         *(nums+end) = *(nums+start);
//         *(nums+start) = tmp;
//         ++start;
//         --end;
//     }
// }
// void rotate(int* nums, int numsSize, int k)
// {   k = k%numsSize;
//     reverse(nums,0,numsSize-1);
//     reverse(nums,0,k-1);
//     reverse(nums,k,numsSize-1);
// }

