#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num; 
	printf("������һ��������");
	scanf("%d", &num);

	while(num)
	{
		
		printf("%d\n", num%10);
		num /= 10;
	}
	system("pause");
	return 0;
}
