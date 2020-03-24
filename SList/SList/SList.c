#include"SList.h"


// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* psl = (SListNode*)malloc(sizeof(SListNode));
	psl->data = x;
	psl->next = NULL;
	return psl;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{	
	//1.空链表
	//2.非空链表
	SListNode* psl = (SListNode*)malloc(sizeof(SListNode));
	psl->data = x;
	psl->next = NULL;
	if (*pplist == NULL)
	{
		*pplist = psl;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = psl;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	//先存头指针，再更新头部。
	SListNode* psl = (SListNode*)malloc(sizeof(SListNode));
	psl->data = x;
	psl->next = NULL;
	psl->next = *pplist;
	*pplist = psl;
	
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{	//1.空链表
	//2.单个链表
	//3.多个链表
	if (*pplist == NULL)
	{
		return;
	}
	if ((*pplist)->next == NULL)
	{
		free(*pplist);//一定要先释放再置NULL，防止野指针问题。
		*pplist = NULL;
	}

	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	//1.空链表
	//2.多个链表
	if (*pplist == NULL)
	{
		return;
	}
	SListNode* cur = (*pplist)->next;
	free(*pplist); //这里也要注意释放空间
	*pplist = cur;

}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
		while (plist !=NULL)
		{
			if (plist->data == x)
			{
				return plist;
			}
			plist = plist->next;
		}
		return plist;
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->data = x;
	cur->next = NULL;
	cur->next = pos->next;//一定要先把后面的指针存起来，再改变指向。
	pos->next = cur;
}
// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL || pos->next == NULL)
	{
		return;
	}
	
	SListNode* next = pos->next->next;
	free(pos->next);
	pos->next = next;
}


//单链表的销毁
void  SListDestory(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return ;
	}
	while ((*pplist)->next != NULL)
	{
		SListNode* cur = (*pplist)->next;
		free(*pplist);
		*pplist = cur;
	}
	free(*pplist);
	*pplist = NULL;//释放完成要置空，不然会存在野指针的
}

void test()
{

	SListNode* psl = NULL;/* BuySListNode(1);*/
	SListPushBack(&psl, 4);
	SListPushBack(&psl, 5);
	SListPushBack(&psl, 6);
	SListPushBack(&psl, 7);
	SListPrint(psl);
	SListPushFront(&psl, 3);
	SListPushFront(&psl, 2);
	SListPushFront(&psl, 1);
	SListPrint(psl);
	SListPopBack(&psl);
	SListPrint(psl);
	SListPopFront(&psl);
	SListPrint(psl);
	SListNode* ret=SListFind(psl, 2);
	SListInsertAfter(ret, 0);
	SListPrint(psl);
	SListEraseAfter(ret);
	SListPrint(psl);
	SListDestory(&psl);
	SListPrint(psl);
	return;
}