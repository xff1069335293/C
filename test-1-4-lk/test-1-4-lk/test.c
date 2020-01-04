// 对链表进行插入排序
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	struct ListNode* rear, *p, *temp, *q = head;      //rear指向尾结点，q指向倒数第二个结点
	rear = head->next;
	while (rear)
	{
		//找到不是升序的结点
		while (rear&&rear->val >= q->val)
		{
			q = rear;
			rear = rear->next;
		}
		if (rear == NULL)   break;
		temp = rear;
		rear = rear->next;
		q->next = rear;
		//该节点小于头结点
		if (temp->val < head->val)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			p = head;
			while (temp->val > p->next->val)
				p = p->next;
			temp->next = p->next;
			p->next = temp;
		}
	}
	return head;
}