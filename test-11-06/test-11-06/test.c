//��һ���ַ����������Ϊ:"student a am i" 
//	���㽫��������ݸ�Ϊ"i am a student".
//�ÿ⺯��ʵ��

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
char* string_(char* string) 
{
	char* ptmp;
	char temp[1024] = { 0 };
	//���ұ��ҵ��ո�
	while (ptmp = strrchr(string, ' ')) {
		//��ַ��1��ʼƴ��
		strcat(temp, ptmp + 1);
		//ƴ�����֮����ո�
		strcat(temp, " ");
		*ptmp = '\0';
	}
	strcat(temp, string);
	strcpy(string, temp);
	return string;
}
int main()
{
	char string[] = { "student a am i" };
	puts(string_(string));
	system("pause");
	return 0;
}
