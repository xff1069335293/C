//��ŵ������
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void move(int n, char x, char y, char z)
{
	if (1 == n)
	{
		printf("%c-->%c\n", x, z);
	}
	else
	{
		move(n - 1, x, z, y);
		printf("%c-->%c\n", x, z);
		move(n - 1, y, x, z);
	}
}

int main()
{
	char x = 'x', y = 'y', z = 'z';
	int n;

	printf("�����뺺ŵ���Ĳ�����\n");
	scanf("%d", &n);

	move(n, x, y, z);
	system("pause");
	return 0;
}
