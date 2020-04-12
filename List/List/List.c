#include"List.h"

// ��������������ͷ���.
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
	ListNode* cur = phead->_next;
	while (cur != phead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;//����ط���ʵû�ã���Ϊ���ص�ָ��ָ��Ŀռ���Ȼ��free���ˣ���������ָ��û�иı䣬�����ÿյ�ֻ����ʱ����ָ���ָ��
}

// ˫��������ӡ
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
{	//ֻ��ͷ
	assert(phead != phead->_next &&phead);
	ListNode* tail = phead->_prev;
	ListNode* prev = tail->_prev;
	free(tail);
	prev->_next = phead;
	phead->_prev = prev;
}

// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{	//ֻ��ͷ�����
	assert(phead);
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
{	//����ɾ��ͷ���
	assert(phead && phead->_next != phead);
	ListNode* next = phead->_next->_next;
	free(phead->_next);
	next->_prev = phead;
	phead->_next = next;
}

// ˫����������
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->_next;
	while (cur != phead)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
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
	ListDestory(ls);
}