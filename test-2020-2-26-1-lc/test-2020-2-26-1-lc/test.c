#define _CRT_SECURE_NO_WARNINGS 1
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

示例 1：

输入：“ab - cd”
输出：“dc - ba”
示例 2：

输入：“a - bC - dEf - ghIj”
输出：“j - Ih - gfE - dCba”
示例 3：

输入：“Test1ng - Leet = code - Q!”
输出：“Qedo1ct - eeLg = ntse - T!”

提示：

S.length <= 100
33 <= S[i].ASCIIcode <= 122
S 中不包含 \ or "


char * reverseOnlyLetters(char * S)
{
	int right = strlen(S) - 1;
	int left = 0;
	while (left < right)
	{
		int flag1 = 0, flag = 0;
		if (S[left] >= 'a'&&S[left] <= 'z' || S[left] >= 'A'&&S[left] <= 'Z')
		{
			flag1 = 1;
		}
		else
		{
			++left;
		}
		if (S[right] >= 'a'&&S[right] <= 'z' || S[right] >= 'A'&&S[right] <= 'Z')
		{
			flag = 1;
		}
		else
		{
			--right;
		}
		if (flag && flag1)
		{
			char tmp = S[left];
			S[left] = S[right];
			S[right] = tmp;
			++left;
			--right;
		}
	}
	return S;
}
