//
//给定一个整数，写一个函数来判断它是否是 3 的幂次方。
//
//示例 1:
//
//输入: 27
//	输出 : true
//	示例 2 :
//
//	输入 : 0
//	输出 : false
//	示例 3 :
//
//	输入 : 9
//	输出 : true
//	示例 4 :
//
//	输入 : 45
//	输出 : false

bool isPowerOfThree(int n) 
{
	if (n == 1)
		return true;
	int i;
	if (n % 3 != 0)
		return false;
	for (i = 3; i <= n; i = i * 3)
	{
		if (n == i)
			return true;
		if (n < i)
			return false;
	}
	return false;
}