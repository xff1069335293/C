//
//1.����Ļ���������ͼ����
//* 1
//***
//*****
//*******
//*********
//***********
//*************
//***********
//*********
//*******
//*****
//***
//*
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int i ,j= 0;
//	for (i = 1; i <=13; i=i+2) {
//		for (j = 1; j <= i; j++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 11; i >= 1; i = i - 2) {
//		for (j = 1; j <= i; j++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	system("pause");
//		return 0;
//}
//
//������
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int line = 0;
//	printf("����������������");
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0; i < line; i++) {
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++) {
//			printf(" ");
//		}
//		int k = 0;
//		for (k = 0; k< 2*i+1; k++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < line - 1; i++) {
//		int j = 0;
//		for (j = 0; j <i+1 ; j++) {
//			printf(" ");
//		}
//		int k = 0;
//		for (k = 0; k <2*(line-i)-3 ; k++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	system("pause");
//		return 0;
//}
//
//2.���0��999֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������
//
//
//�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number������ָһNλ�����������֮N�η��͵��ڸ�����
//����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
//153 = 1^3 + 5^3 + 3^3��
//370 = 3^3 + 7^3 + 0^3��
//371 = 3^3 + 7^3 + 1^3��
//407 = 4^3 + 0^3 + 7^3��
//
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int main() {
//	int i = 0;
//	int a, b, c = 0;
//	
//	for (i = 100; i <= 999; i++) {
//		a = i / 100;
//		b = (i/10)%10;
//		c = i % 10;
//		double sum =0;
//		sum =pow(a, 3) + pow(b, 3) +pow(c, 3);
//		if (i == sum)
//		{
//			printf("%d\n", i);
//		}
//	}
//		system("pause");
//		return 0;}
//
//
//3.
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222 
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int main(){
//	int ch = 0;
//	int a = 0;
//	printf("������ĩβ��a�ĸ�����");
//	scanf("%d", &ch);
//	printf("��������Ҫ���������");
//	scanf("%d", &a);
//	int i = 0;
//	
//		if (ch == 1) {
//			printf(" %d", a);
//		}
//		if (ch >= 2) {
//			int sum = a;
//			int b = 0;
//			b = a;
//			for (i = 1; i <ch; i++) {
//				a = ((a * 10) + b);
//				sum = sum + a;
//			}
//			printf("%d", sum);
//	}
//	
//	system("pause");
//		return 0;
//}
