#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//
//输入: “A man, a plan, a canal : Panama”
//	输出 : true
//	示例 2 :
//
//	输入 : “race a car”
//	输出 : false


bool isPalindrome(char * s)
{
	char * arr = (char *)malloc(sizeof(char)*(strlen(s)));
	int num = 0;
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9' || *s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')
		{
			if (*s >= 'A' && *s <= 'Z')
			{
				*s += 32;
			}
			arr[num] = *s;
			++num;
		}
		++s;
	}
	if (num == 0)
	{
		return true;
	}
	int right = num - 1;
	int left = 0;
	while (left <= right && arr[left] == arr[right])
	{
		left++;
		right--;
	}
	if (left < right)
	{
		return false;
	}
	return true;
}