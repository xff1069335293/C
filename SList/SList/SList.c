#include"SList.h"


// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* psl = (SListNode*)malloc(sizeof(SListNode));
	psl->data = x;
	psl->next = NULL;
	return psl;
}

// �������ӡ
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

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{	
	//1.������
	//2.�ǿ�����
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
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	//�ȴ�ͷָ�룬�ٸ���ͷ����
	SListNode* psl = (SListNode*)malloc(sizeof(SListNode));
	psl->data = x;
	psl->next = NULL;
	psl->next = *pplist;
	*pplist = psl;
	
}
// �������βɾ
void SListPopBack(SListNode** pplist)
{	//1.������
	//2.��������
	//3.�������
	if (*pplist == NULL)
	{
		return;
	}
	if ((*pplist)->next == NULL)
	{
		free(*pplist);//һ��Ҫ���ͷ�����NULL����ֹҰָ�����⡣
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
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	//1.������
	//2.�������
	if (*pplist == NULL)
	{
		return;
	}
	SListNode* cur = (*pplist)->next;
	free(*pplist); //����ҲҪע���ͷſռ�
	*pplist = cur;

}
// ���������
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

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->data = x;
	cur->next = NULL;
	cur->next = pos->next;//һ��Ҫ�ȰѺ����ָ����������ٸı�ָ��
	pos->next = cur;
}
// ������ɾ��posλ��֮���ֵ
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


//�����������
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
	*pplist = NULL;//�ͷ����Ҫ�ÿգ���Ȼ�����Ұָ���
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