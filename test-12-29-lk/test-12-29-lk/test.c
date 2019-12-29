//复制带随机指针的链表
/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	if (!head) {
		return head;
	}
	struct RandomListNode *cur = head;
	while (cur) {
		struct RandomListNode *newnode = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
		newnode->label = cur->label;
		newnode->next = cur->next;
		cur->next = newnode;
		cur = newnode->next;
	}
	cur = head;
	while (cur&&cur->next) {
		if (cur->random) {
			cur->next->random = cur->random->next;
		}
		else {
			cur->next->random = (struct RandomListNode *)0;
		}
		cur = cur->next->next;
	}
	struct RandomListNode node;
	struct RandomListNode *newtail = &node;
	cur = head;
	while (cur&&cur->next) {
		newtail->next = cur->next;
		newtail = cur->next;
		cur->next = cur->next->next;
		cur = cur->next;
	}
	newtail->next = (struct RandomListNode *)0;
	return node.next;
}