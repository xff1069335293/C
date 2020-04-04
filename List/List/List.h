#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

// 2����ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate();
// ˫����������
void ListDestory(ListNode* phead);
// ˫�������ӡ
void ListPrint(ListNode* phead);
// ˫������β��
void ListPushBack(ListNode* phead, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* phead);
// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* phead);
// ˫���������
ListNode* ListFind(ListNode* phead, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);