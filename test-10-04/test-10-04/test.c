//1.完成猜数字游戏。
//

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main() {
//	int ch;
//	scanf("%d", &ch);
//	
//
//	system("pause");
//	return 0;
//}
//2.写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）
//binary_search(int arr[],int ch,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (int)((left + right) / 2);
//		if (arr[mid] > ch)
//		{
//			right = mid - 1;
//		}
//	  if (arr[mid] < ch)
//		{
//			left = mid + 1;
//		}
//		if (arr[mid] == ch)
//		
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int arr[] = {1,2,3,4,5,6,7 ,8,9,10};
//	int ch = 0;
//	scanf("%d", &ch);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int mid = 0;
//	int ret = 0;
//	ret=binary_search(arr, ch, sz);
//	if (ret == -1) 
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("找到了下标是：%d", ret);
//	}
//	system("pause");
//	return 0;
//}
//

//
//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int ch=0;
	int count = 3;
	scanf("%d", &ch);
	int passward = "123456";
	while (count > 0) 
	{
		if (passward == ch)
		{
			printf("登录成功：/n");
		}
		else
		{
			count--;
			printf("登录失败，你还有%d次机会", count);
			continue;
		}
	}

	system("pause");
	return 0;
}




//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void main() {
//	char ch;
//	void	getchar(ch);
//	while (ch == EOF) {
//		if ((ch > 0) && (ch < 9))
//		{
//			;
//		}
//		if ((ch > 'a') && (ch < 'z')) {
//			putchar(ch + 32);
//		}
//		if ((ch >= 'A') && (ch = < 'Z')) {
//			putchar(ch - 32);
//		}
//	}
//
//	system("pause");
//}