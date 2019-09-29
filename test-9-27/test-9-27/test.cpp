//1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 6,7,8,9,0 };
//	int tmp = 0;
//	int i = 0;
//	int ch = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < ch; i++)
//	{
//		tmp = arr2[i];
//		arr2[i] = arr1[i];
//		arr1[i] = tmp;
//		printf("%d", arr1[i]);
//	}
//	    printf("\n");
//		for (i = 0; i < ch; i++)
//		{
//			printf("%d", arr2[i]);
//		}
//		printf("\n");
//	system("pause");
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i = 0;
//		double sum= 0;
//		for (i = 1; i <= 100; i++) {
//			if (1 == i % 2) {
//				sum += 1.0 / i;
//			}
//			if (0 == i % 2) {
//				sum -= 1.0 / i;
//			}
//		}
//		printf("%lf", sum);
//system("pause");
//return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9) {
//			count++;
//		}
//		
//		if (i / 10 == 9) {
//			count++;
//		}
//	}
//	printf("%d ", count);
//		system("pause");
//		return 0;
//	}


/*#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
#define NUM 100
using namespace std;

int main() {
	double sum = 0.0;
	int i = 0;
	cout << "计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值" << endl;
	for (i = 1; i <= NUM; i++) {
		if (1 == i % 2) {
			sum += 1.0 / i;
		}
		if (0 == i % 2) {
			sum -= 1.0 / i;
		}
	}
	cout << "计算的结果是" << sum << endl;
	system("pause");
	return 0;
}*/
