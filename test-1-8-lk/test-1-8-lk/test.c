//独一无二的出现次数
//给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
//如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
//

bool uniqueOccurrences(int* arr, int arrSize) {
	int x, i, j;
	int count[1000] = { 0 }, t = 0;
	bool a;
	for (i = 0; i < arrSize; i++)
	{
		a = false;
		if (arr[i] != -1001)x = arr[i];
		for (j = i; j < arrSize; j++)
		{
			if (x == arr[j])
			{
				count[t]++;
				arr[j] = -1001;
				a = true;
			}
		}
		if (a)t++;
	}
	for (i = 0; i < t; i++)
	{
		for (j = 0; j < t; j++)
		{
			if (count[i] == count[j] && i != j)
			{
				return false;
			}
		}
	}
	return true;

}