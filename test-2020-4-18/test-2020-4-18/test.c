﻿//
//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
//
//答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。
//
//示例 1：
//
//输入：n = 2
//输出：2
//示例 2：
//
//输入：n = 7
//输出：21
int numWays(int n) {
	int nums[3] = { 1,1,2 };
	if (n <= 2)
	{
		return nums[n];
	}
	int numsWayone = 1;
	int numsWaytwo = 2;
	int numsWayN;
	for (unsigned int i = 3; i <= n; i++)
	{
		numsWayN = (numsWayone + numsWaytwo) % 1000000007;

		numsWayone = numsWaytwo;
		numsWaytwo = numsWayN;
	}
	return numsWayN;
}