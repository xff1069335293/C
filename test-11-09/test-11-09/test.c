#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Stdlib.h>
#define COL 3
#define ROW 3
//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9

//void  Search(int* arr,int num)
//{
//	int col =0;
//	int row = ROW-1;
//	while (((*arr+row)+col) != num && row >=0 && col<COL)
//	{
//		
//		if (((*arr + row)+col) > num)
//		{
//			--row;
//		}
//		if (((*arr + row)+col) < num)
//		{
//			++col;
//		}
//	}
//	if (row <0 || col >= COL)
//	{
//		printf("������\n");
//	}
//	else
//	{
//		printf("����\n");
//	}
//}
//
//int main()
//{
//	int input = 0;
//	int arr[ROW][COL] = { 0 };
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			scanf("%d",&input);
//			arr[i][j] = input;
//		}
//	}
//	int num = 0;
//	scanf("%d",&num);
//	Search(arr,num);
//	system("pause");
//	return 0;
//}