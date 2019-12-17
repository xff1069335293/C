// ����һ������������һ�������ͷ��㣬��ת�����������ת�������ͷ���
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *pNext;
}node;


struct node *gen()
{
	node *pHead = NULL;
	for (int i = 10; i > 0; i--) {
		node * p = (node *)malloc(sizeof(node));
		p->val = i;
		p->pNext = pHead;
		pHead = p;
	}
	return pHead;
}

void display(node *pHead)
{
	while (pHead != NULL)
	{
		printf("%d ", pHead->val);
		pHead = pHead->pNext;
	}
	printf("\n");
}



//β�ݹ�ʵ��
node * do_reverse_tail(node *pHead, node *pNewHead)
{
	if (pHead == NULL)
	{
		return pNewHead;
	}
	else
	{
		node *pNext = pHead->pNext;
		pHead->pNext = pNewHead;
		return do_reverse_tail(pNext, pHead);
	}
}

node * reverse_tail(node *pHead)
{
	return do_reverse_tail(pHead, NULL);
}



int main()
{
	node *pHead = gen();
	display(pHead);
	pHead = reverse_tail(pHead);
	display(pHead);
	system("pause");
}
