/*#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1;j <= i; j++) {
			printf("%d*%d=%d ", i,j,i*j);}
		
		printf("\n");
	}
	system("pause");
	return 0;
}*/
//9*9乘法表


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
 int i = 100;
 int count = 0;
 while(i <= 200)
	{
 int flag = 0;
 int j = 2;
 while(j < i)
		{
 if(i%j == 0)
			{
 flag = 1;
 break;
			}
 j++;
		}
 if(flag == 0)
		{
 count++;
 printf("%d ", i);
		}
 i++;
	}
 printf("\ncount = %d\n", count);
 system("pause");
 return 0;
}
		
//100-200素数
/*
#include <math.h>

int main()
{
 int i = 101;
 int count = 0;
 while(i<=200)
	{
 //printf("%d ", i);
 //判断i是否为素数
 //2->i-1
 int flag = 0;
 int j = 2;
 while(j<=sqrt(i))
		{
 if(i%j == 0)
			{
 flag = 1;
 break;
			}
 j++;
		}
		//..
 if(flag == 0)
		{
 count++;
 printf("%d ", i);
		}
 i+=2;
	}
 printf("\ncount = %d\n", count);
 system("pause");
 return 0;
}*/
/*#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int i = 0;
	int count = 0;
	for (i = 1000; i <= 2000; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
			printf("%d  ", i);
			count++;
		}
	}
	printf("\n"); 
	printf("count = %d\n", count);
	system("pause");
	return 0;
	}
//1000-2000闰年

/*自己独立思考要花好久，后面要加油鸭！！！
多自己敲代码，多自己敲代码，多自己敲代码！！！！
老师优化的代码，后续会整理更新到CSDN
*/