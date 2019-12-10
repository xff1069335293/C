#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

LinkList Create();
void print(LinkList L);
void reverse(LinkList L);
LinkList Create()
{
	LinkList L, p, s;
	ElemType e;
	L = (LinkList)malloc(sizeof(LNode));
	p = L;
	scanf("%d", &e);
	while (e != -1)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = e;
		p->next = s;
		p = s;
		scanf("%d", &e);
	}
	p->next = NULL;
	return L;
}
void print(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void reverse(LinkList L)
{
	if (L->next == NULL) return;
	LinkList now, p;
	now = L->next;
	while (now->next)
	{
		p = now->next;
		now->next = p->next;
		p->next = L->next;
		L->next = p;//每一次都将当前的p插前面去。
	}
}
int main()
{
	LinkList L = Create();
	print(L);
	printf("\n");
	reverse(L);
	print(L);
	system("pause");
	return 0;
}