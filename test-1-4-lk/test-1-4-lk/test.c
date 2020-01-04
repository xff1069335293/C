// ��������в�������
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	struct ListNode* rear, *p, *temp, *q = head;      //rearָ��β��㣬qָ�����ڶ������
	rear = head->next;
	while (rear)
	{
		//�ҵ���������Ľ��
		while (rear&&rear->val >= q->val)
		{
			q = rear;
			rear = rear->next;
		}
		if (rear == NULL)   break;
		temp = rear;
		rear = rear->next;
		q->next = rear;
		//�ýڵ�С��ͷ���
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