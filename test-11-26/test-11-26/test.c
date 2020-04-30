#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
f(int x,int y)
{
	printf("%d %d",x,y);//先传到y  所以VS下 从右边向左

}



int main()
{
	int i = 1;
	f(i++, i++);
	system("pause");
	return 0;
}