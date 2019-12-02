//回文字符串
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	char s[] = "basada";
	int len = strlen(s); //获取s长度
	int p = 0, r = 0;
	int count = 0; //记录回文串长度
	int k = 0; //控制循环退出
	for (int i = 0; i < len; i++) //从前往后查找
	{
		for (int j = len - 1; j > i; j--) //从后往前查找
		{
			if (s[i] == s[j] && r - p + 1 > count) //当子串首尾相等且长度大于原先的子串则进入
			{
				p = i, r = j, k = 0;
				int n = p, m = r;
				while (n <= m)
				{
					n++;
					m--;
					if (s[n] != s[m]) //当出现不等时循环结束
					{
						k = 1;
					}
					if (k)
					{
						break;
					}
				}
				if (k)                  //并且不记录长度
				{
					continue;
				}
				count = r - p + 1;
			}
		}
	}
	if (count)
	{
		for (int i = p; i <= r; i++)
		{
			printf("%c", s[i]);
		}
	}
	else
	{
		printf("0");
	}
	system("pause");
	return 0;
}
