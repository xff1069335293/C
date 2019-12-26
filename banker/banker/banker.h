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
	Bdatetype _request[M][N];//请求资源
	Bdatetype _available[M][N];//可获得的
	Bdatetype _need[M][N];//需要
	Bdatetype _max[M][N];//最大
	Bdatetype _allocation[M][N];	//已分配
	Bdatetype _finish[M][N];//是否完成
	Bdatetype _work[M][N];
	Bdatetype _count[N];//计数
	Bdatetype _sum[M][N];//可以提供的资源数
	size_t size;//进程数量
	size_t resource;//资源数
}Node;

void Bankerinit(Node* psl);  //初始化
void Print();//
void Display(Node* psl, Bdatetype size, Bdatetype resource);
void Nodepush(Node* psl, Bdatetype size, Bdatetype resource);
void request(Node* psl, Bdatetype size, Bdatetype resource, Bdatetype input);
void safetytest(Node* psl, Bdatetype size, Bdatetype resource, Bdatetype input);