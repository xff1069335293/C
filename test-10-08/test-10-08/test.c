#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
////
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	for (int i = 1; i <= input; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ",j ,i,i*j);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//2.使用函数实现两个数的交换。
//void NumExchange1(int a, int b)//仅仅是改变临时拷贝的a,b的值
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void NumExchange2(int* a, int *b)//用指针才能实际改变原来的数字
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//	{
//	int a = 3;
//	int b = 4;
//	printf("%d %d\n", a, b);
//	NumExchange1(a, b);
//	printf("%d %d\n", a, b);
//	NumExchange2(&a, &b);
//	printf("%d %d\n", a, b);
//	system("pause");
//	return 0;
//	}

//3.实现一个函数判断year是不是润年。
//
//int Year(int year)
//{
//	int ret = 0;
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) 
//	{
//		ret = year;
//	}
//	else
//	{
//		ret = -1;
//	}
//	return ret;	
//}

//int main()
//{
//	printf("请输入一个年份：\n");
//	int ret = 0;
//	int year = 0;
//	scanf("%d", &year);
//	printf("你输入的是: %d \n", year);
//  ret = Year(year);
//	printf("haha %d", ret);
//	if (ret == -1)
//	{
//		printf("%d 不是闰年", year);
//	}
//	else 
//	{
//		printf("%d 是闰年", year);
//	}
//system("pause");
//	return 0;
//}
//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//
//void Init(int* arr, int len)
//{
//	int input = 0;
//	for (int i = 0; i < len; i++)
//	{
//		scanf("%d", &input);
//		arr[i] = input;
//	}
//}
//void Empty(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void Reverse(int *arr, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left <= right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void Print(int* arr, int len)
//{
//	for (int  i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int len = (sizeof(arr) / sizeof(arr[0]));
//	Init(arr,len);
//	Print(arr, len);
//	Reverse(arr,len);
//	Print(arr, len);
//	Empty(arr, len);
//	Print(arr, len);
//	system("pause");
//	return 0;
//}


//5.实现一个函数，判断一个数是不是素数。
//int Judge(int input)
//{
//	if (input == 1)
//	{
//		return 1;
//	}
//	for (int i = 1; i < input / 2; i++)
//	{
//		if (input % i != 0)
//		{
//			continue;
//		}
//		else
//		{
//			return 0;
//		}
//		return 1;
//	}
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d",&input);
//	int ret = Judge(input);
//	if (ret == 0)
//	{
//		printf("%d不是素数\n",input);
//	}
//	else
//	{
//		printf("%d是素数\n", input);
//	}
//	system("pause");
//	return 0;
//}


