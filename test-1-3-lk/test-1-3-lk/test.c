//�Ƴ�����Ԫ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (!head) {
		return NULL;
	}
	struct ListNode *head_t, *tmp;
	head_t = head;
	while (head_t) {
		if (head_t->val == val) {
			tmp = head_t;
			head_t = head_t->next;
			head = head_t;
			free(tmp);
			continue;
		}
		while (head_t->next && head_t->next->val == val) {
			tmp = head_t->next;
			head_t->next = head_t->next->next;
			free(tmp);
		}
		head_t = head_t->next;
	}
	return head;
}