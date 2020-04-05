#include"List.h"

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* phead = (ListNode *)malloc(sizeof(ListNode));
	phead->_next = phead->_prev = phead;
	return phead;
}

// 双向链表销毁
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
	phead = NULL;//这个地方其实没用，因为返回的指针指向的空间虽然被free掉了，但是它的指向并没有改变，我们置空的只是临时变量指针的指向。
}

// 双向链表打印
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

// 双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* tail = (ListNode*)malloc(sizeof(ListNode));
	tail->_data = x;
	tail->_prev = phead->_prev;
	tail->_prev->_next = tail;
	phead->_prev = tail;
	tail->_next = phead;

}
// 双向链表尾删
void ListPopBack(ListNode* phead)
{	//只有头
	assert(phead != phead->_next &&phead);
	ListNode* tail = phead->_prev;
	ListNode* prev = tail->_prev;
	free(tail);
	prev->_next = phead;
	phead->_prev = prev;
}

// 双向链表头插
void ListPushFront(ListNode* phead, LTDataType x)
{	//只有头的情况
	assert(phead);
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	ListNode* next = phead->_next;
	phead->_next = cur;
	next->_prev = cur;
	cur->_prev = phead;
	cur->_next = next;
}

// 双向链表头删
void ListPopFront(ListNode* phead)
{	//不能删除头结点
	assert(phead && phead->_next != phead);
	ListNode* next = phead->_next->_next;
	free(phead->_next);
	next->_prev = phead;
	phead->_next = next;
}

// 双向链表查找
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

// 双向链表在pos的前面进行插入
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

// 双向链表删除pos位置的节点
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