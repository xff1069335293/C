#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define M 10
#define N 10
#pragma once

typedef int Bdatetype;
typedef struct Node
{
	Bdatetype _request[M][N];//������Դ
	Bdatetype _available[M][N];//�ɻ�õ�
	Bdatetype _need[M][N];//��Ҫ
	Bdatetype _max[M][N];//���
	Bdatetype _allocation[M][N];	//�ѷ���
	Bdatetype _finish[M][N];//�Ƿ����
	Bdatetype _work[M][N];
	Bdatetype _count[N];//����
	Bdatetype _sum[M][N];//�����ṩ����Դ��
	size_t size;//��������
	size_t resource;//��Դ��
}Node;

void Bankerinit(Node* psl);  //��ʼ��
void Print();//
void Display(Node* psl, Bdatetype size, Bdatetype resource);
void Nodepush(Node* psl, Bdatetype size, Bdatetype resource);
void request(Node* psl, Bdatetype size, Bdatetype resource, Bdatetype input);
void safetytest(Node* psl, Bdatetype size, Bdatetype resource, Bdatetype input);