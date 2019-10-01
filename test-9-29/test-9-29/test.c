//
//1.在屏幕上输出以下图案：
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
//升级版
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int line = 0;
//	printf("请输入菱形行数：");
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
//2.求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
//
//
//在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，其各个数之N次方和等于该数。
//例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
//153 = 1^3 + 5^3 + 3^3。
//370 = 3^3 + 7^3 + 0^3。
//371 = 3^3 + 7^3 + 1^3。
//407 = 4^3 + 0^3 + 7^3。
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
//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222 
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int main(){
//	int ch = 0;
//	int a = 0;
//	printf("请输入末尾含a的个数：");
//	scanf("%d", &ch);
//	printf("请输入需要计算的数：");
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
