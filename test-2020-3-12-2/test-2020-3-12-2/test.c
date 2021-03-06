//给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
//
//
//
//示例 1：
//
//输出：[0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1]
//输出：true
//解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
//示例 2：
//
//输入：[0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1]
//输出：false
//示例 3：
//
//输入：[3, 3, 6, 5, -2, 2, 5, 1, -9, 4]
//输出：true
//解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
//
//提示：
//
//3 <= A.length <= 50000
//- 10 ^ 4 <= A[i] <= 10 ^ 4
//

bool canThreePartsEqualSum(int* A, int ASize)
{
	int sum = 0, num = 0, count = 0;
	for (int i = 0; i < ASize; i++)
	{
		sum += A[i];
	}
	if (sum % 3 == 0)
	{
		num = sum / 3;
		sum = 0;
		for (int i = 0; i < ASize; i++)
		{
			sum += A[i];
			if (sum == num)
			{
				count++;
				sum = 0;
			}
		}
	}
	if (count >= 3)
		return true;
	return false;
}
