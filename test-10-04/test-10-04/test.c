//1.完成猜数字游戏。
//
//play_game()
//{
//	int ret = 0;
//	int guess = 0;
//	ret = rand()%100+1;
//	printf("猜数字开始,请输入0-100之间的数字：\n");
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (ret == guess) 
//		{
//			printf("恭喜你猜对了\n");
//		}
//		if (ret > guess)
//		{
//			printf("猜小了，请重新猜:\n");
//		}
//		if (ret < guess)
//		{
//			printf("猜大了，请重新猜:\n");
//		}
//	}
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main() {
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do {
//		printf("请选择功能：\n 1.进入游戏\n 0.退出游戏\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			play_game();
//			break;
//		case 0:
//			printf("游戏退出");
//			break;
//		default:
//			printf("输入错误");
//			break;
//		}
//	} while (input);
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

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int count = 3;
//	int i = 0;
//	char passward[10] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:\n");
//		//char passward[] = "123456";
//		scanf("%s", passward);
//		if (strcmp(passward, "123456") == 0)
//		{
//			printf("登录成功：\n");
//			break;
//		}
//		else
//		{
//			count--;
//			printf("登录失败，你还有%d次机会\n", count);
//		}
//	}
//		if (i == 3) 
//		{
//			printf("三次输入失败，程序自动退出\n");
//		}
//
//		system("pause");
//		return ;
//	}




//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void main() {
//	char ch;
//	printf("请输入任意字符：\n");
//	while ((ch=getchar()) != EOF) 
//	{
//		if (ch >= 'a'&& ch <= 'z')
//		{
//			ch = ch - 32;
//			printf("%c\n", ch);
//		}
//		else if (ch >= 'A'&&ch <= 'Z')
//		{
//			ch = ch + 32;
//			printf("%c\n", ch);
//		}
//		else if (ch >= '0'&&ch <= '9')
//		{
//			;
//		}
//		else
//			;
//	}
//	system("pause");
//}