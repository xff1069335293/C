#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void fcfs(int num);//先来先服务
void sjf(int num);//短作业优先
void RR(int num);//RR算法
void print(int num);
void display(int num);
void Arrive_sort(int num);
void Service_sort(int num);
void Priority_sort(int num);//按优先级减小排序
void Arrive_Short_sort(int num);