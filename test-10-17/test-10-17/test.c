//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//�ݹ�
// int Strlen(char* arr)
//{
//	int static count = 0;
//	if ( *((arr++))== '\0')
//		;
//	else
//	{
//		count++;
//		Strlen(arr++);
//	}
//	return count;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char arr[] = "abcdef";
//	int  ret = Strlen(arr);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//�ǵݹ�
//
//int Strlen(char* arr)
//{
//	int count = 0;
//	while (*(arr++) != '\0')
//	{
//		
//		count++;
//
//	}
//	
//	return count;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char arr[] = "abcdefgh";
//	int  ret = Strlen(arr);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�

//�ݹ�
//factorial(int n) 
//{
//	if (n == 1)
//	{
//		return n;
//}
//	else
//	{
//		return n * factorial(n - 1);
//	}
//
//}
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int ch = 0;
//	scanf("%d", &ch);
//	int ret = factorial(ch);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}

//�ǵݹ�

//int Factorial(int n)
//{
//	int sum = 1;
//	while(n)
//	{
//		sum *= n;
//		n--;
//	}
//	return sum;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int ch = 0;
//	scanf("%d", &ch);
//	int ret = Factorial(ch);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}

//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
//int Printf(int ch)
//{
//	int x = 0;
//	if (ch < 10)
//	{
//		return ch;
//	}
//	else
//	{
//		x = ch % 10;
//		printf("%d ", x);
//		Printf(ch / 10);
//		
//	}
//
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int ch = 0;
//	scanf("%d", &ch);
//	int ret = Printf(ch);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}

