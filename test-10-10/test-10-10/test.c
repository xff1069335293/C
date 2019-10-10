//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//
//void mult_table(int num)
//{
//	int i = 0;
//	int j = 0;
//	int sum = 0;
//	for (i = 0; i < num; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			sum = (j + 1)*(i + 1);
//			printf("%d * %d = %d ", j + 1, i + 1, sum);
//		}
//		printf("\n");
//	}
//	return;
//}
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	printf("请输入一个数：\n");
//	int num = 0;
//	scanf("%d", &num);
//	mult_table(num);
//	system("pause");
//	return 0;
//}
//2.使用函数实现两个数的交换。

//void exchange_num(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdlib.h>
//#include<stdio.h>
//int main()
//{
//	printf("请输入两个数：\n");
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	scanf("%d", &b);
//	printf(" a= %d b= %d\n", a, b);
//	exchange_num(&a,&b);
//	printf(" a= %d b= %d\n", a, b);
//	system("pause");
//	return 0;
//}



//
//5.实现一个函数，判断一个数是不是素数。
//int prime_num(int n)
//{
//	int i = 0;
//	if (n <= 2)
//	{
//		return -1;
//	}
//	for (i = 2; i < n; i++)
//	{
//		if (n%i == 0)
//		{
//			break;
//		}
//	}
//	if (i == n)
//	{
//		return -1;
//	}
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdlib.h>
//#include<math.h>
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	printf("请输入一个数：\n");
//	scanf("%d", &n);
//	int ret = prime_num(n);
//	if (ret == -1)
//	{
//		printf("%d 是素数\n", n);
//	}
//	else
//	{
//		printf("%d 不是素数\n", n);
//	}
//	system("pause");
//	return 0;
//}


//未完成
//4
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。




//intt(int arr[], int ch)
//{
//	int n = 0;
//	int i = 0;
//	for (i = 0; i < ch; i++)
//	{
//		scanf("%d", &n);
//		if (n == 0)
//			;
//		else
//		{
//			arr[i] = n;
//			printf("%d ", arr[i]);
//		}
//	}
//}
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdlib.h>
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int ch = sizeof(arr) / sizeof(0);
//	printf("请开始初始化数组：\n");
//	intt(arr, ch);
//	printf("ha %d", ch);
//	printf("开始倒置\n");
//	int i = 0;
//	for (i = 0; i < ch / 2; i++)
//	{
//		int tmp = arr[i];
//		arr[ch - i] = tmp;
//		arr[i] = arr[ch - i];
//	}
//	printf("hehe %d", ch);
//	for (i = 0; i < ch; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}