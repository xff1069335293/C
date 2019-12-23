#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#pragma once

typedef int Bdatetype;
typedef struct Node
{
	size_t _val;
	Bdatetype* _available;//可获得的
	Bdatetype* _need;//需要
	Bdatetype* _max;//最大
	Bdatetype* _allocation;	//已分配
	Bdatetype* _work;//可以提供的资源数
	size_t capcity;//容量
	size_t size;//进程数量
	size_t resource;//资源数
}Node;
void Bankerinit(Node* psl);  //初始化
void Print();//