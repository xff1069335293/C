#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//��һ���ַ����������Ϊ:"student a am i" 
//	���㽫��������ݸ�Ϊ"i am a student".
//�ÿ⺯��ʵ��
//
//
//char* string_(char* string) 
//{
//	char* ptmp;
//	char temp[1024] = { 0 };
//	//���ұ��ҵ��ո�
//	while (ptmp = strrchr(string, ' ')) 
//	{
//		//��ַ��1��ʼƴ��
//		strcat(temp, ptmp + 1);
//		//ƴ�����֮����ո�
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
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//	student a am i
//	i ma a tneduts
//	i am a student

//void Reverse1(char* arr, int left, int right)//�ַ���������
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
//void Print(char* arr, int len)		//��ӡ
//{
//	for (int i = 0; i < len; i++)
//	{
//  		printf("%c", arr[i]);
//	}
//	printf("\n");
//}
//
//int Strlen(char* arr)		//�󳤶�
//{
//	int count = 0;
//	while (*arr++ != '\0')
//	{
//		++count;
//	}
//	return count;
//}
//

//char Reverse2(char* arr)//�����ڲ�������
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
//Reverse_size(char* pstart, char* pend) (ָ�뷨)
//{
//	while (pstart <= pend)   //ע�ⲻ����д�ɣ�pstart++ <= pend�������ȼ����⵼����++ --�ٱȴ�С�ˣ�������Ч���ɲ���ͬ
//	{
//		char tmp = *pstart;
//		*pstart = *pend;
//		*pend = tmp;
//		++pstart;
//		--pend;
//	}
//}
//
//void Reverse3(char* arr) ��ָ�뷨��
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


