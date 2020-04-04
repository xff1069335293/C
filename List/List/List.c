#include"List.h"

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* phead = (ListNode *)malloc(sizeof(ListNode));
	phead->_next = phead->_prev = phead;
	return phead;
}

// ˫����������
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead;
	if (cur == cur->_next)
	{
		free(cur);
		cur = NULL;
		//cur->_next = cur->_prev = NULL;
		return ;
	}
	if (cur->_next == cur->_prev)
	{
		ListNode* next = cur->_next;
		free(cur);
		free(next);
	}
	while (cur->_next != phead)
	{
		ListNode* next= cur->_next;
		free(cur);
		cur = next; 
	}
	free(cur->_next);
	free(cur);
}

// ˫�������ӡ
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->_next;
	while (cur != phead)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

// ˫������β��
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* tail = (ListNode*)malloc(sizeof(ListNode));
	tail->_data = x;
	tail->_prev = phead->_prev;
	tail->_prev->_next = tail;
	phead->_prev = tail;
	tail->_next = phead;

}
// ˫������βɾ
void ListPopBack(ListNode* phead)
{
	ListNode* prev = phead->_prev;
	ListNode* next = phead->_next;
	free(phead);
	prev->_next = next;
	next->_prev = prev;
}
// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	ListNode* next = phead->_next;
	phead->_next = cur;
	next->_prev = cur;
	cur->_prev = phead;
	cur->_next = next;
}
// ˫������ͷɾ
void ListPopFront(ListNode* phead)
{
	//ֻ��ͷ
	//������
	//������
	assert(phead);
	if (phead->_prev == phead)
	{
		return;
	}
	if (phead->_next == phead->_prev)
	{
		ListNode *next = phead->_next;
		free(next);
		next = phead;
	}
	else
	{
		ListNode *next = phead->_next->_next;
		free(phead->_next);
		phead->_next = next;
		next->_prev = phead;
	}
}

// ˫���������
ListNode* ListFind(ListNode* phead, LTDataType x)
{	//ֻ��ͷ
	//������
	//������
	ListNode* cur = phead;
	if (cur->_next == cur)
	{
		return NULL;
	}
	if (cur->_prev == cur->_next)
	{
		if (cur->_next->_data == x)
		{
			return cur->_next;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		while (cur->_prev != cur->_next)
		{
			ListNode* next = cur->_next;
			if (next->_data == x)
			{
				return next;
			}
			cur = next;
		}
		return NULL;
	}
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	
	ListNode* cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;
	ListNode* prev = pos->_prev;
	prev->_next = cur;
	cur->_prev = prev;
	cur->_next = pos;
	pos->_prev = cur;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}


void test()
{
	ListNode* ls = ListCreate();
	
	ListPushBack(ls, 2);
	ListPushBack(ls, 3);
	ListPushBack(ls, 4);
	ListPushBack(ls, 5);
	ListPrint(ls);
	ListPopBack(ls);
	ListPrint(ls);
	ListPushFront(ls, 1);
	ListPushFront(ls, 0);
	ListPrint(ls);
	ListPopFront(ls);
	ListPrint(ls);
	ListNode* ret = ListFind(ls, 1);
	ListInsert(ret, 0);
	ListInsert(ret, 9);
	ListPrint(ls);
	ListErase(ret);
	ListPrint(ls);
}