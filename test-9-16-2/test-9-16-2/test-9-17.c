/*#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i, j, k;
	scanf("%d %d", &i, &j);
	printf("交换前 ：i = %d,j = %d", i, j);
	k = i;
    i = j;
	j = k;
			printf("\n交换后：i = %d,j = %d", i, j);
		
system("pause");
return 0;
}



#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i, j;
	scanf("%d %d", &i, &j);
	i = i + j;
	j = i - j;
	i = i - j;
	printf("%d %d", i, j);
	system("pause");
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1,8,9,11,4,10,12,35,65,95 };
	int max = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (max > arr[i])
		{
			continue;
		else 
		{
			max = arr[i];
		}
	}
	printf("max = %d", max);
	system("pause");
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, b, c, n;
	printf("请输入三个整数：\n");
	scanf("%d %d %d", &a, &b, &c);
	if (a > b) {}
	else { 
		n = b;
		b = a;
		a = n;
	}
	if (a > c) {}
	else {
		n = c;
		c = a;
		a = n;
	}
	if (b > c) {}
	else {
		n = c;
		c = b;
		b = n;
	}
	printf("%d %d %d", a, b, c);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, b, i, j;
	printf("请输入两个整数：\n");
	scanf("%d %d", &a, &b);
	if (a >= b) {
		
	}
	else {
		j = b;
		b = a;
		a = j;
	}

	{while (b != 0)
		{
			i = a % b;
			a = b;
			b = i;
		}
		printf("最大公约数为：%d", a);
	}

	
	system("pause");
	return 0;
}*/