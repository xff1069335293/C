﻿/**删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode*p = head;
	struct ListNode* a[100];
	int i = 0;
	while (p != NULL)
	{
		a[i] = p;
		++i;
		p = p->next;
	}
	i = i - n;
	if (i == 0)
	{
		return head->next;
	}
	else
	{
		a[i - 1]->next = a[i]->next;
		return head;
	}
}