//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
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
//	printf("������һ������\n");
//	int num = 0;
//	scanf("%d", &num);
//	mult_table(num);
//	system("pause");
//	return 0;
//}
//2.ʹ�ú���ʵ���������Ľ�����

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
//	printf("��������������\n");
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
//5.ʵ��һ���������ж�һ�����ǲ���������
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
//	printf("������һ������\n");
//	scanf("%d", &n);
//	int ret = prime_num(n);
//	if (ret == -1)
//	{
//		printf("%d ������\n", n);
//	}
//	else
//	{
//		printf("%d ��������\n", n);
//	}
//	system("pause");
//	return 0;
//}


//δ���
//4
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��




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
//	printf("�뿪ʼ��ʼ�����飺\n");
//	intt(arr, ch);
//	printf("ha %d", ch);
//	printf("��ʼ����\n");
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