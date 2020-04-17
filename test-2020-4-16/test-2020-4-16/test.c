//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
//
//
//
//示例 1：
//
//输入：head = [1, 3, 2]
//输出：[2, 3, 1]

//1.遍历两遍
//2.用栈存储
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
void Swap(int *pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void Reverse(int*arr, int begin, int end)
{
	while (begin < end)
	{
		Swap(&arr[begin++], &arr[end--]);
	}
}
int* reversePrint(struct ListNode* head, int* returnSize) {
	struct ListNode* cur = head;
	int count = 0;
	while (cur != NULL)
	{
		++count;
		cur = cur->next;
	}
	int* arr = (int*)malloc(sizeof(int)*(count));
	*returnSize = 0;
	while (head != NULL)
	{
		arr[(*returnSize)++] = head->val;
		head = head->next;
	}
	Reverse(arr, 0, *returnSize - 1);
	return arr;
}