#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#pragma once

typedef int Bdatetype;
typedef struct Node
{
	size_t _val;
	Bdatetype* _available;//�ɻ�õ�
	Bdatetype* _need;//��Ҫ
	Bdatetype* _max;//���
	Bdatetype* _allocation;	//�ѷ���
	Bdatetype* _work;//�����ṩ����Դ��
	size_t capcity;//����
	size_t size;//��������
	size_t resource;//��Դ��
}Node;
void Bankerinit(Node* psl);  //��ʼ��
void Print();//