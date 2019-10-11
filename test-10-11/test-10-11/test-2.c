//
//1.递归和非递归分别实现求第n个斐波那契数。
//非递归
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int ch = 0;
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	printf("请输入需要输出的斐波那契项数：\n");
//	scanf("%d", &ch);
//	if (ch <= 2)
//	{
//		printf("第%d个斐波那契数是: %d\n",ch, a);
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i <ch-2; i++)
//		{
//
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		printf("第%d个斐波那契数是：%d\n", ch, c);
//	}
//	system("pause");
//	return 0;
//}

//递归

//int fibo(int i)
//{
//	int c = 1;
//	if (i == 2|| i == 1)
//	{
//		;
//	}
//	else
//	{
//	c = fibo(i - 1) + fibo(i - 2);
//	}
//	return c;
//}
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	printf("请输入需要输出的斐波那契项数：\n");
//	int ch = 0;
//	scanf("%d", &ch);
//	int ret = fibo(ch);
//	printf("第 %d 项的斐波那契数为：%d\n", ch,ret);
//	system("pause");
//	return 0;
//}

