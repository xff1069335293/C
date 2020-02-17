#define _CRT_SECURE_NO_WARNINGS 1
//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//
//示例 1:
//
//输入: 121
//	输出 : true
//	示例 2 :
//
//	输入 : -121
//	输出 : false
//	解释 : 从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
//	示例 3 :
//
//	输入 : 10
//	输出 : false
//	解释 : 从右向左读, 为 01 。因此它不是一个回文数。
bool isPalindrome(int x)
{
	if (x < 0 || x >= 0x7fffffff)
	{
		return false;
	}
	int a = x, b = 0;
	while (x != 0)
	{
		b = b * 10 + x % 10;
		x = x / 10;
	}
	if (a == b)
	{
		return true;
	}
	else return false;
}
int numsplit(int* arr, int x)
{
	int count = 0;
	while (x > 9)
	{
		arr[count] = x % 10;
		count++;
		x /= 10;
	}
	arr[count] = x;
	return count;
}

bool isPalindrome(int x)
{
	int arr[10] = { 0 };
	if (x < 0)
	{
		return false;
	}
	int end = numsplit(arr, x);
	int start = 0;
	while (start <= end)
	{
		if (arr[end] != arr[start])
		{
			return false;
		}
		++start;
		--end;
	}
	return true;
}