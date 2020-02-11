#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//有一个字符数组的内容为:"student a am i" 
//	请你将数组的内容改为"i am a student".
//用库函数实现
//
//
//char* string_(char* string) 
//{
//	char* ptmp;
//	char temp[1024] = { 0 };
//	//从右边找到空格
//	while (ptmp = strrchr(string, ' ')) 
//	{
//		//地址加1开始拼接
//		strcat(temp, ptmp + 1);
//		//拼接完成之后给空格
//		strcat(temp, " ");
//		*ptmp = '\0';
//	}
//	strcat(temp, string);
//	strcpy(string, temp);
//	return string;
//}
//
//int main()
//{
//	char string[] = { "student a am i" };
//	puts(string_(string));
//	system("pause");
//	return 0;
//}



//
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//	student a am i
//	i ma a tneduts
//	i am a student

//void Reverse1(char* arr, int left, int right)//字符串的逆置
//{
//	while (left <= right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void Print(char* arr, int len)		//打印
//{
//	for (int i = 0; i < len; i++)
//	{
//  		printf("%c", arr[i]);
//	}
//	printf("\n");
//}
//
//int Strlen(char* arr)		//求长度
//{
//	int count = 0;
//	while (*arr++ != '\0')
//	{
//		++count;
//	}
//	return count;
//}
//

//char Reverse2(char* arr)//单词内部的逆置
//{
//	int start = 0;
//	int move = 0;
//	int end = 0;
//	while (arr[move] != '\0')
//	{
//		int flag = 0;
//		if (arr[move] == ' '&& arr[move+1] != ' ')
//		{
//			flag = 1;
//			start = move+1;
//		}
//		if (arr[move] != ' '&& arr[move + 1] == ' '|| arr[move + 1] == '\0')
//		{
//			flag = 1;
//			end= move;
//		}
//		if (start <= end && flag == 1)
//		{
//			Reverse1(arr, start, end);
//		}
//		++move;
//	}
//}
//
//Reverse_size(char* pstart, char* pend) (指针法)
//{
//	while (pstart <= pend)   //注意不可以写成（pstart++ <= pend），优先级问题导致先++ --再比大小了，和下述效果可不相同
//	{
//		char tmp = *pstart;
//		*pstart = *pend;
//		*pend = tmp;
//		++pstart;
//		--pend;
//	}
//}
//
//void Reverse3(char* arr) （指针法）
//{
//	int len = Strlen(arr);
//	Reverse_size(arr, arr + len-1);
//	char* pstart = arr;
//	char* pend = NULL;
//	while (*arr != '\0')
//	{
//		pstart = arr;
//		while (*arr != ' ' && *arr != '\0')
//		{
//			++arr;
//		}
//		pend = arr;
//		Reverse_size(pstart, pend - 1);
//		if (*arr == '\0') 
//		{
//			return ;
//		}
//		++arr;
//	}
//}
//
//int main()
//{
//	char arr[] = "student a am i";
//	int len = Strlen(arr);
//	int left = 0;
//	int right = len - 1;
//	Print(arr, len);
//	Reverse1(arr, left, right);
//	Print(arr, len);
//	Reverse2(arr);
//	Print(arr, len);
//	Reverse3(arr);
//	Reverse3(arr);
//	Print(arr, len);
//	system("pause");
//	return 0;
//}


