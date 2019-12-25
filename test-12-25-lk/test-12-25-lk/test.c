//相交链表
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *a = headA;
	struct ListNode *b = headB;
	struct ListNode *tmp = NULL;
	int len_a = 0;
	int len_b = 0;
	//计算链表a的长度
	while (a) {
		if (a->next) {
			a = a->next;
		}
		else {
			break;
		}
		len_a++;
	}
	//计算链表b的长度
	while (b) {
		if (b->next) {
			b = b->next;
		}
		else {
			break;
		}
		len_b++;
	}
	//调整两个链表长度
	a = headA;
	b = headB;
	if (len_a > len_b) {
		int times = len_a - len_b;
		while (times--) {
			a = a->next;
		}
	}
	else {
		int times = len_b - len_a;
		while (times--) {
			b = b->next;
		}

	}

	//遍历找出入口
	while (a && b) {
		if (a == b) {
			tmp = a;
			break;
		}
		a = a->next;
		b = b->next;
	}
	return tmp;
}