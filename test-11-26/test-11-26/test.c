#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
f(int x,int y)
{
	printf("%d %d",x,y);//�ȴ���y  ����VS�� ���ұ�����

}



int main()
{
	int i = 1;
	f(i++, i++);
	system("pause");
	return 0;
}